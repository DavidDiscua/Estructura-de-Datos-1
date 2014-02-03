//
//  SLNode.h
//  Estructuras
//
//  Created by meme lopez on 5/14/13.
//  Copyright (c) 2013 meme lopez. All rights reserved.
//

#ifndef __Estructuras__SLNode__
#define __Estructuras__SLNode__

#include <iostream>

#include "tdalist.h"
#include "object.h"

class SLinkedNode {
private:
    Object* data;
    SLinkedNode* next;
    
public:
    SLinkedNode(Object*);
    ~SLinkedNode();
    void setData(Object*);
    Object* getData() const;
    void setNext(SLinkedNode*);
    SLinkedNode* getNext() const;
    
};


#endif /* defined(__Estructuras__SLNode__) */
