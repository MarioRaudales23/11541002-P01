#pragma once
#include "Object.h"
#include <string>
using std::string;
class Person:public Object{
		string name;
		int age;
	public:
		Person(string,int);
		virtual ~Person();
		virtual string toString()const;
		virtual bool equals(Object*)const;
};