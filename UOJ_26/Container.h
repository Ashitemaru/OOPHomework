#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
};

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
    vector< Point<A> > base;
    int findTimes;
    
public:
    Container(): findTimes(0) {};

    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
    }

    A* find(Pos p) {
        if (!findTimes) std::sort(base.begin(), base.end(), [](const Point<A>& a, const Point<A>& b) {
            return a.pos < b.pos;
        });
        findTimes++;

        int l = 0;
        int r = base.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (p < base[m].pos) r = m;
            else if (p > base[m].pos) l = m + 1;
            else return &(base[m].value);
        }
        return NULL;
    }
};

template <class A>
class Container<A, map<Pos, A> >: public BasicContainer<A> {
    map<Pos, A> base;
public:
    void insert(const Pos& p, const A& v) {
        base[p] = v;
    }

    A* find(Pos p) {
        if (base.find(p) == base.end()) return NULL;
        return &base[p];
    }
};

#endif
