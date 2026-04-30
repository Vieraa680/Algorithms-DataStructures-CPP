#include <iostream>
#include <fstream>
using namespace std;

struct Nodo {
	string nombre;
	int DNI;
	Nodo *siguiente;
};

void agregarNodo(Nodo*& lista, string nombre, int DNI) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->nombre = nombre;
	nuevo_nodo->DNI = DNI;
	nuevo_nodo->siguiente = NULL;
	
	if (lista == NULL) {
		lista = nuevo_nodo;
	} else {
		Nodo *aux = lista;
		while (aux->siguiente != NULL) {
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;
	}
}

void guardarEnArchivo(Nodo* lista) {
	ofstream archivo("agenda.txt");
	
	Nodo *aux = lista;
	
	while (aux != NULL) {
		archivo<<aux->nombre<<endl;
		archivo<<aux->DNI<<endl;
		
		aux = aux->siguiente;
	}
	archivo.close();
	
	cout<<"Datos guardados correctamente."<<endl;
}

void cargarDesdeArchivo(Nodo*& lista) {
	ifstream archivo("agenda.txt");
	
	if (archivo.fail()) {
		cout<<"No se encontró el archivo. Creando lista vacía."<<endl;
		return;
	}
	
	string nombre;
	int DNI;
	
	while(getline(archivo, nombre)) {
		archivo>>DNI;
		cin.ignore();
		
		agregarNodo(lista, nombre, DNI);
	}
}

void mostrarLista(Nodo* lista) {
	Nodo *aux = lista;
	int contador = 1;
	
	while (aux != NULL) {
		cout << contador << ". " << aux->nombre << " (DNI: " << aux->DNI << ")" << endl;
		aux = aux->siguiente;
		contador++;
	}
}


int main(int argc, char *argv[]) {
	Nodo *lista = NULL;
	
	cargarDesdeArchivo(lista);
	
	mostrarLista(lista);
	
	string nombre;
	int DNI;
	
	
	cout<<"Ingresando nuevos datos: "<<endl;
	
	for (int i = 0; i < 20; i++) {
		cout<<"Persona "<<i+1<<": "<<endl;
		cout<<"Ingrese DNI: ";
		cin>>DNI;
		cin.ignore();
		
		if (DNI == 0) break;
		
		cout<<"Ingrese nombre: ";
		getline(cin, nombre);
		
		agregarNodo(lista, nombre, DNI);
	}
	
	guardarEnArchivo(lista);
	
	
	return 0;
}

