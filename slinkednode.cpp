//
//  slinkednode.cpp
//  Estructuras
//
//  Created by meme lopez on 5/14/13.
//  Copyright (c) 2013 meme lopez. All rights reserved.
//

#include "slinkednode.h"

SLinkedNode::SLinkedNode(Object* E){
    data = E;
    next = NULL;
}// fin constructor

SLinkedNode::~SLinkedNode(){
    if(data)
        delete data;
    if (next)
        delete next;
}// fin destructor

void SLinkedNode::setData(Object *E){
    data = E;
}// fin setData

Object* SLinkedNode::getData() const{
    return data;
}// fin getData

void SLinkedNode::setNext(SLinkedNode* n){
    next = n;
}//fin

SLinkedNode* SLinkedNode::getNext() const{
    return next;
}// fin 