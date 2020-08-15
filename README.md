# OOP Homework

## Introduction

主要上传2020年THU开设的OOP课程所布置的作业答案代码以及UOJ上另外一些题目的答案代码。

## Updates

### 2020.07.27

更新了目前已经有的答案代码。

### 2020.08.11

简单做了几道题，结果发现自己C++的语法已经忘得差不多了，有些奇怪的bug还是整不动；

- #27交上去就是Dangerous syscalls

- 计算图那条到现在还只有10分

感觉再这样下去OOP要挂科了啊。

### 2020.08.16

据说8.23考OOP，瞬间有点慌张，就先做了几道题练练手；还好收效比之前要好得多；

不过倒是有点懵，感觉C++的内存管理和多态实在是太细节了，好多时候都写得一愣一愣，AC了都弄不明白；

比如说这样的一个东西吧：

```cpp
class Base {
public:
    virtual std::string get() {return "Base";}
    virtual ~Base() {
        if (get() == "Base") std::cout << "Alert" << std::endl;
    }
};

class Derive: public Base {
public:
    virtual std::string get() {return "Derive";}
    virtual ~Derive() {}
};

int main() {
    Base* d = new Derive;
    delete b;
    return 0;
}
```

这个程序运行下来，`delete`这个指向派生类的指针的时候，是会输出`Alert`的，也就是说`get()`方法返回的是`Base`；

自己有想过是不是因为虚表被删掉出了什么问题之类的，不过暂时不想想了。
