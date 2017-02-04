
#include "Object.h"
#include <sstream>
#include <string>

using std::string;
using std::stringstream;

Object::Object(){};

Object::~Object(){};

string Object::toString()const{
	stringstream ss;
	ss<<"Object@"<<this;
	return ss.str();
}

bool Object::equals(Object* other)const{
	return other == this;
}