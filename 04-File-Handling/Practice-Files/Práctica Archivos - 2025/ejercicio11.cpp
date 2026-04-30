#include <iostream>
#include <fstream>
using namespace std;

struct Empleado {
	int ID;
	string nombre;
	int aniosServicio;
	Empleado *siguiente;
};

bool existeID(Empleado* lista, int id) {
	Empleado* aux = lista;
	while (aux != NULL) {
		if (aux->ID == id) return true;
		aux = aux->siguiente;
	}
	return false;
}

void insertarOrdenado(Empleado*& lista, int id, string nombre, int anios) {
	if (existeID(lista, id)) {
		cout<<"Error: El ID "<<id<<" ya existe. No se agregó."<<endl<<endl;
		return;
	}
	
	Empleado* nuevo_nodo = new Empleado();
	nuevo_nodo->ID = id;
	nuevo_nodo->nombre = nombre;
	nuevo_nodo->aniosServicio = anios;
	
	if (lista == NULL || nombre < lista->nombre) {
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
	} else {
		Empleado *aux = lista;
		while (aux->siguiente != NULL && aux->siguiente->nombre < nombre) {
			aux = aux->siguiente;
		}
		nuevo_nodo->siguiente = aux->siguiente;
		aux->siguiente = nuevo_nodo;
	}
	cout<<endl;
}

void cargarDesdeArchivo(Empleado*& listaActivos, Empleado*& listaJubilados) {
	ifstream activos("activos.txt");
	ifstream jubilados("jubilados.txt");
	
	int id, anios;
	string nombre;
	
	if (activos.fail()) {
		cout<<"Hubo un error al encontrar el archivo activos.txt"<<endl;
	} else {
		while (activos>>id) {
			activos.ignore();
			getline(activos, nombre);
			activos>>anios;
			insertarOrdenado(listaActivos, id, nombre, anios);
		}
		activos.close();
	}
	
	if (jubilados.fail()) {
		cout<<"Hubo un error al encontrar el archivo jubilados.txt"<<endl<<endl;
	} else {
		while (jubilados>>id) {
			jubilados.ignore();
			getline(jubilados, nombre);
			jubilados>>anios;
			insertarOrdenado(listaJubilados, id, nombre, anios);
		}
		jubilados.close();
	}
}

void transferirAJubilados(Empleado*& listaActivos, Empleado*& listaJubilados, string nombreBuscado) {
	Empleado* actual = listaActivos;
	Empleado* anterior = NULL;
	bool encontrado = false;
	
	while  (actual != NULL && !encontrado) {
		if (actual->nombre == nombreBuscado) {
			encontrado = true;
		} else {
			anterior = actual;
			actual = actual->siguiente;
		}
	}
	
	if (!encontrado) {
		cout<<"Error - Empleado no encontrado en la lista de activos."<<endl;
		return;
	}
	
	if (actual->aniosServicio <= 20) {
		cout<<"Error - El empleado no cumple con la cantidad de anios requerida."<<endl;
		return;
	}
	
	int idTemp = actual->ID;
	int aniosTemp = actual->aniosServicio;
	
	if (actual == listaActivos) {
		listaActivos = actual->siguiente;
	} else {
		anterior->siguiente = actual->siguiente;
	}
	
	delete actual;
	
	insertarOrdenado(listaJubilados, idTemp, nombreBuscado, aniosTemp);
	cout<<"Exito: Empleado "<<nombreBuscado<<" trasnferior a jubilados."<<endl;
}

void mostrarListas(Empleado* listaActivos, Empleado* listaJubilados) {	
	cout<<"Lista de empleados activos: "<<endl;
	if (listaActivos == NULL) {
		cout<<"No hay empleados en la lista de activos."<<endl;
	} else {
		Empleado* aux = listaActivos;
		while (aux != NULL) {
			cout<<"ID: "<<aux->ID<<endl;
			cout<<"Nombre: "<<aux->nombre<<endl;
			cout<<"Años de servicio: "<<aux->aniosServicio<<endl;
			cout<<endl;
			aux = aux->siguiente;
		}
	}

	cout<<"Lista de empleados jubilados: "<<endl;
	if (listaJubilados == NULL) {
		cout<<"No hay empleados en la lista de jubilados."<<endl;
	} else {
		Empleado* aux = listaJubilados;
		while (aux != NULL) {
			cout<<"ID: "<<aux->ID<<endl;
			cout<<"Nombre: "<<aux->nombre<<endl;
			cout<<"Años de servicio: "<<aux->aniosServicio<<endl;
			cout<<endl;
			aux = aux->siguiente;
		}
	}
}

void guardarListas(Empleado* listaActivos, Empleado* listaJubilados) {
	ofstream activos("activos.txt");
	ofstream jubilados("jubilados.txt");
	
	Empleado* aux = listaActivos;
	
	// Recorro los activos y los guardo
	while (aux != NULL) {
		activos<<aux->ID<<endl;
		activos<<aux->nombre<<endl;
		activos<<aux->aniosServicio<<endl;
		aux = aux->siguiente;
	}
	activos.close();
	
	aux = listaJubilados;
	// Recorro los jubilados y los guardo
	while (aux != NULL) {
		jubilados<<aux->ID<<endl;
		jubilados<<aux->nombre<<endl;
		jubilados<<aux->aniosServicio<<endl;
		aux = aux->siguiente;
	}
	
	jubilados.close();
}

void liberarListas(Empleado*& lista) {
	Empleado* aux;
	
	while (lista != NULL) {
		aux = lista;
		lista = lista->siguiente;
		delete aux;
	}
}

void menu() {
	cout<<"1. Agregar empleado a la lista de activos."<<endl;
	cout<<"2. Transferir empleado a la lista de jubilados."<<endl;
	cout<<"3. Mostrar listas de empleados."<<endl;
	cout<<"4. Guardar listas"<<endl;
	cout<<"S. Salir"<<endl;
}

int main(int argc, char *argv[]) {
	Empleado *listaActivos = NULL;
	Empleado *listaJubilados = NULL;
	
	char option;
	string nombre;
	int id, anios;
	
	cargarDesdeArchivo(listaActivos, listaJubilados);
	
	do {
		menu();
		cout<<"Ingrese una opción: ";
		cin>>option;
		
		switch (tolower(option)) {
			case '1':
				do {
					cout<<"Ingrese el ID del empleado: ";
					cin>>id;
					if (id < 0) cout<<"El ID no puede ser negativo. Reingrese."<<endl;
				} while(id < 0);
				cout<<"Ingrese el nombre del empleado: ";
				cin.ignore();
				getline(cin, nombre);
				cout<<"Ingrese los años de servicio: ";
				cin>>anios;
				insertarOrdenado(listaActivos, id, nombre, anios);
				break;
			case '2':
				cout<<"Ingrese el nombre del empleado: ";
				cin.ignore();
				getline(cin, nombre);
				transferirAJubilados(listaActivos, listaJubilados, nombre);
				break;
			case '3':
				mostrarListas(listaActivos, listaJubilados);
				break;
			case '4':
				guardarListas(listaActivos, listaJubilados);
				break;
			case 's':
				cout<<"Liberando memoria y saliendo..."<<endl;
				liberarListas(listaActivos);
				liberarListas(listaJubilados);
				break;
		default:
			cout<<"La opción ingresada no es valida. Reingrese."<<endl;
		}
	} while(tolower(option) != 's');
	
	return 0;
}

