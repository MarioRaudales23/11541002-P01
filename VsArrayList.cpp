#include "VsArrayList.h"
#include "Object.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

VsArrayList::VsArrayList(int capacity){
	currentcapacity=capacity;
	array=new Object*[capacity];
	if (!array)
	{
		cerr<<"Out of Memory"<<endl;
	}
	delta=currentcapacity*0.5;
}
VsArrayList::VsArrayList(int capacity,int delta){
	currentcapacity=capacity;
	array=new Object*[capacity];
	if (!array)
	{
		cerr<<"Out of Memory"<<endl;
	}
	this->delta=delta;
}

VsArrayList::~VsArrayList(){
	for (int i = 0; i < getSize(); ++i)
	{
		if (array[i])
		{
			delete array[i];
		}
	}
	delete array;
}

void VsArrayList::clear(){
	for (int i = 0; i < getSize(); ++i)
	{
		if (array[i])
		{
			delete array[i];
			array[i] = NULL;
		}
	}
	size=0;
}

Object* VsArrayList::remove(int p){
	if (p < 0|| p > getSize())
	{
		cerr<<"Posicion invalida";
		return NULL;
	}
	Object* temp = array[p];
	//delete array[p];
	for (int i = p; i <size ; ++i)
	{
		array[i] = array[i+1];
	}
	size--;
	return temp;
}

Object* VsArrayList::first()const{
	return array[0];
}
Object* VsArrayList::last()const{
	return array[size-1];
}

int VsArrayList::indexof(Object* e){
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return -1;
	}
	for (int i = 0; i < size; ++i)
	{
		if (array[i]->equals(e))
		{
			return i;
		}
	}
	return -1;
}

Object* VsArrayList::get(int p)const{
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return NULL;
	}
	if (p<0||p>size)
	{
		cerr<<"Posicion invalida";
		return NULL;
	}else{
		return array[p];
	}
}

int VsArrayList::getCapacity()const{
	return currentcapacity;
}

bool VsArrayList::isFull()const{
	if (size == currentcapacity)
	{
		return true;
	}
	return false;
}

bool VsArrayList::isEmpty()const{
	if (size==0)
	{
		return true;
	}
	return false;
}

void VsArrayList::resize(){
	Object** temp = NULL;
	temp = new Object*[currentcapacity+delta];
	if (!array)
	{
		cerr<<"Out of Memory"<<endl;
		exit(1);
	}
	for (int i = 0; i < currentcapacity; ++i)
	{
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
	currentcapacity+=delta;
}

bool VsArrayList::insert(Object* e,int p){
	if (p<0||p>getSize())
	{
		return false;
	}
	if (getSize() == currentcapacity)
	{
		resize();
	}
	for (int i = getSize(); i > p; --i)
	{
		array[i] = array[i-1];
	}
	array[p] = e;
	size++;
	return true;
}