#include <iostream>
using namespace std;

//Realizar un programa que contenga una lista con 10 valores enteros. Informar de cuántos
//	de ellos son superiores a 100.

struct Nodo {
	int dato;
	Nodo *siguiente;
};

int main(int argc, char *argv[]) {
	
	Nodo *lista = NULL;
	
	int contador = 0;
	
	for(int i = 0; i < 10; i++) {
		Nodo *nuevo_nodo = new Nodo();
		cout<<"Ingrese un valor"<<endl;
		cin>>nuevo_nodo->dato;
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
		
		if(nuevo_nodo->dato > 100) {
			contador++;
		}
	}
	
	cout<<"Hay "<<contador<<" valores superiores a 100."<<endl;
	
	return 0;
}

