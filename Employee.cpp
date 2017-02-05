#include "Employee.h"
#include "Person.h"
#include <string>
#include <sstream>
using std::stringstream;
using std::string;

Employee::Employee(double sueldo,string name,int edad):Person(name,edad),sueldo(sueldo){
}

Employee::~Employee(){

}

string Employee::toString()const{
	stringstream ss;
	ss<<Person::toString()<<" Sueldo:"<<sueldo;
	return ss.str();
}
//Devuelve el sueldo actual
double Employee::getSueldo(){
	return sueldo;
}
//Asigna un cambia a sueldo por metio de porcentaje
bool Employee::inflacion(double aumento){
	double valor = aumento/100;
	sueldo = sueldo + (sueldo*valor);
	return true;
}