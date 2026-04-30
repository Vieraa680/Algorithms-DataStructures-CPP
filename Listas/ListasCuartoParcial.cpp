#include <iostream>
using namespace std;

struct Nodo {
	int legajo;
	string apellido;
	string nombre;
	int codigoMateria;
	string condicion;
	Nodo *siguiente;
};

void insertar(Nodo *&lista, Nodo *nuevo_nodo);

void LISTA (Nodo *&);

void imprimir(Nodo *lista);

int main(int argc, char *argv[]) {
	
	char opcion;
	
	Nodo *lista = NULL;
	
	cout<<"Menú:"<<endl;
	cout<<"1.- Lista"<<endl;
	cout<<"2.- Archivo"<<endl;
	cout<<"F-f Finalizar."<<endl;
	
	cout<<"Seleccione una opción del Menú: "<<endl;
	cin>>opcion;
	
	switch (opcion) {
	case '1': 
		LISTA (lista);
		imprimir(lista);
		break;
	case '2': 
		cout<<"Chau";
		break;
	case 'F':
		cout<<"Tuki";
	}
	return 0;
}

void insertar(Nodo *&lista, Nodo *nuevo_nodo) {
	Nodo *aux;
	
	if (lista == NULL) { // Si la lista está vacía
		lista = nuevo_nodo; // El nuevo nodo es el primer nodo de la lista
	} else { // Si la lista no está vacía
		aux = lista; // Empezamos a recorrer la lista desde el principio
		
		// Recorremos la lista hasta llegar al último nodo
		while (aux->siguiente != NULL) {
			aux = aux->siguiente;
		}
		
		// Insertamos el nuevo nodo al final de la lista
		aux->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = NULL; // El siguiente del nuevo nodo es NULL porque es el último nodo
}


void LISTA (Nodo *&lista) {
	
	char continuar, condicion1;
	
	string Libre = "Libre", Regular = "Regular";
	
	do {
		Nodo *nuevo_nodo = new Nodo();
		do {
			cout<<"Ingrese su número de legajo: "<<endl;
			cin>>nuevo_nodo->legajo;
			if(nuevo_nodo->legajo < 100 or nuevo_nodo->legajo > 200) {
				cout<<"Número de legajo inválido. Reingrese."<<endl;
			} 
		} while(nuevo_nodo->legajo < 100 or nuevo_nodo->legajo > 200);
		
		cout<<"Ingrese su apellido: "<<endl;
		cin>>nuevo_nodo->apellido;
		
		fflush(stdin);
		
		cout<<"Ingrese su nombre: "<<endl;
		cin>>nuevo_nodo->nombre;
		fflush(stdin);
		
		do {
			cout<<"Ingrese el código de la matería a la cual se inscribe: "<<endl;
			cin>>nuevo_nodo->codigoMateria;
			if (nuevo_nodo->codigoMateria < 500 or nuevo_nodo->codigoMateria > 600) {
				cout<<"El código de la materia es inválido. Reingrese."<<endl;
			}
		} while(nuevo_nodo->codigoMateria < 500 or nuevo_nodo->codigoMateria > 600);
		
		do {
			cout<<"Ingrese su condición. L para Libre o R para Regular: "<<endl;
			fflush(stdin);
			cin>>condicion1;

			if (condicion1 != 'L' && condicion1 != 'l' && condicion1 != 'R' && condicion1 != 'r'){
				cout<<"Condición inválida. Reingrese."<<endl;
			} 
			if (condicion1 == 'L' or condicion1 == 'l') {
				nuevo_nodo->condicion = Libre;
			}
			if (condicion1 == 'R' or condicion1 == 'r') {
				nuevo_nodo->condicion = Regular;
			}
		} while(condicion1 != 'L' && condicion1 != 'l' && condicion1 != 'R' && condicion1 != 'r');
		
		insertar(lista, nuevo_nodo);
		
		do {
			cout<<"¿Desea seguir cargando datos? (S para si. N para no)"<<endl;
			cin>>continuar;
			if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n') {
				cout<<"Respuesta inválida. Reingrese."<<endl;
			}
		} while(continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');
	} while(continuar == 'S' or continuar == 's');
	
}

void imprimir(Nodo *lista) {
	Nodo *actual = lista;  // Empezamos a recorrer la lista desde el principio
	
	while (actual != NULL) {  // Mientras no lleguemos al final de la lista
		// Imprimimos los datos del nodo actual
		cout << "Legajo: " << actual->legajo << endl;
		cout << "Apellido: " << actual->apellido << endl;
		cout << "Nombre: " << actual->nombre << endl;
		cout << "Código de Materia: " << actual->codigoMateria << endl;
		cout << "Condición: " << actual->condicion << endl;
		cout << "------------------------" << endl;
		
		actual = actual->siguiente;  // Pasamos al siguiente nodo
	}
}
