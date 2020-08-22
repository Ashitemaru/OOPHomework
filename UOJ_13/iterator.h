#pragma once

#include <vector>

class baseContainer;

class baseIterator {
protected:
    int index;
    baseContainer* pt;
public:
    virtual void operator++() = 0;
    virtual bool operator!=(baseIterator&) = 0;

    baseContainer* getPt() {
        return pt;
    }

    int getIndex() {
        return index;
    }
};

class baseContainer {
public:
    virtual void sort() = 0;
};

// VECTOR

class vectorContainer;

class vectorIterator: public baseIterator {
public:
    virtual void operator++() {
        index++;
    }

    virtual bool operator!=(baseIterator& src) {
        return pt != src.getPt() || index != src.getIndex();
    }
};

class vectorContainer: public baseContainer {
    std::vector<int> base;
public:
    virtual void sort() override {

    }
};