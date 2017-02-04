#pragma once
#include "ADTList.h"

class VsArrayList:public ADTList{
	private:
		int currentcapacity;
		int delta;
		Object** array;
		void resize();
	public:
		VsArrayList(int);
		VsArrayList(int,int);
		virtual ~VsArrayList();
		virtual bool insert(Object* ,int);
		virtual Object* remove(int);
		virtual Object* first()const;
		virtual Object* last()const;
		virtual void clear();
		virtual int indexof(Object*);
		virtual Object* get(int)const;
		virtual int getCapacity()const;
		virtual bool isEmpty()const;
		virtual bool isFull()const;
};