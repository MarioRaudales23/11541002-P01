#include "ADTList.h"
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include "VsArrayList.h"
#include <string>
#include <iostream>
using namespace std;

void listar(ADTList*);
void SueldoMayor(ADTList*);
void SueldoMenor(ADTList*);

int main(int argc, char const *argv[])
{
	int opcion;
	ADTList* empleados = new VsArrayList(5,5);
	while(opcion != 8){
		cout<<"1-Ingresar Empleados\n2-Listar Empleados\n"
		<<"3-Borrar Empleados\n4-Sueldo Promedio\n5-Sueldo Mayor"
		<<"\n6-Sueldo Menor\n7-Ajuste de Inflacion\n8-Salir\n....";
		cin>>opcion;
		switch(opcion){
			case 1:{
				double sueldo;
				string nombre;
				int edad;
				cout<<"Ingrese el nombre del empleado: ";
				cin>>nombre;
				cout<<"Ingrese la edad del empleado: ";
				cin>>edad;
				cout<<"Ingrese el sueldo del empleado: ";
				cin>>sueldo;
				empleados->insert(new Employee(sueldo,nombre,edad),0);
				break;
			}
			case 2:{
				listar(empleados);
				break;
			}
			case 3:{
				int posbor;
				listar(empleados);
				cout<<"Ingrese el empleado a borrar: ";
				cin>>posbor;
				Object* borrar = empleados->remove(posbor);
				if (borrar == NULL)
				{
					cout<<"Borrado Invalido"<<endl;
				}else{
					cout<<borrar->toString()<<endl;
				}
				break;
			}
			case 4:{
				double sueldprom;
				for (int i = 0; i < empleados->getSize(); ++i)
				{
					if (dynamic_cast<Employee*>(empleados->get(i))){
						Employee* temp = dynamic_cast<Employee*>(empleados->get(i));
						sueldprom += temp->getSueldo();
					}
				}
				sueldprom = sueldprom/empleados->getSize();
				cout<<"El Sueldo promedio es: "<<sueldprom;
				break;
			}
			case 5:{
				SueldoMayor(empleados);
				break;
			}
			case 6:{
				SueldoMenor(empleados);
				break;
			}
			case 7:{
				int inflacion;
				cout<<"Ingrese el valor de Inflacion porcentual: ";
				cin>>inflacion;
				cout<<"Empleados antes del aumento"<<endl;
				listar(empleados);
				for (int i = 0; i < empleados->getSize(); ++i)
				{
					if (dynamic_cast<Employee*>(empleados->get(i))){
						dynamic_cast<Employee*>(empleados->get(i))->inflacion(inflacion);
					}
				}
				cout<<"Empleados despues del aumento"<<endl;
				listar(empleados);
				break;
			}
			case 8:{
				break;
			}
			default:{
				cout<<"Opcion no valida"<<endl;
				break;
			}
		}
	}
	delete empleados;
	return 0;
}

void listar(ADTList* empleados){
	for (int i = 0; i < empleados->getSize(); ++i)
	{
		cout<<i<<" "<<empleados->get(i)->toString()<<endl;
	}
}

void SueldoMayor(ADTList* empleados){
	double mayor;
	if (dynamic_cast<Employee*>(empleados->get(0))){
			Employee* temp = dynamic_cast<Employee*>(empleados->get(0));
			mayor = temp->getSueldo();
	}
	for (int i = 0; i < empleados->getSize(); ++i)
	{
		if (dynamic_cast<Employee*>(empleados->get(i))){
			Employee* temp = dynamic_cast<Employee*>(empleados->get(i));
			if (temp->getSueldo() > mayor)
			{
				mayor = temp->getSueldo();
			}
		}
	}
	for (int i = 0; i < empleados->getSize(); ++i)
	{
		if (dynamic_cast<Employee*>(empleados->get(i))){
			Employee* temp = dynamic_cast<Employee*>(empleados->get(i));
			if (temp->getSueldo() == mayor)
			{
				cout<<i<<" "<<temp->toString()<<endl;
			}
		}
	}
}

void SueldoMenor(ADTList* empleados){
	double menor;
	if (dynamic_cast<Employee*>(empleados->get(0))){
			Employee* temp = dynamic_cast<Employee*>(empleados->get(0));
			menor = temp->getSueldo();
	}
	for (int i = 0; i < empleados->getSize(); ++i)
	{
		if (dynamic_cast<Employee*>(empleados->get(i))){
			Employee* temp = dynamic_cast<Employee*>(empleados->get(i));
			if (temp->getSueldo() < menor)
			{
				menor = temp->getSueldo();
			}
		}
	}
	for (int i = 0; i < empleados->getSize(); ++i)
	{
		if (dynamic_cast<Employee*>(empleados->get(i))){
			Employee* temp = dynamic_cast<Employee*>(empleados->get(i));
			if (temp->getSueldo() == menor)
			{
				cout<<i<<" "<<temp->toString()<<endl;
			}
		}
	}
}