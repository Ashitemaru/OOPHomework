#ifndef BASICCONTAINER_H
#define BASICCONTAINER_H
#include <utility>

typedef std::pair<int, int> Pos;

template<class A>
class BasicContainer {
public:
    virtual ~BasicContainer(){}
    virtual void insert(const Pos &p, const A &v) = 0;
    virtual A* find(Pos k) = 0;
};

#endif
