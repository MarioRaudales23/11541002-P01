#pragma once
#include "Object.h"

class ADTList:public Object{
	protected:
		int size;
	public:
		ADTList();
		virtual ~ADTList();
		int getSize();
		virtual bool insert(Object* ,int)=0;
		virtual Object* remove(int)=0;
		virtual Object* first()const=0;
		virtual Object* last()const=0;
		virtual void clear()=0;
		virtual int indexof(Object*)=0;
		virtual Object* get(int)const=0;
		virtual int getCapacity()const=0;
		virtual bool isEmpty()const=0;
		virtual bool isFull()const=0;

};