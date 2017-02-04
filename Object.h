#pragma once
#include <sstream>
#include <string>

using std::string;

class Object{
	public:
		Object();
		virtual ~Object();
		virtual string toString()const;
		virtual bool equals(Object*)const;	
};