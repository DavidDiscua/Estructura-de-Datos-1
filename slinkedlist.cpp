//
//  SLinkedList.cpp
//  Estructuras
//
//  Created by meme lopez on 5/14/13.
//  Copyright (c) 2013 meme lopez. All rights reserved.
//

#include "slinkedlist.h"

SLinkedList::SLinkedList(){
    head=NULL;
}//fin constructor

SLinkedList::~SLinkedList(){
    if (head)
        delete head;
}// fin destructor

bool SLinkedList::insert(Object* E, int p){
    if(!(p>=0&&p<=SIZE))
        return false;
    
    SLinkedNode* neo = new SLinkedNode (E);
    
    if (!neo)//revisa si creo a neo
        return false;
    if (isEmpty())// mira a ver si la lista esta vacia
        head = neo;//si esta vacia entonces solo lo pone en head
    else {
        if (p==0) {//si no esta vacia pero quiere insertar en p=0
            neo->setNext(head);
            head = neo;
        } else{//para cuando quiere insertar en una posicion despues el principio
            SLinkedNode* tmp = head;//necesario para recorrer la lista
            
            for (int i =0; i<p-1; i++)//recorre lista y para una posicion antes de donde quiere poner
                tmp = tmp->getNext();
            //deja a tmp con el nodo
            neo->setNext(tmp->getNext());
            tmp->setNext(neo);
        }
    }
    SIZE++;
    return true;
}//fin insert

Object* SLinkedList::remove(unsigned int p){
    if (isEmpty())
        return NULL;
    if (!(p>=0&&p<SIZE))//aqui tiene que ingresar una posicion directa osea 0,1,2,3,... hasta antes de SIZE. si mete el SIZE entonces no se puede.
        return NULL;
    
    SLinkedNode* rem = head;
    Object* retval = NULL;
    
    if (p==0)
        head = head->getNext();
    else{
        for (int i=0; i<p-1; i++)
            rem = rem->getNext();
        SLinkedNode* tmp = rem;
        rem=rem->getNext();
        tmp->setNext(rem->getNext());
    }
    //al llegar aqui ya corrio las posiciones omitiendo al que quiere remove y lo tiene guardado en rem para sacar su data
    retval = rem->getData();
    rem->setData(NULL);
    rem->setNext(NULL);
    delete rem;
    SIZE--;
    return retval;
}//fin remove

Object* SLinkedList::first() const{
    if (isEmpty())
        return NULL;
    return head->getData();
}// fin first

Object* SLinkedList::last() const{
    if (isEmpty())
        return NULL;
    SLinkedNode* tmp = head;
    
    for (int i=0; i<SIZE-1; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}// fin last

int SLinkedList::capacity() const{
    return -1;
}// fin getCapacity

bool SLinkedList::isFull() const{
    return false;
}// fin siFull

void SLinkedList::clear(){
    if (isEmpty())
        return;
    delete head;
    head = NULL;
    SIZE =0;
}// fin clear

int SLinkedList::indexOf(Object* E) const{
    if (isEmpty())
        return -1;
    SLinkedNode* tmp = head;
    for (int i=0; i<SIZE; i++){
        if (tmp->getData()->equals(E))
            return i;
    }
    return -1;
}// fin indexOf

Object* SLinkedList::get(unsigned int p) const{
    if (isEmpty())
        return NULL;
    if (!(p>=0&&p<SIZE))
        return NULL;
    SLinkedNode* tmp = head;
    for(int i =0; i<p; i++)
        tmp= tmp->getNext();
    
    return tmp->getData();
}// fin get
int SLinkedList::prev(int p) const{
    return p - 1;
}
int SLinkedList::next(int p) const{
    return p + 1;
}
string SLinkedList::toString() const{
    return NULL;
}