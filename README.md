# repo
 ![https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true](https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true)  
 
## 版本说明
0.0版：就一个开始游戏界面，里面有开始游戏按钮和退出按钮，没有
model层和viewmodel层,app层就显示页面。  
0.1版：在common层里写了SWMatrix的公用头文件，在window层增加了游戏界面，
model层增加了swmodel类，在viewmodel层里增加了swviewmodel类  
0.2版：window层增加关卡到2关，同时window层增加了2个接收器，一个是更新矩阵的属性改变通知，一个是。
viewmodel层相应的增加了发送器。
app层把model,viewmodel,window层组装起来，把接收器挂在发送器上，同时写了一个命令，把开始界面的实现窗口跳转功能的命令指向了app层的命令，由app层实现窗口间的跳转。
0.3版：完成游戏界面，有2个关卡可选   
0.4版：增加选关卡界面和游戏成功或失败的通知界面，有10关可选   
0.5版：美化UI和.....