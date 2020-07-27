# 万能播放器代码架构以及设计思路



### 代码基本架构

`Player`类：存储播放列表，有多个暴露给主函数的接口用于控制播放行为；

其中`play(),pause(),doubleSpeed()`方法通过适配器调用`Audio,Video`类的派生类之中的实现；

`add()`方法为此类特有，用于向播放列表中添加视频/音频；

`Adapter`类：适配器的抽象基类，设定有`play(),pause(),doublespeed()`三个接口以及虚析构函数；

`AudioAdapter/VideoAdapter`类：继承自`Adapter`类，具体实现抽象基类之中的接口；用于将`Audio,Video`类的派生类之中的接口实现转化为符合`Player`类调用的形式；



### 设计思路

课堂上通过“用`std::vector`实现栈”的例子讲解了适配器模式，其本质上是将不符合调用语句的接口通过`Adapter`类转换为我们可以调用的接口；



注意到在`main.cpp`之中，我们调用了`Player`类的`play(),pause(),doubleSpeed()`这三个接口，而这三个接口在`Audio,Video`类及其派生类之中有所实现，只是名称不同；所以我们可以设定`AudioAdapter,VideoAdapter`两个派生类，分别负责包装`Audio,Video`类的接口；之后通过虚函数的机制实现多态；













