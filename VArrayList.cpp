
//  VArrayList.cpp

#include "varraylist.h"

VArrayList::VArrayList(){
    capacity=1;
    data=new Object*[capacity];
}

VArrayList::VArrayList(int a, int b){
    capacity=1;
    data=new Object*[capacity];
}

VArrayList::~VArrayList(){
    delete[] data;
}

bool VArrayList::insert(Object* E, int p){
    if (isFull())//Verificar si esta lleno
        if (!agrandar())//En caso de que este lleno, debemos agrandar
            return false;
    if (!(p>=0  &&  p<=SIZE))//Validar Posicion
        return false;
    
    if (isEmpty()||p==SIZE)//Insertar al final
        data[p]=E;
    else{//cuando inserta en medio o al principio
        //Actualizar Posiciones
        for (int i=SIZE; i>p; i--)
            data[i]=data[i-1];
        data[p]=E;
    }
    SIZE++;
    return true;
}// fin insert

Object* VArrayList::remove(unsigned int p){
    if (isEmpty())
        return NULL;
    if (!(p<=0  &&  p>SIZE))
        return NULL;
    Object* retval = data[p];//Obtener posicion a remover
    
    if (p==SIZE-1)//Remover Ultimo
        data[p] = NULL;
    else {//Remover en n posicion
        //actualizar arrreglo
        for (int i=p; i<SIZE-1; i++)
            data[i]= data[i+1];
        
        data[SIZE-1] = NULL;//ultimo elemento
    }
    SIZE--;
    return retval;
    
}// fin remove

Object* VArrayList::first() const{
    if (isEmpty())
        return NULL;
    return data[0];
}// fin first

Object* VArrayList::last() const{
    if (isEmpty())
        return NULL;
    return data[SIZE-1];
}// fin last

int VArrayList::getCapacity() const{
    return capacity;//return -
}//fin getCapacity

bool VArrayList::isFull() const{
    return SIZE==capacity;
}// fin isFull

void VArrayList::clear() {
    delete[] data;
    
    data = new Object*[capacity];
    SIZE=0;
}// fin

int VArrayList::indexOf(Object*E)const{
    for (int i=0; i<SIZE; i++) {
        if (data[i]->equals(E))
            return i;
    }
    return -1;
}// fin

Object* VArrayList::get(unsigned int p) const{
    if(isEmpty())
        return NULL;
    if (p<0||p>=SIZE)
        return NULL;
    return data[p];
}// fin

bool VArrayList::agrandar(){//inicio agrandar
    /*int n=(capacity*10);
    capacity=n;
    Object** tmp = new Object*[n];*/
    Object** tmp = new Object*[++capacity];

    if (!tmp)
        return false;
    for(int i =0; i<SIZE;i++)
        tmp[i]= data[i];
    data = tmp;
    //delete[] tmp
    return true;
}//fin agrandar

int VArrayList::size()const{

    return SIZE;
}

 int VArrayList::prev(int n)const{


    return (n-1);
 }  

 int VArrayList::next(int n)const{


    return (n+1);
 }     

 string VArrayList::toString()const{

    return "PRUEBA";
 }
