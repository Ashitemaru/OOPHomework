#pragma once
#include <vector>
#include <list>

template <class T>
class MyQueriable{
    std::vector<T> base;
public:
    MyQueriable(std::vector<T> src):base(src){};
    
    template <class F>
    MyQueriable where(F f){
        std::vector<T> filter;
        for(int i=0;i<base.size();i++)
            if(f(base[i])) filter.push_back(base[i]);
        return MyQueriable<T>(filter);
    }

    template <class F>
    MyQueriable apply(F f){
        std::vector<T> _map;
        for(int i=0;i<base.size();i++) _map.push_back(f(base[i]));
        return MyQueriable<T>(_map);
    }

    T sum(){
        T result=0;
        for(int i=0;i<base.size();i++) result+=base[i];
        return result;
    }

    T operator[](int loc){return base[loc];}

    int size(){return base.size();}
};

template <class T>
MyQueriable<T> from(std::vector<T> src){return MyQueriable<T>(src);}

template <class T>
MyQueriable<T> from(std::list<T> src){
    std::vector<T> tmp;
    for(auto x:src) tmp.push_back(x);
    return MyQueriable<T>(tmp);
}