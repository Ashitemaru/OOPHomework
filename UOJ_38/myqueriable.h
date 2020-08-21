#pragma once

#include <iostream>
#include <vector>

template <class T>
class myQueriable {
    std::vector<T> base;
public:
    myQueriable(std::vector<T> src) {
        base = src;
    }

    typename std::vector<T>::iterator begin() {
        return base.begin();
    }

    typename std::vector<T>::iterator end() {
        return base.end();
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
auto from(const std::vector<T>& src) {
    return myQueriable<T>(src);
}

template <class T, int len>
auto from(const T (&src)[len]) {
    std::vector<T> tmp;
    for (int i = 0; i < len; ++i) tmp.push_back(src[i]);
    return myQueriable<T>(tmp);
}
