//
//  SLList.h
//  Estructuras
//
//  Created by meme lopez on 5/14/13.
//  Copyright (c) 2013 meme lopez. All rights reserved.
//

#ifndef __Estructuras__SLList__
#define __Estructuras__SLList__

#include <iostream>

#include "slinkednode.h"
#include "tdalist.h"
#include "object.h"

class SLinkedList : public TDAList {
    SLinkedNode* head;
    
public:
    SLinkedList();
    virtual ~SLinkedList();
    virtual bool insert(Object*, int);
    virtual Object* remove (unsigned int);
    virtual Object* first() const;
    virtual Object* last() const;
    virtual int capacity() const; // porque??
    virtual bool isFull() const;
    virtual void clear();
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual int indexOf(Object*) const;
    virtual Object* get(unsigned int) const;
    virtual string toString() const;
};

#endif /* defined(__Estructuras__SLList__) */
