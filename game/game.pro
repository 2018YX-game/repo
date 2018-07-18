#-------------------------------------------------
#
# Project created by QtCreator 2018-07-13T14:04:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SameWorld
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    APP/main.cpp \
    WINDOW/startpage.cpp \
    WINDOW/gamewindow.cpp \
    VIEWMODEL/sinks/swviewmodelsink.cpp \
    VIEWMODEL/swviewmodel.cpp \
    MODEL/swmodel.cpp \
    WINDOW/sinks/gamewindowprosink.cpp \
    VIEWMODEL/commands/layoutcommand.cpp \
    APP/app.cpp \
    APP/commands/startbuttoncommand.cpp \
    VIEWMODEL/commands/mousemovecommand.cpp \
    WINDOW/sinks/mousemovecommandsink.cpp \
    WINDOW/form.cpp \
    WINDOW/levelpage.cpp \
    WINDOW/sinks/newlayoutcommandsink.cpp \
    APP/commands/gamewindowcommand.cpp \
    WINDOW/sinks/gamecompletesink.cpp

HEADERS += \
    common/etlbase.h \
    WINDOW/startpage.h \
    WINDOW/gamewindow.h \
    VIEWMODEL/sinks/swviewmodelsink.h \
    VIEWMODEL/swviewmodel.h \
    MODEL/swmodel.h \
    common/SWMatrix.h \
    common/any.h \
    WINDOW/sinks/gamewindowprosink.h \
    VIEWMODEL/commands/layoutcommand.h \
    APP/app.h \
    APP/commands/startbuttoncommand.h \
    VIEWMODEL/commands/mousemovecommand.h \
    WINDOW/sinks/mousemovecommandsink.h \
    WINDOW/form.h \
    WINDOW/levelpage.h \
    WINDOW/sinks/newlayoutcommandsink.h \
    APP/commands/gamewndowcommand.h \
    WINDOW/sinks/gamecompletesink.h

FORMS += \
    WINDOW/startpage.ui \
    WINDOW/gamewindow.ui \
    WINDOW/form.ui \
    WINDOW/levelpage.ui

CONFIG += c++17
