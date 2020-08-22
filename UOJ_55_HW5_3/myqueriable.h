#pragma once

#include <vector>
#include <list>

template <class T>
class myQueriable {
    std::vector<T> base;
public:
    myQueriable(const std::vector<T>& src): base(src) {};

    int size() {
        return base.size();
    }

    T& operator[](int pos) {
        return base.operator[](pos);
    }

    template <class F>
    myQueriable<T> where(F f) {
        std::vector<T> tmp;
        for (T x: base)
            if (f(x)) tmp.push_back(x);
        return myQueriable<T>(tmp);
    }

    template <class F>
    myQueriable<T> apply(F f) {
        std::vector<T> tmp;
        for (T x: base) tmp.push_back(f(x));
        return myQueriable<T>(tmp);
    }

    T sum() {
        T s = 0;
        for (T x: base) s += x;
        return s;
    }
};

template <class T>
myQueriable<T> from(const std::vector<T>& src) {
    return myQueriable<T>(src);
}

template <class T>
myQueriable<T> from(const std::list<T>& src) {
    std::vector<T> tmp;
    for (T x: src) tmp.push_back(x);
    return myQueriable<T>(tmp);
}