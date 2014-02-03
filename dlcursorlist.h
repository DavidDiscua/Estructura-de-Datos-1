#ifndef DLCURSORLIST_H
#define DLCURSORLIST_H
#include "object.h"
#include "tdalist.h"
#include <string>
using namespace std; 

class DLCursorList : public TDAList {
	struct row {
		int prev, next;
		Object* data;
		row(Object* E){
			prev = next = -1;
			data = E;
		}
	};
	int capa, head, tail, nextSlot;
	row** data;
	int calc_nextSlot();
	bool makebigger();
public:
	explicit DLCursorList();
	virtual ~DLCursorList();
	virtual bool insert(Object*, int);
	virtual int indexOf(Object*) const;
	virtual Object* get(unsigned) const;
	virtual Object* remove(unsigned);
	virtual int prev(int) const;
	virtual int next(int) const;
	virtual void clear();
	virtual Object* first() const;
	virtual Object* last() const;
	virtual string toString() const;
	virtual bool isFull() const;
};

#endif 