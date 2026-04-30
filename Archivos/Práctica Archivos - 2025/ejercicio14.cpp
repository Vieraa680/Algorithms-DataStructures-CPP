#include <iostream>
#include <fstream>
using namespace std;

struct Libro {
	string ISBN;
	string titulo;
	string autor;
	string estado;
	int DNI = 0;
	Libro* siguiente;
};

void menu() {
	cout<<"1. Registrar libro"<<endl;
	cout<<"2. Prestar libro"<<endl;
	cout<<"3. Devolver libro"<<endl;
	cout<<"4. Enviar a reparación"<<endl;
	cout<<"5. Listar libros"<<endl;
	cout<<"6. Guardar y salir."<<endl;
}

void registrarLibro(Libro*& lista, string ISBN, string titulo, string autor, string estado, int DNI = -1) {
	Libro* nuevo_nodo = new Libro();
	
	nuevo_nodo->ISBN = ISBN;
	nuevo_nodo->titulo = titulo;
	nuevo_nodo->autor = autor;
	nuevo_nodo->estado = estado;
	if (DNI != -1) nuevo_nodo->DNI = DNI;
	nuevo_nodo->siguiente = NULL;
	
	if (lista == NULL || titulo < lista->titulo) {
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
		cout<<"--- Libro agregado correctamente al inicio de la lista ---"<<endl<<endl;
	} else {
		Libro* aux = lista;
		
		while (aux->siguiente != NULL && (aux->siguiente->titulo < titulo)) {
			aux = aux->siguiente;
		}
		nuevo_nodo->siguiente = aux->siguiente;
		aux->siguiente = nuevo_nodo;
		cout<<"--- Libro ordenado alfabeticamente ---"<<endl<<endl;
	}
}

bool existeISBN(Libro* lista, string ISBN) {
	Libro* aux = lista;
	
	while (aux != NULL) {
		if (aux->ISBN == ISBN) return true;
		aux = aux->siguiente;
	}
	return false;
}

void prestarLibro(Libro*& lista, string ISBN, int DNI) {
	Libro* aux = lista;
	bool encontrado = false, prestar = false;
	
	while (aux != NULL) {
		if (aux->ISBN == ISBN) {
			if (aux->estado == "Disponible") {
				aux->estado = "Prestado";
				aux->DNI = DNI;
				cout<<"--- Libro prestado con éxito ---"<<endl<<endl;
			} else {
				cout<<"El libro está "<<aux->estado<<", no se puede prestar."<<endl<<endl;
			}
			return;
		}
		aux = aux->siguiente;
	}
	
	cout<<"--- El libro no fue encontrado ---"<<endl<<endl;
}

void devolverLibro(Libro*& lista, string ISBN) {
	Libro* aux = lista;
	bool encontrado = false;
	
	while (aux != NULL) {
		if (aux->ISBN == ISBN) encontrado = true;
		aux = aux->siguiente;
	}
	
	if (encontrado) {
		aux->estado = "Disponible";
		aux->DNI = 0;
		cout<<"--- Libro devuelto con éxito ---"<<endl<<endl;
	} else {
		cout<<"-- No se encontró el libro con el ISBN "<<ISBN<<" ---"<<endl<<endl;
	}
}

void enviarAReparacion(Libro*& lista, string ISBN) {
	Libro* aux = lista;
	bool encontrado = false, disponible = false;
	
	while (aux != NULL) {
		if (aux->ISBN == ISBN) encontrado = true;
			if (aux->estado == "Disponible") disponible = true;
		
		aux = aux->siguiente;
	}
	
	if (encontrado) {
		if (disponible) {
			aux->estado = "En reparación";
			cout<<"--- El libro fue enviado correctamente a reparación ---"<<endl<<endl;
		} else {
			cout<<"--- El libro fué encontrado pero no estaba disponible para su reparación ---"<<endl<<endl;
		}
	} else {
		cout<<"--- El libro no fue encontrado ---"<<endl<<endl;
	}
}

void listarLibros(Libro* lista, bool disponibles = false, bool prestados = false) {
	Libro* aux = lista;
	
	while (aux != NULL) {
		bool mostrar = false;
		
		if (!disponibles && !prestados) {
			mostrar = true;
		} else if (disponibles && aux->estado == "Disponible") {
			mostrar = true;
		} else if (prestados && aux->estado == "Prestado") {
			mostrar = true;
		}
		
		if (mostrar) {
			cout<<"ISBN: "<<aux->ISBN<<endl;
			cout<<"Título: "<<aux->titulo<<endl;
			cout<<"Autor: "<<aux->autor<<endl;
			cout<<"Estado: "<<aux->estado<<endl;
			if (aux->estado == "Prestado") cout<<"Prestado al DNI: "<<aux->DNI<<endl;
		}
		aux = aux->siguiente;
	}
}

void guardarArchivo(Libro* lista) {
	Libro* aux = lista;
	ofstream archivo("libros.txt");
	
	while (aux != NULL) {
		archivo<<"ISBN: "<<aux->ISBN<<endl;
		archivo<<"Título: "<<aux->titulo<<endl;
		archivo<<"Autor: "<<aux->autor<<endl;
		archivo<<"Estado: "<<aux->estado<<endl;
		if (aux->estado == "Prestado") archivo<<"Prestado al DNI: "<<aux->DNI<<endl;
		aux = aux->siguiente;
	}
	
	archivo.close();
	
	cout<<"--- Archivo creado con éxito ---"<<endl<<endl;
}

void liberarLista(Libro*& lista) {
	Libro* aux;
	
	while (lista != NULL) {
		aux = lista;
		lista = lista->siguiente;
		delete aux;
	}
}

int main(int argc, char *argv[]) {
	Libro* lista = NULL;
	
	char option;
	string ISBN, titulo, autor, estado;
	int DNI = 0;
	
	do {
		menu();
		
		cout<<"Ingrese una opción del menú: ";
		cin>>option;
		
		switch (option) {
		case '1':
			char estadoLibro;
			
			cout<<endl;
			do {
				cout<<"Ingrese el ISBN del libro: ";
				cin.ignore();
				getline(cin, ISBN);
				
				if (existeISBN(lista, ISBN)) cout<<"El ISBN ingresado ya existe. Reingrese."<<endl;
			} while(existeISBN(lista, ISBN));
			
			cout<<"Ingrese el título del libro: ";
			cin.ignore();
			getline(cin, titulo);
			
			cout<<"Ingrese el autor del libro: ";
			cin.ignore();
			getline(cin, autor);
			
			do {
				cout<<"Ingrese el estado del libro (1-Disponible, 2-Prestado, 3-En reparación): ";
				cin>>estadoLibro;
				
				switch (estadoLibro) {
				case '1':
					estado = "Disponible";
					break;
				case '2':
					estado = "Prestado";
					do {
						cout<<"Ingrese el DNI de la persona: ";
						cin>>DNI;
						
						if (DNI < 0) cout<<"El DNI no puede ser negativo. Reingrese."<<endl;
					} while(DNI < 0);
					break;
				case '3':
					estado = "En reparación";
					break;
				}
			} while(estadoLibro != '1' && estadoLibro != '2' && estadoLibro != '3');
			
			if (estado == "Prestado") {
				registrarLibro(lista, ISBN, titulo, autor, estado, DNI);
			} else {
				registrarLibro(lista, ISBN, titulo, autor, estado);
			}
			break;
		case '2':
			if (lista == NULL) {
				cout<<"Primero debe cargar la lista. Reintente."<<endl<<endl;
			} else {
				cout<<"Ingrese el ISBN del libro: ";
				cin.ignore();
				getline(cin, ISBN);
				
				do {
					cout<<"Ingrese el DNI de la persona: ";
					cin>>DNI;
					
					if (DNI < 0) cout<<"El DNI no puede ser negativo. Reingrese."<<endl;
				} while(DNI < 0);
				
				prestarLibro(lista, ISBN, DNI);
			}
			break;
		case '3':
			if (lista == NULL) {
				cout<<"Primero debe cargar la lista. Reintente."<<endl<<endl;
			} else {
				cout<<"Ingrese el ISBN del libro a devolver: ";
				cin.ignore();
				getline(cin, ISBN);
				
				devolverLibro(lista, ISBN);
			}
			break;
		case '4':
			if (lista == NULL) {
				cout<<"Primero debe cargar la lista. Reintente."<<endl<<endl;
			} else {
				cout<<"Ingrese el ISBN del libro a reparar: ";
				cin.ignore();
				getline(cin, ISBN);
				
				enviarAReparacion(lista, ISBN);
			}
			break;
		case '5':
			if (lista == NULL) {
				cout<<"Primero debe cargar la lista. Reintente."<<endl<<endl;
			} else {
				char subOption;
				
				do {
					cout<<"1. Todos"<<endl;
					cout<<"2. Solo Disponibles"<<endl;
					cout<<"3. Prestados"<<endl;
					
					cout<<"Ingrese una opción del menú: ";
					cin>>subOption;
					
					switch (subOption) {
					case '1':
						listarLibros(lista);
						break;
					case '2':
						listarLibros(lista, true);
						break;
					case '3':
						listarLibros(lista, false, true);
						break;
					default:
						cout<<"La opción ingresada no es válida. Reingrese."<<endl;
					}
				} while(subOption != '1' && subOption != '2' && subOption != '3');
			}
			break;
		case '6':
			if (lista == NULL) {
				cout<<"Saliendo..."<<endl;
			} else {
				guardarArchivo(lista);
				liberarLista(lista);
				cout<<"Saliendo...."<<endl;
			}
			break;
		default:
			cout<<"La opción ingresada no es válida. Reingrese."<<endl;
		}
	} while(option != '6');
	return 0;
}

