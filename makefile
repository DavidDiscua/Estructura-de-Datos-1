tda:	main.o integer.o linkedlist.o object.o tdalist.o dllnode.o dlcursorlist.o VArrayList.o FArrayList.o slinkedlist.o slinkednode.o
	g++ main.o integer.o dllnode.o linkedlist.o object.o tdalist.o dlcursorlist.o VArrayList.o FArrayList.o slinkedlist.o slinkednode.o -o tda

main.o:	main.cpp tdalist.h linkedlist.h integer.h
	g++ -c main.cpp

integer.o:	integer.cpp integer.h object.h
	g++ -c integer.cpp

dllnode.o:	dllnode.cpp dllnode.h
	g++ -c dllnode.cpp

tdalist.o:	tdalist.h tdalist.cpp
	g++ -c tdalist.cpp

linkedlist.o:	linkedlist.cpp linkedlist.h tdalist.h object.h
	g++ -c linkedlist.cpp

object.o:	object.h object.cpp
	g++ -c object.cpp

dlcursorlist.o:	dlcursorlist.h tdalist.h
	g++ -c dlcursorlist.cpp

varraylist.o:	VArrayList.h tdalist.h
	g++ -c VArrayList.cpp

farraylist.o:	FArrayList.h tdalist.h
	g++ -c FArrayList.cpp

slinkedlist.o: slinkednode.o slinkedlist.h tdalist.h
	g++ -c slinkedlist.cpp

slinkednode.o: slinkednode.h object.h tdalist.h
	g++ -c slinkednode.cpp

clean:
	rm *.o tda
