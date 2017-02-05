#include "Person.h"
#include <string>

class Employee:public Person{
	private:
		double sueldo;
	public:
		Employee(double,string,int);
		virtual~Employee();
		virtual string toString()const;
		double getSueldo();
		bool inflacion(double aumento);	
};