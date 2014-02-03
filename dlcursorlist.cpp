#include "dlcursorlist.h"
#include "tdalist.h"
#include <iostream>
using namespace std;

DLCursorList::DLCursorList(){
	capa = 1;
	head = -1;
	data = new row*[capa];
}
DLCursorList::~DLCursorList(){
	delete data;
}
bool DLCursorList::insert(Object* element, int p){
	if (isFull())
		if (!makebigger())
			return false;
	if (p < 0 || p > SIZE)
		return false;

	row* neo = new row(element);
	
	if (head == -1){
		data[0] = neo;
		head = 0;
		nextSlot = calc_nextSlot();
	} else {
		if (data[nextSlot] = neo){
			if (p == 0){
 				data[nextSlot]->next = head;
 				data[head]->prev = nextSlot;
 				head = nextSlot;
 				nextSlot = calc_nextSlot();
			} else if (p > 0 && p < SIZE){
				int tmp = head;
				for (int i = 0; i < p - 1; i++)
					tmp = data[tmp]->next;
				data[nextSlot]->prev = tmp;
				data[nextSlot]->next = data[tmp]->next;
				data[tmp]->next = nextSlot;
				data[data[nextSlot]->next]->prev = nextSlot;
				nextSlot = calc_nextSlot();
			} else {
				int tmp = head;
				for (int i = 0; i < p - 1; i++)
					tmp = data[tmp]->next;
				data[nextSlot]->prev = tmp;
				data[nextSlot]->next = data[tmp]->next;
				data[tmp]->next = nextSlot;
				nextSlot = calc_nextSlot();
			}
		}
	} 
	SIZE++;
	return true;
}
int DLCursorList::indexOf(Object* e) const{
	int tmp = head;
	for (int i = 0; i < SIZE; i++)
		if (data[tmp]->data->equals(e))
			return i;
		else 
			tmp = data[tmp]->next;
	return -1;
}
Object* DLCursorList::get(unsigned p) const{
	if (isEmpty())
		return NULL;
	if (p < 0 || p>SIZE)
		return NULL;
	int tmp = head;
	for (int i = 0; i < p; i++)
		tmp = data[tmp]->next;
	return data[tmp]->data;
}
Object* DLCursorList::remove(unsigned p){
	if (isEmpty())
		return NULL;
	if (p < 0 || p >= SIZE)
		return NULL;
	Object* retVal;
	int tmp;
	if (p == 0){
		tmp = data[head]->next;
		data[head]->next = -1;
		retVal = data[head]->data;
		data[head]->data = NULL;
		//delete[] data[head];
		head = tmp;
	} else if (p == SIZE - 1) {
		tmp = head;
		for (int i = 1; i < p; i++)
			tmp = data[tmp]->next;
		int toErase = data[tmp]->next;
		data[tmp]->next = -1;
		data[toErase]->prev = -1;
		retVal = data[toErase]->data;
		//data[head]->data = NULL;
		delete[] data[toErase];
	} else {
		tmp = head;
		for (int i = 0; i < p - 1; i++)
			tmp = data[tmp]->next;
		int toErase = data[tmp]->next;
		data[tmp]->next = data[data[tmp]->next]->next;
		data[data[tmp]->next]->prev = tmp;
		data[toErase]->next = -1;
		data[toErase]->prev = -1;
		retVal = data[toErase]->data;
		//data[head]->data = NULL;
		delete[] data[toErase];
	}
	SIZE--;
	return retVal;
}
int DLCursorList::prev(int p) const{
	return p - 1;
}
int DLCursorList::next(int p) const{
	return p + 1;
}
void DLCursorList::clear(){
	SIZE = 0;
}
Object* DLCursorList::first() const{
	if (head != -1)
		return data[head]->data;
	return NULL;
}
Object* DLCursorList::last() const{
	if (SIZE != 0){
		int tmp;
		for (int i = 0; i < SIZE; i++)
			if (data[i])
				tmp = i;
		return data[tmp]->data;
	}
	return NULL;
}
string DLCursorList::toString() const{
	return NULL;
}
bool DLCursorList::isFull() const{
	return SIZE == capa;
}
int DLCursorList::calc_nextSlot(){
	int retVal;
	for(retVal = 0; retVal < capa; retVal++)
		if (!data[retVal]->data)
			break;
	return retVal;
}
bool DLCursorList::makebigger(){
	row** tmp = new row*[capa + 1];
	if (!tmp)
		return false;
	for (int i = 0; i < SIZE; i++)
		tmp[i] = data[i];
	data = tmp;
	capa++;
	return true;
}