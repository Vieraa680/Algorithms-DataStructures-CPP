#include <iostream>
using namespace std;

struct Nodo {
	int unidad;
	float cantidadKm;
	Nodo *siguiente;
};

void LISTA ();
void ARCHIVO (Nodo *);

int main(int argc, char *argv[]) {
	char opcion;
	do {
		cout<<"Menú:"<<endl;
		cout<<"1.- Lista"<<endl;
		cout<<"2.- Archivo"<<endl;
		cout<<"F-f Finalizar"<<endl;
		
		cout<<"Ingrese una opción del menú anterior:"<<endl;
		cin>>opcion;
		
		switch (opcion) {
		case '1':
			LISTA();
			break;
		case '2':
			ARCHIVO(Nodo *lista);
		case '3':
			cout<<"Case 3"<<endl;
		}
	} while(opcion != 'F' && opcion != 'f');
	
	return 0;
}

void LISTA() {
	Nodo *lista = NULL;
	int unidad;
	
	//Cargar Lista Enlazada
	do {
		Nodo *nuevo_nodo = new Nodo();
		do {
			cout<<"Ingrese el número de unidad (0 para finalizar):"<<endl;
			cin>>nuevo_nodo->unidad;
			unidad = nuevo_nodo->unidad;
			if (nuevo_nodo->unidad == 0) {
				break;
			}
			if (nuevo_nodo->unidad < 0) {
				cout<<"El número de unidad tiene que ser un entero positivo. Reingrese."<<endl;
			}
		} while(nuevo_nodo->unidad < 0);
		if (nuevo_nodo->unidad == 0) {
			break;
		}
		do {
			cout<<"Ingrse la cantidad de KM recorridos:"<<endl;
			cin>>nuevo_nodo->cantidadKm;
			if (nuevo_nodo->cantidadKm < 0) {
				cout<<"La cantidad de KM recorridos no puede ser negativa. Reingrese"<<endl;
			}
		} while(nuevo_nodo->cantidadKm < 0);
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
	} while(unidad != 0);
	
	Nodo *actual = lista;
	
	while (actual != NULL) {
		cout<<"Unidad: "<<actual->unidad<<", KM: "<<actual->cantidadKm<<endl;
		actual = actual->siguiente;
	}
	
	int unidadMax = 0;
	int maxKm = 0;
	actual = lista;
	
	while (actual != NULL) {
		float totalKm = 0;
		Nodo *temp = lista;
		while (temp != NULL) {
			if (temp->unidad == actual->unidad) {
				totalKm += temp->cantidadKm;
			}
			temp = temp->siguiente;
		}
		if (totalKm > maxKm) {
			maxKm = totalKm;
			unidadMax = actual->unidad;
		}
		actual = actual->siguiente;
	}
	cout<<"La unidad que más km ha recorrido es la "<<unidadMax<<" con "<<maxKm<<" Km."<<endl;
	
	//Liberar Memoria
	
	actual = lista;
	while(actual != NULL) {
		Nodo *siguiente = actual->siguiente;
		delete actual;
		actual = siguiente;
	}
	lista = NULL;
}

void ARCHIVO(Nodo *lista) {
	if (lista == NULL) {
		cout<<"Debe ejecutar primero la opción 1."<<endl;
		return;
	}
}

