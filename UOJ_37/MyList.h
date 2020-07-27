#pragma once
#include <list>
#include <iostream>

class MyList {
public:
    static std::list<int> Container;
    std::list<int>::iterator left;
    std::list<int>::iterator right;

    std::list<int>::iterator forward(int k) {
        std::list<int>::iterator flag = left;
        if(k != 0)
            for(int i = 0; i < k; ++i) ++flag;
        return flag;
    }

public:
    MyList() {
        left = ++MyList::Container.begin();
        right = ++MyList::Container.end();
    }

    MyList(
        std::list<int>::iterator _left,
        std::list<int>::iterator _right
    ):
        left(_left), right(_right) {};

    MyList(const MyList& src) {
        left = src.left;
        right = src.right;
    }

    void append(int x) {
        MyList::Container.insert(right, x);
        if(left == right) ++right;
        return;
    }

    int& operator[](int location) {
        return *forward(location);
    }

    MyList operator()(int leftLocation, int rightLocation) {
        return MyList(forward(leftLocation), forward(rightLocation));
    }

    friend std::ostream& operator<<(std::ostream& out, const MyList& src) {
        out << "[";
        if(src.left != src.right) {
            std::list<int>::iterator flag = src.left;
            out << *flag;
            ++flag;
            for(; flag != src.right; ++flag) {
                out << "," << *flag;
            }
        }
        out << "]";
        return out;
    }
};

std::list<int> MyList::Container;
