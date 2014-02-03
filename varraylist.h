
//  varraylist.h


#pragma once

#include <iostream>
#include "tdalist.h"

class VArrayList : public TDAList {
private:
    int capacity;
    Object** data;
    bool agrandar();
    
    
public:
    VArrayList();
    VArrayList(int,int);
    virtual ~VArrayList();

    virtual bool insert(Object*, int);
    virtual Object* remove (unsigned int);
    virtual int indexOf(Object*) const;
    virtual Object* first() const;
    virtual bool isFull() const;
    virtual Object* last() const;
    virtual void clear();
    virtual int getCapacity() const;
    virtual Object* get(unsigned int) const;
    virtual int size() const;
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual string toString()const;
    
};


