#include <iostream>
#include <cstring>
using namespace std;

struct producto {
	int codigo;
	string nombre;
	int camionAsignado
	float sueldo;
};

void agregarEmpleado(producto *&lista) {
	producto *aux, aux2;
	int codigo, camionAsignado;
	float sueldo;
	string nombre;
	bool codigoUnico = false;
	
	do {
		
		
		
	} while(codigo < 0 || codigo > 999 || !codigoUnico);
}

int main(int argc, char *argv[]) {
	producto *lista = NULL;
	char option;
	int codigo;
	
	do {
		cout<<"Menu:"<<endl;
		cout<<"1) Agregar un Empleado"<<endl<<
			"2) Mostrar Empleados"<<endl<<
			"3) Buscar Empleado"<<endl<<
			"4) Empleado con Mayor Sueldo"<<endl<<
			"5) Eliminar un Empleado"<<endl<<
			"6) Guardar empleados"<<endl<<
			"7) Salir"<<endl;
		
		switch (option) {
		case '1':
			agregarEmpleado(lista);
			break;
		case '2':
			do {
				cout<<"Ingrese el código de empleado a buscar: ";
				cin>>codigo;
				
				if (codigo < 0 || codigo > 999) {
					cout<<"Ingrese el código de "
				}
			} while();
			mostrarEmpleados(lista, id);
		}
	} while(true);
	
	return 0;
}
