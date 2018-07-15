// any standard header
// Copyright (c) Microsoft Corporation. All rights reserved.
#pragma once
#ifndef _ANY_
#define _ANY_
#ifndef RC_INVOKED
#include <initializer_list>
#include <typeinfo>
#include <type_traits>
#include <utility>
#include <xmemory0>




#if !_HAS_STATIC_RTTI
 #error class any requires static RTTI.
#endif /* _HAS_STATIC_RTTI */

 #pragma pack(push,_CRT_PACKING)
 #pragma warning(push,_STL_WARNING_LEVEL)
 #pragma warning(disable: _STL_DISABLED_WARNINGS)
 #pragma push_macro("new")
 #undef new


namespace _new_any_space_{

using namespace std;

template <class T> struct in_place_type_t {
        explicit in_place_type_t() = default;
    };
        // CLASS bad_any_cast
class bad_any_cast
    : public bad_cast
    {	// thrown by failed any_cast
public:
    virtual const char * __CLR_OR_THIS_CALL what() const _NOEXCEPT override
        {
        return ("Bad any_cast");
        }
    };

constexpr size_t _Any_trivial_space_size = (_Small_object_num_ptrs - 1) * sizeof(void *);

template<class _Ty>
    using _Any_is_trivial = bool_constant<
        alignof(_Ty) <= alignof(max_align_t)
        && is_trivially_copyable_v<_Ty>
        && sizeof(_Ty) <= _Any_trivial_space_size>;

constexpr size_t _Any_small_space_size = (_Small_object_num_ptrs - 2) * sizeof(void *);

template<class _Ty>
    using _Any_is_small = bool_constant<
        alignof(_Ty) <= alignof(max_align_t)
        && is_nothrow_move_constructible_v<_Ty>
        && sizeof(_Ty) <= _Any_small_space_size>;

enum class _Any_representation : uintptr_t { _Trivial, _Big, _Small };

struct _Any_big_RTTI
    {	// Hand-rolled vtable for types that must be heap allocated in an any
    using _Destroy_fn = void __CLRCALL_PURE_OR_CDECL (void *) /* noexcept */;
    using _Copy_fn = void * __CLRCALL_PURE_OR_CDECL (const void *);

    template<class _Ty>
        static void __CLRCALL_PURE_OR_CDECL _Destroy_impl(void * const _Target) _NOEXCEPT
        {	// Implements destruction for _Ty
        ::delete static_cast<_Ty *>(_Target);
        }

    template<class _Ty>
        static void * __CLRCALL_PURE_OR_CDECL _Copy_impl(const void * const _Source)
        {	// Implements copy for _Ty
        return (::new _Ty(*static_cast<const _Ty *>(_Source)));
        }

    _Destroy_fn * _Destroy;
    _Copy_fn * _Copy;
    };

struct _Any_small_RTTI
    {	// Hand-rolled vtable for nontrivial types that can be stored internally in an any
    using _Destroy_fn = void __CLRCALL_PURE_OR_CDECL (void *) /* noexcept */;
    using _Copy_fn = void __CLRCALL_PURE_OR_CDECL (void *, const void *);
    using _Move_fn = void __CLRCALL_PURE_OR_CDECL (void *, void *) /* noexcept */;

    template<class _Ty>
        static void __CLRCALL_PURE_OR_CDECL _Destroy_impl(void * const _Target) _NOEXCEPT
        {	// Implements destruction for _Ty
        _Destroy_in_place(*static_cast<_Ty *>(_Target));
        }

    template<class _Ty>
        static void __CLRCALL_PURE_OR_CDECL _Copy_impl(void * const _Target, const void * const _Source)
        {	// Implements copy for _Ty
        _Construct_in_place(*static_cast<_Ty *>(_Target), *static_cast<const _Ty *>(_Source));
        }

    template<class _Ty>
        static void __CLRCALL_PURE_OR_CDECL _Move_impl(void * const _Target, void * const _Source) _NOEXCEPT
        {	// Implements move for _Ty
        _Construct_in_place(*static_cast<_Ty *>(_Target),   move(*static_cast<_Ty *>(_Source)));
        }

    _Destroy_fn * _Destroy;
    _Copy_fn * _Copy;
    _Move_fn * _Move;
    };

template<class _Ty>
    _INLINE_VAR constexpr _Any_big_RTTI _Any_big_RTTI_obj =
        {&_Any_big_RTTI::_Destroy_impl<_Ty>, &_Any_big_RTTI::_Copy_impl<_Ty>};

template<class _Ty>
    _INLINE_VAR constexpr _Any_small_RTTI _Any_small_RTTI_obj =
        {&_Any_small_RTTI::_Destroy_impl<_Ty>, &_Any_small_RTTI::_Copy_impl<_Ty>, &_Any_small_RTTI::_Move_impl<_Ty>};

        // CLASS any
class any
    {	// storage for any (CopyConstructible) type
public:
    // Construction and destruction [any.cons]
    constexpr any() _NOEXCEPT
        : _Storage{}
        {	// initialize to the empty state
        }

    any(const any& _That)
        {	// copy _That's value
        _TypeData() = _That._TypeData();
        switch (_Rep())
            {
            case _Any_representation::_Small:
                _SmallRTTI() = _That._SmallRTTI();
                _SmallRTTI()->_Copy(_SmallData(), _That._SmallData());
                break;
            case _Any_representation::_Big:
                _BigRTTI() = _That._BigRTTI();
                _BigPointer() = _BigRTTI()->_Copy(_That._BigPointer());
                break;
            case _Any_representation::_Trivial:
            default:
                _Storage._TrivialData = _That._Storage._TrivialData;
                break;
            }
        }

    any(any&& _That) _NOEXCEPT
        {	// steal _That's value
        _Move_from(_That);
        }

    template<class _ValueType,
        enable_if_t<conjunction_v<
            negation<is_same<decay_t<_ValueType>, any>>,
            negation<_Is_specialization<decay_t<_ValueType>, in_place_type_t>>,
            is_copy_constructible<decay_t<_ValueType>>
        >, int> = 0>
        any(_ValueType&& _Value)
        {	// initialize with _Value
        _Emplace<decay_t<_ValueType>>(  forward<_ValueType>(_Value));
        }

    template<class _ValueType,
        class... _Types,
        enable_if_t<is_constructible_v<decay_t<_ValueType>, _Types...>
            && is_copy_constructible_v<decay_t<_ValueType>>, int> = 0>
        explicit any(in_place_type_t<_ValueType>, _Types&&... _Args)
        {	// in-place initialize a value of type decay_t<_ValueType> with _Args...
        _Emplace<decay_t<_ValueType>>(  forward<_Types>(_Args)...);
        }

    template<class _ValueType,
        class _Elem,
        class... _Types,
        enable_if_t<is_constructible_v<decay_t<_ValueType>, initializer_list<_Elem>&, _Types...>
            && is_copy_constructible_v<decay_t<_ValueType>>, int> = 0>
        explicit any(in_place_type_t<_ValueType>, initializer_list<_Elem> _Ilist, _Types&&... _Args)
        {	// in-place initialize a value of type decay_t<_ValueType> with _Ilist and _Args...
        _Emplace<decay_t<_ValueType>>(_Ilist,   forward<_Types>(_Args)...);
        }

    ~any() _NOEXCEPT
        {	// destroy the contained value, if any (pun intended)
        reset();
        }

    // Assignment [any.assign]
    any& operator=(const any& _That)
        {	// copy _That's value to *this, if any
        *this = any{_That};
        return (*this);
        }

    any& operator=(any&& _That) _NOEXCEPT
        {	// move _That's value to *this, if any
        reset();
        _Move_from(_That);
        return (*this);
        }

    template<class _ValueType,
        enable_if_t<conjunction_v<
            negation<is_same<decay_t<_ValueType>, any>>,
            is_copy_constructible<decay_t<_ValueType>>
        >, int> = 0>
        any& operator=(_ValueType&& _Value)
        {	// replace contained value with an object of type decay_t<_ValueType> initialized from _Value
        *this = any{  forward<_ValueType>(_Value)};
        return (*this);
        }

    // Modifiers [any.modifiers]
    template<class _ValueType,
        class... _Types,
        enable_if_t<is_constructible_v<decay_t<_ValueType>, _Types...>
            && is_copy_constructible_v<decay_t<_ValueType>>, int> = 0>
        decay_t<_ValueType>& emplace(_Types&&... _Args)
        {	// replace contained value with an object of type decay_t<_ValueType> initialized from _Args...
        reset();
        return (_Emplace<decay_t<_ValueType>>(  forward<_Types>(_Args)...));
        }
    template<class _ValueType,
        class _Elem,
        class... _Types,
        enable_if_t<is_constructible_v<decay_t<_ValueType>, initializer_list<_Elem>&, _Types...>
            && is_copy_constructible_v<decay_t<_ValueType>>, int> = 0>
        decay_t<_ValueType>& emplace(initializer_list<_Elem> _Ilist, _Types&&... _Args)
        {	// replace contained value with an object of type decay_t<_ValueType> initialized from _Ilist and _Args...
        reset();
        return (_Emplace<decay_t<_ValueType>>(_Ilist,   forward<_Types>(_Args)...));
        }

    void reset() _NOEXCEPT
        {	// transition to the empty state
        switch (_Rep())
            {
            case _Any_representation::_Small:
                _SmallRTTI()->_Destroy(_SmallData());
                break;
            case _Any_representation::_Big:
                _BigRTTI()->_Destroy(_BigPointer());
                break;
            case _Any_representation::_Trivial:
            default:
                break;
            }
        _TypeData() = 0;
        }

    void swap(any& _That) _NOEXCEPT
        {	// exchange the values of *this and _That
        _That =   exchange(*this,   move(_That));
        }

    // Observers [any.observers]
    bool has_value() const _NOEXCEPT
        {	// return true iff *this contains a value
        return (_TypeData() != 0);
        }

    const type_info& type() const _NOEXCEPT
        {	// if *this contains a value of type T, return typeid(T); otherwise typeid(void)
        const type_info * const _Info = _TypeInfo();
        if (_Info)
            {
            return (*_Info);
            }

        return (typeid(void));
        }

    template<class _Decayed>
        const _Decayed * _Cast() const _NOEXCEPT
        {	// if *this contains a value of type _Decayed, return a pointer to it
        const type_info * const _Info = _TypeInfo();
        if (_Info && *_Info == typeid(_Decayed))
            {
            return (_Cast1<_Decayed>(_Any_is_small<_Decayed>{}, _Any_is_trivial<_Decayed>{}));
            }

        return (nullptr);
        }

    template<class _Decayed>
        _Decayed * _Cast() _NOEXCEPT
        {	// if *this contains a value of type _Decayed, return a pointer to it
        return (const_cast<_Decayed *>(const_cast<const any *>(this)->_Cast<_Decayed>()));
        }

private:
    static constexpr uintptr_t _Rep_mask = 3;

    _Any_representation _Rep() const
        {	// extract the representation format from _TypeData
        return (static_cast<_Any_representation>(_TypeData() & _Rep_mask));
        }
    const type_info * _TypeInfo() const
        {	// extract the type_info from _TypeData
        return (reinterpret_cast<const type_info *>(_TypeData() & ~_Rep_mask));
        }

    void _Move_from(any& _That)
        {
        _TypeData() = _That._TypeData();
        switch (_Rep())
            {
            case _Any_representation::_Small:
                _SmallRTTI() = _That._SmallRTTI();
                _SmallRTTI()->_Move(_SmallData(), _That._SmallData());
                break;
            case _Any_representation::_Big:
                _BigRTTI() = _That._BigRTTI();
                _BigPointer() = _That._BigPointer();
                _That._TypeData() = 0;
                break;
            case _Any_representation::_Trivial:
            default:
                _Storage._TrivialData = _That._Storage._TrivialData;
                break;
            }
        }

    template<class _Decayed,
        class... _Types>
        _Decayed& _Emplace(_Types&&... _Args)
        {
        static_assert(alignof(_Decayed) <= alignof(max_align_t),
            "Sorry: std::any doesn't support over-aligned types at this time.");
        return (_Emplace1<_Decayed>(_Any_is_small<_Decayed>{}, _Any_is_trivial<_Decayed>{},
              forward<_Types>(_Args)...));
        }

    template<class _Decayed,
        class... _Types>
        _Decayed& _Emplace1(false_type, false_type, _Types&&... _Args)
        {	// emplace construct _Decayed using the _Big representation
        _Decayed * const _Ptr = ::new _Decayed(  forward<_Types>(_Args)...);
        _BigPointer() = _Ptr;
        _BigRTTI() = &_Any_big_RTTI_obj<_Decayed>;
        _TypeData() = reinterpret_cast<uintptr_t>(&typeid(_Decayed))
            | static_cast<uintptr_t>(_Any_representation::_Big);
        return (*_Ptr);
        }

    template<class _Decayed,
        class... _Types>
        _Decayed& _Emplace1(true_type, false_type, _Types&&... _Args)
        {	// emplace construct _Decayed using the _Small representation
        auto& _Obj = reinterpret_cast<_Decayed&>(_Storage._SmallStorage._Data);
        _Construct_in_place(_Obj,   forward<_Types>(_Args)...);
        _SmallRTTI() = &_Any_small_RTTI_obj<_Decayed>;
        _TypeData() = reinterpret_cast<uintptr_t>(&typeid(_Decayed))
            | static_cast<uintptr_t>(_Any_representation::_Small);
        return (_Obj);
        }

    template<class _Decayed,
        class... _Types>
        _Decayed& _Emplace1(_Any_tag, true_type, _Types&&... _Args)
        {	// emplace construct _Decayed using the _Trivial representation
        auto& _Obj = reinterpret_cast<_Decayed&>(_Storage._TrivialData);
        _Construct_in_place(_Obj,   forward<_Types>(_Args)...);
        _TypeData() = reinterpret_cast<uintptr_t>(&typeid(_Decayed))
            | static_cast<uintptr_t>(_Any_representation::_Trivial);
        return (_Obj);
        }

    template<class _Decayed>
        const _Decayed * _Cast1(false_type, false_type) const _NOEXCEPT
        {	// get a pointer to the contained _Big value of type _Decayed
        return (static_cast<const _Decayed *>(_BigPointer()));
        }

    template<class _Decayed>
        const _Decayed * _Cast1(true_type, false_type) const _NOEXCEPT
        {	// get a pointer to the contained _Small value of type _Decayed
        return (static_cast<const _Decayed *>(_SmallData()));
        }

    template<class _Decayed>
        const _Decayed * _Cast1(_Any_tag, true_type) const _NOEXCEPT
        {	// get a pointer to the contained _Trivial value of type _Decayed
        return (reinterpret_cast<const _Decayed *>(&_Storage._TrivialData));
        }

    uintptr_t& _TypeData() &
        {
        return (_Storage._TypeData);
        }
    const uintptr_t& _TypeData() const &
        {
        return (_Storage._TypeData);
        }

    void *& _BigPointer() &
        {
        return (_Storage._BigStorage._Ptr);
        }
    void * const& _BigPointer() const &
        {
        return (_Storage._BigStorage._Ptr);
        }

    const _Any_big_RTTI *& _BigRTTI() &
        {
        return (_Storage._BigStorage._RTTI);
        }
    const _Any_big_RTTI * const& _BigRTTI() const &
        {
        return (_Storage._BigStorage._RTTI);
        }

    void * _SmallData() &
        {
        return (&_Storage._SmallStorage._Data);
        }
    const void * _SmallData() const &
        {
        return (&_Storage._SmallStorage._Data);
        }

    const _Any_small_RTTI *& _SmallRTTI() &
        {
        return (_Storage._SmallStorage._RTTI);
        }
    const _Any_small_RTTI * const& _SmallRTTI() const &
        {
        return (_Storage._SmallStorage._RTTI);
        }

    struct _Small_storage_t
        {
        aligned_union_t<_Any_small_space_size, void *> _Data;
        const _Any_small_RTTI * _RTTI;
        };

    struct _Big_storage_t
        {
        char _Padding[_Any_small_space_size - sizeof(void *)]; // "push down" the active members near to _TypeData
        void * _Ptr;
        const _Any_big_RTTI * _RTTI;
        };

    struct _Storage_t
        {
        union
            {
            aligned_union_t<_Any_trivial_space_size, void *> _TrivialData;
            _Small_storage_t _SmallStorage;
            _Big_storage_t _BigStorage;
            };
        uintptr_t _TypeData;
        };

    union
        {
        _Storage_t _Storage;
        max_align_t _Dummy;
        };
    };

// Non-member functions [any.nonmembers]
inline void swap(any& _Left, any& _Right) _NOEXCEPT
    {	// exchange the values of _Left and _Right
    _Left.swap(_Right);
    }

template<class _ValueType,
    class... _Types> inline
    any make_any(_Types&&... _Args)
    {	// construct an any containing a _ValueType initialized with _Args...
    return (any{in_place_type<_ValueType>,   forward<_Types>(_Args)...});
    }
template<class _ValueType,
    class _Elem,
    class... _Types> inline
    any make_any(initializer_list<_Elem> _Ilist, _Types&&... _Args)
    {	// construct an any containing a _ValueType initialized with _Ilist and _Args...
    return (any{in_place_type<_ValueType>, _Ilist,   forward<_Types>(_Args)...});
    }

template<class _ValueType> inline
    const _ValueType * _Any_cast1(const any *, true_type) _NOEXCEPT
    {	// retrieve a pointer to a function/array type
    return (nullptr);
    }
template<class _ValueType> inline
    _ValueType * _Any_cast1(any *, true_type) _NOEXCEPT
    {	// retrieve a pointer to a function/array type
    return (nullptr);
    }
template<class _ValueType> inline
    const _ValueType * _Any_cast1(const any * const _Any, false_type) _NOEXCEPT
    {	// retrieve a pointer to the _ValueType contained in _Any, or null
    return (_Any->_Cast<decay_t<_ValueType>>());
    }
template<class _ValueType> inline
    _ValueType * _Any_cast1(any * const _Any, false_type) _NOEXCEPT
    {	// retrieve a pointer to the _ValueType contained in _Any, or null
    return (_Any->_Cast<decay_t<_ValueType>>());
    }

template<class _Ty>
    using _Any_is_function_or_array = bool_constant<is_function_v<_Ty> || is_array_v<_Ty>>;

template<class _ValueType> inline
    const _ValueType * any_cast(const any * const _Any) _NOEXCEPT
    {	// retrieve a pointer to the _ValueType contained in _Any, or null
    static_assert(!is_void_v<_ValueType>, "std::any cannot contain void.");
    if (_Any)
        {
        return (_Any_cast1<_ValueType>(_Any, _Any_is_function_or_array<_ValueType>{}));
        }

    return (nullptr);
    }
template<class _ValueType> inline
    _ValueType * any_cast(any * const _Any) _NOEXCEPT
    {	// retrieve a pointer to the _ValueType contained in _Any, or null
    static_assert(!is_void_v<_ValueType>, "std::any cannot contain void.");
    if (_Any)
        {
        return (_Any_cast1<_ValueType>(_Any, _Any_is_function_or_array<_ValueType>{}));
        }

    return (nullptr);
    }

template<class _Ty> inline
    _Ty any_cast(const any& _Any)
    {	// retrieve _Any's contained value as _Ty
    static_assert(is_constructible_v<_Ty, const remove_cv_t<remove_reference_t<_Ty>>&>,
        "any_cast<T>(const any&) requires T to be constructible from const remove_cv_t<remove_reference_t<T>>&");
    const auto _Ptr =   any_cast<remove_cv_t<remove_reference_t<_Ty>>>(&_Any);
    if (!_Ptr)
        {
        _THROW(bad_any_cast{});
        }

    return (static_cast<_Ty>(*_Ptr));
    }
template<class _Ty> inline
    _Ty any_cast(any& _Any)
    {	// retrieve _Any's contained value as _Ty
    static_assert(is_constructible_v<_Ty, remove_cv_t<remove_reference_t<_Ty>>&>,
        "any_cast<T>(any&) requires T to be constructible from remove_cv_t<remove_reference_t<T>>&");
    const auto _Ptr =   any_cast<remove_cv_t<remove_reference_t<_Ty>>>(&_Any);
    if (!_Ptr)
        {
        _THROW(bad_any_cast{});
        }

    return (static_cast<_Ty>(*_Ptr));
    }
template<class _Ty> inline
    _Ty any_cast(any&& _Any)
    {	// retrieve _Any's contained value as _Ty
    static_assert(is_constructible_v<_Ty, remove_cv_t<remove_reference_t<_Ty>>>,
        "any_cast<T>(any&&) requires T to be constructible from remove_cv_t<remove_reference_t<T>>");
    const auto _Ptr =   any_cast<remove_cv_t<remove_reference_t<_Ty>>>(&_Any);
    if (!_Ptr)
        {
        _THROW(bad_any_cast{});
        }

    return (static_cast<_Ty>(  move(*_Ptr)));
    }

}

 #pragma pop_macro("new")
 #pragma warning(pop)
 #pragma pack(pop)

#endif /* RC_INVOKED */
#endif /* _ANY_ */
