#include "Person.h"
#include "Object.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Person::Person(string name,int age):name(name),age(age){}

Person::~Person(){

}

string Person::toString()const{
	stringstream ss;
	ss<<"Nombre: "<<name
	<<"Edad: "<<age;
	return ss.str();
}
//Duevuele si una Persona el igual a otra
bool Person::equals(Object* other)const{
	if (dynamic_cast<Person*>(other))
	{
		return false;
	}
	Person* p = dynamic_cast<Person*>(other);
	return p->name==name;
}