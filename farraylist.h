
//  farraylist.h



#pragma once

#include "tdalist.h"

class FArrayList : public TDAList {
    
protected:
    int capacity;
    Object** data;
    
public:
    
    FArrayList(int);
    virtual ~FArrayList();
    virtual void clear();
    virtual bool insert(Object*, int);
    virtual Object* first() const;
    virtual Object* get(unsigned int) const;
    virtual Object* last() const;
    virtual int getCapacity() const;
    virtual Object* remove(unsigned int);
    virtual bool isFull() const;
    virtual int indexOf(Object*) const;
    virtual int size() const;
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual string toString()const;
    
};


