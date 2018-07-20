# 报告
 ![https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true](https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true)  

## 问题和背景


见 [需求分析文档](https://github.com/2018YX-game/repo/blob/master/%E9%9C%80%E6%B1%82%E5%88%86%E6%9E%90/%E9%9C%80%E6%B1%82%E5%88%86%E6%9E%90.md)  


## 开发计划和分工

第一轮迭代由张思淡负责View和Window层，吕慕凡负责Model和ViewModel层，王航宇负责APP层。  
第二轮迭代由吕慕凡负责View和Window层，王航宇负责Model和ViewModel层，张思淡负责APP层。  
第一轮迭代由王航宇负责View和Window层，张思淡负责Model和ViewModel层，吕慕凡负责APP层。  
三轮迭代完成，每个人都把MVVM框架的各个分工都做了一遍。  

## 每轮迭代效果说明

0.0版：就一个开始游戏界面，里面有开始游戏按钮和退出按钮，没有
model层和viewmodel层,app层就显示页面。  
0.1版：在common层里写了SWMatrix的公用头文件，在window层增加了游戏界面，
model层增加了swmodel类，在viewmodel层里增加了swviewmodel类  
0.2版：window层增加关卡到2关，同时window层增加了接收器。
viewmodel层相应的增加了发送器和命令。
app层把model,viewmodel,window层组装起来，把接收器挂在发送器上，同时写了一个命令，把开始界面的实现窗口跳转功能的命令指向了app层的命令，由app层实现窗口间的跳转。   
0.3版：实现了鼠标按下时移动改变矩阵的功能，在viewmodel层增加了鼠标移动的命令，在window层执行，并且增加了鼠标移动命令是否执行成功的通知。完成游戏的功能，有2个关卡可选。     
0.4版：美化了UI，增加了选关卡界面和游戏成功或失败的通知界面，有10关可选，并且实现显示的图案的形状不仅仅是长方形的。     
0.5版：美化UI，修改了游戏的逻辑判断。

### 项目目录树

## 最终运行效果图

## 小组成员
- 组长： 
  - 张思淡 ： 进行分工协调，在第一轮迭代中负责实现VIEW层

- 组员：
  - 吕慕凡： 第一轮迭代中负责实现Model层各项基本功能
  - 王航宇： 第一轮迭代中负责APP层的组装


