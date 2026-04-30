#include <iostream>
using namespace std;

/*Una empresa divide el trabajo en dos turnos (mañana y tarde) en las que trabajan 6
empleados (3/turno). Agrupar los sueldos de los empleados en dos listas y mostrar
después las listas por pantalla.*/

struct Nodo {
	string empleado;
	float sueldo;
	Nodo *siguiente;
};

int main(int argc, char *argv[]) {
	
	Nodo *listaManana = NULL;
	Nodo *listaTarde = NULL;
	
	for (int i = 0; i < 6; i++) {
		string turno;
		Nodo *nuevo_nodo = new Nodo();
		cout<<"Ingrese el nombre del empleado número "<<i+1<<":"<<endl;
		cin>>nuevo_nodo->empleado;
		fflush(stdin);
		cout<<"Ingrese el turno en el que trabaja el empelado (Mañana o Tarde): "<<endl;
		cin>>turno;
		fflush(stdin);
		cout<<"Ingrese el sueldo del empelado: "<<endl;
		cin>>nuevo_nodo->sueldo;
		nuevo_nodo->siguiente = NULL;
		
		if (turno == "Mañana") {
			nuevo_nodo->siguiente = listaManana;
			listaManana = nuevo_nodo;
		} else if(turno == "Tarde") {
			nuevo_nodo->siguiente = listaTarde;
			listaTarde = nuevo_nodo;
		}
	}
	
	cout<<"\nLa lista de empleados que trabajan en la mañana es:"<<endl;
	Nodo *actual = listaManana;
	while (actual != NULL) {
		cout<<actual->empleado<<" - Sueldo: "<<actual->sueldo<<endl;
		actual = actual->siguiente; 
	}
	
	cout<<"\nLa lista de empleados que trabajan en la tarde es:"<<endl;
	actual = listaTarde;
	while (actual != NULL) {
		cout<<actual->empleado<<" - Sueldo: "<<actual->sueldo<<endl;
		actual = actual->siguiente; 
	}
	
	return 0;
}

