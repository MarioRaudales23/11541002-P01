#include "Employee.h"
#include "Person.h"
#include <string>
#include <sstream>

Employee::Employee(double sueldo,string name,int edad):Person(name,edad),sueldo(sueldo){
}

Employee::~Employee(){

}

string Employee::toString()const{
	stringstream ss;
	
}