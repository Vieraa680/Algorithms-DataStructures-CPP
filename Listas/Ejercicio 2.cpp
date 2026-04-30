#include <iostream>
using namespace std;

//Realizar un programa que permita crear una lista y almacenar los nombres de N países,
//	luego mostrarlos en el orden ingresado.

struct Nodo {
	string paises;
	Nodo *siguiente;
};

int main(int argc, char *argv[]) {
	
	Nodo *lista = NULL, *ultimo = NULL;
	int cantidad;
	
	
	cout<<"Ingrese la cantidad de países que desea ingresar: "<<endl;
	cin>>cantidad;
	
	for (int i = 0; i < cantidad; i++) {
		Nodo *nuevo_nodo = new Nodo();
		cout<<"Ingrese el nombre del país "<<i+1<<":"<<endl;
		cin>>nuevo_nodo->paises;
		nuevo_nodo->siguiente = NULL;
		
		if (lista == NULL) {
			lista = nuevo_nodo;
		} else {
			ultimo->siguiente = nuevo_nodo;
		}
		
		ultimo = nuevo_nodo;
	}
	
	cout<<"\nLa lista de países ingresados es:"<<endl;
	
	Nodo *actual = lista;
	
	while (actual != NULL) {
		cout<<actual->paises<<endl;
		cout<<"-----------------"<<endl;
		actual = actual->siguiente; 
	}
	
	return 0;
}

