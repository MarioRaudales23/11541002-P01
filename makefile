main:	ADTList.o Person.o Object.o VsArrayList.o Employee.o main.o
	g++ ADTList.o Person.o Object.o VsArrayList.o main.o Employee.o -o run

ADTList.o:	ADTList.h ADTList.cpp Object.h
	g++ -c ADTList.cpp

Person.o:	Person.h Person.cpp Object.h
	g++ -c Person.cpp

Object.o: Object.h Object.cpp
	g++ -c Object.cpp

main.o:	main.cpp ADTList.h VsArrayList.h Person.h Object.h Employee.h
	g++ -c main.cpp

VsArrayList.o:	ADTList.h VsArrayList.h VsArrayList.cpp Object.h
	g++ -c VsArrayList.cpp
Employee.o:	Employee.cpp Employee.h Object.h
	g++ -c Employee.cpp

