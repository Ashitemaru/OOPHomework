#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <string>
#include <vector>
#include <set>

class BasicIntContainer: public BasicContainer{
public:
    virtual void insert(const int &x) = 0;
    virtual int find(int k) = 0;
};

class BasicStringContainer: public BasicContainer{
public:
    virtual void insert(const std::string &x) = 0;
    virtual std::string find(int k) = 0;
};

class IntVectorContainer: public BasicIntContainer{
    std::vector<int> base;
    int find_times=0;
public:
    virtual void insert(const int &x){base.push_back(x);}
    virtual int find(int k){
        if(find_times==0) std::sort(base.begin(),base.end());
        ++find_times; 
        return base[k-1];
    }
};

class StringVectorContainer: public BasicStringContainer{
    std::vector<std::string> base;
    int find_times=0;
public:
    virtual void insert(const std::string &x){base.push_back(x);}
    virtual std::string find(int k){
        if(find_times==0) std::sort(base.begin(),base.end());
        ++find_times; 
        return base[k-1];
    }
};

class IntMultisetContainer: public BasicIntContainer{
    std::multiset<int> base;
public:
    virtual void insert(const int &x){
        base.insert(x);
        return;
    }
    virtual int find(int k){
        auto iter=base.begin();
        for(int i=1;i<k;i++) ++iter;
        return *iter;
    }
};

class StringMultisetContainer: public BasicStringContainer{
    std::multiset<std::string> base;
public:
    virtual void insert(const std::string &x){
        base.insert(x);
        return;
    }
    virtual std::string find(int k){
        auto iter=base.begin();
        for(int i=1;i<k;i++) ++iter;
        return *iter;
    }
};

#endif