
//  FArrayList.cpp

#include "farraylist.h"
#include <iostream>
using namespace std;

FArrayList::FArrayList(int c){
    this->capacity=c;
    this->data = new Object*[capacity];
}

FArrayList::~FArrayList(){
    delete []data;
}

bool FArrayList::insert(Object* E, int p){//Funcion Insertar Elemento
    if (isFull())//verirficar si esta Llena
        return false;
    if (!(p>=0 && p<=SIZE))//Validar Posicion
        return false;
    
    //insertar al final del arreglo o cuando esta vacia
    if (isEmpty() || p==SIZE)
        data[p] = E;
    else{
        //insertar en medio de la lista o al principio, hay que correr elementos
        for (int i=SIZE; i>p; i--)
            data[i] = data[i-1];
        
        data[p] = E;
    }// fin else
    
    SIZE++;
    return true;
}// fin insert

Object* FArrayList::first() const{//Inicio first
    if (isEmpty())
        return NULL;
    
    return data[0];
}// fin first

Object* FArrayList::last() const{//inicio last
    if (isEmpty())
        return NULL;
    
    return data[SIZE-1];
}// fin last

int FArrayList::getCapacity() const{//inicio getCaapcity
    return capacity;
}// fin getCapacity

Object* FArrayList::remove(unsigned int p){//inicio Remover
    if (isEmpty())//Verificar si esta Vacia
        return NULL;
    if (p<0 || p>=SIZE)//verificar si la posicion es valida
        return NULL;
    
    Object* retval = data[p];
    if (p==SIZE-1)//remover el ultimo elemento de la lista
        data[p]=NULL;
    else{//remover cualquier otro elemento dentro de la lista
        for (int i=p; i<SIZE-1; i++)
            data[i]= data[i+1];
        
        data[SIZE-1]= NULL;
    }
    SIZE--;//drecrementar el SIZE
    return retval;
}//fin remove

bool FArrayList::isFull() const{//inicio IsFull
    if (SIZE>= capacity)
        return true;
    else
        return false;
}// fin isFUll

void FArrayList::clear(){
    delete [] data;
    
    data= new Object*[capacity];
    SIZE=0;
} //fin clear

int FArrayList::indexOf(Object* E) const{//inicio IndexOf
    for (int i=0; i<SIZE; i++) {
        if(data[i]->equals(E))
            return i;
    }
    return -1;
}// fin indexOF

Object* FArrayList::get(unsigned int p) const{//inicio get
    if (isEmpty())
        return NULL;
    if (p<0 || p>=SIZE)
        return NULL;
    
    return data[p];
}//fin get


int FArrayList::size()const{

    return SIZE;
}


 int FArrayList::prev(int n)const{


    return (n-1);
 }  

 int FArrayList::next(int n)const{


    return (n+1);
 }     

 string FArrayList::toString()const{

 
 }
