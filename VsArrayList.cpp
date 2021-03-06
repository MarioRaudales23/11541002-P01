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
	//Se verifica la memoria
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
//Metodo elimina todo lo que se encuentra en el arreglo
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
//Elimina una posicion especifica en el arreglo
Object* VsArrayList::remove(int pos){
	if (pos < 0|| pos >= getSize())
	{
		cerr<<"Posicion invalida"<<endl;
		return NULL;
	}
	Object* temp = array[pos];
	//delete array[p];
	for (int i = pos; i <size ; ++i)
	{
		array[i] = array[i+1];
	}
	size--;
	return temp;
}
//Devuelve el primer elemento del arreglo
Object* VsArrayList::first()const{
	return array[0];
}
//Deuvuelve el ultimo elemento del arreglo
Object* VsArrayList::last()const{
	return array[size-1];
}
//Busca si un elemento esta en el arreglo y si lo esta devuelve su posicion
int VsArrayList::indexof(Object* elem){
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return -1;
	}
	for (int i = 0; i < size; ++i)
	{
		if (array[i]->equals(elem))
		{
			return i;
		}
	}
	return -1;
}
//Devuelve el elemento en una posicion del arreglo
Object* VsArrayList::get(int pos)const{
	if (isEmpty())
	{
		cout<<"No hay nada en la lista";
		return NULL;
	}
	if (pos<0||pos>=size)
	{
		cerr<<"Posicion invalida";
		return NULL;
	}else{
		return array[pos];
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
//Modifica el tamano del arreglo a una de mayor tamano
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
//Inserta elemnto en posiciones especificas del arreglo
bool VsArrayList::insert(Object* elem,int pos){
	if (pos<0||pos>getSize())
	{
		return false;
	}
	if (getSize() == currentcapacity)
	{
		resize();
	}
	for (int i = getSize(); i > pos; --i)
	{
		array[i] = array[i-1];
	}
	array[pos] = elem;
	size++;
	return true;
}