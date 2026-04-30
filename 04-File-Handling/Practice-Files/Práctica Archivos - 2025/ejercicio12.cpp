#include <iostream>
#include <fstream>
using namespace std;

struct Tarea {
	int ID;
	string descripcion;
	string desarrollador;
	int prioridad;
	string estado;
	int limite;
	Tarea* siguiente;
};

void menu() {
	cout<<"1. Agregar tarea"<<endl;
	cout<<"2. Modificar estado de tarea"<<endl;
	cout<<"3. Reasignar tarea"<<endl;
	cout<<"4. Eliminar tarea completada"<<endl;
	cout<<"5. Listar tarea"<<endl;
	cout<<"6. Buscar tarea"<<endl;
	cout<<"7. Guardar tareas en archivo"<<endl;
	cout<<"8. Salir"<<endl;
}

bool existeID(Tarea* lista, int id) {
	Tarea* aux = lista;
	while (aux != NULL) {
		if (aux->ID == id) {
			return true;
		}
		aux = aux->siguiente;
	}
	return false;
}

void insertarTarea(Tarea*& lista, int id, string descrip, string dev, int prio, string estado, int lim) {
	Tarea* nuevo_nodo = new Tarea();
	
	nuevo_nodo->ID = id;
	nuevo_nodo->descripcion = descrip;
	nuevo_nodo->desarrollador = dev;
	nuevo_nodo->prioridad = prio;
	nuevo_nodo->estado = estado;
	nuevo_nodo->limite = lim;
	
	if (lista == NULL || (prio < lista->prioridad) || (prio == lista->prioridad && lim < lista->limite)) {
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
	} else {
		Tarea* aux = lista;
		while (aux->siguiente != NULL &&
			  (aux->siguiente->prioridad < prio ||
			   (aux->siguiente->prioridad == prio && aux->siguiente->limite <= lim))) {

			aux = aux->siguiente;
		}
		nuevo_nodo->siguiente = aux->siguiente;
		aux->siguiente = nuevo_nodo;
	}
	cout<<"--- Tarea agregada correctamente ---"<<endl<<endl;
}

void actualizarEstado(Tarea*& lista, int id, string estado) {
	Tarea* aux = lista;
	bool encontrado = false;
	
	while (aux != NULL) {
		if (aux->ID == id) {
			encontrado = true;
			break;
		}
		aux = aux->siguiente;
	}
	
	if (encontrado) {
		aux->estado = estado;
	}
	
	cout<<"--- Estado cambiado correctamente ---"<<endl<<endl;
}

void reasignarTarea(Tarea*& lista, int id, string dev) {
	Tarea* aux = lista;
	bool encontrado = false;
	
	while (aux != NULL) {
		if (aux->ID == id) {
			encontrado = true;
			break;
		}
		aux = aux->siguiente;
	}
	
	if (encontrado) {
		aux->desarrollador = dev;
	}
	
	cout<<"--- Desarrollador cambiado correctamente ---"<<endl<<endl;
}

void eliminarCompletadas(Tarea*& lista) {
	Tarea* actual = lista;
	Tarea* anterior = NULL;
	
	bool huboEliminados = false;
	
	while (actual != NULL) {
		if (actual->estado == "Completada") {
			Tarea* aBorrar = actual;
			
			if (anterior == NULL) {
				lista = actual->siguiente;
				actual = lista;
			} else {
				anterior->siguiente = actual->siguiente;
				actual = actual->siguiente;
			}
			
			delete aBorrar;
			huboEliminados = true;
		} else {
			anterior = actual;
			actual = actual->siguiente;	
		}
	}
	
	if (huboEliminados) {
		cout<<"--- Tareas completadas eliminadas correctamente ---"<<endl<<endl;
	} else {
		cout<<"--- No había tareas completadas para eliminar ---"<<endl<<endl;
	}
}

void listarTareas(Tarea* lista, string dev = "", string estado = "") {
	Tarea* aux = lista;
	
		while (aux != NULL) {
			bool mostrar = false;
			
			if (dev == "" && estado == "") {
				mostrar = true;
			} else if (dev != "" && aux->desarrollador == dev) {
				mostrar = true;
			} else if (estado != "" && aux->estado == estado) {
				mostrar = true;
			}
			
			if (mostrar) {
				cout<<"ID de tarea: "<<aux->ID<<endl;
				cout<<"Descripción: "<<aux->descripcion<<endl;
				cout<<"Desarrollador asignado: "<<aux->desarrollador<<endl;
				cout<<"Prioridad: "<<aux->prioridad;
				if (aux->prioridad == 1) cout<<" (Alta)"<<endl;
				if (aux->prioridad == 2) cout<<" (Media)"<<endl;
				if (aux->prioridad == 3) cout<<" (Baja)"<<endl;
				cout<<"Estado: "<<aux->estado<<endl;
				cout<<"Tiempo límite: "<<aux->limite;
				aux = aux->siguiente;
			}
		}
}

void buscarTarea(Tarea* lista, int id = -1, string descripcion = "") {
	Tarea* aux = lista;
	
	while (aux != NULL) {
		bool coincidencia = false;
		
		if (id != -1 && aux->ID == id) {
			coincidencia = true;
		} else if (descripcion != "" && aux->descripcion == descripcion) {
			coincidencia = true;
		}
		
		if (coincidencia) {
			cout<<"ID de tarea: "<<aux->ID<<endl;
			cout<<"Descripción: "<<aux->descripcion<<endl;
			cout<<"Desarrollador asignado: "<<aux->desarrollador<<endl;
			cout<<"Prioridad: "<<aux->prioridad;
			if (aux->prioridad == 1) cout<<" (Alta)"<<endl;
			if (aux->prioridad == 2) cout<<" (Media)"<<endl;
			if (aux->prioridad == 3) cout<<" (Baja)"<<endl;
			cout<<"Estado: "<<aux->estado<<endl;
			cout<<"Tiempo límite: "<<aux->limite;
		}
		aux = aux->siguiente;
	}
}

int main(int argc, char *argv[]) {
	Tarea* lista = NULL;
	char option;
	int ID, limite, prioridad, estado;
	string descripcion, desarrollador;
	
	do {
		menu();
		cout<<"Ingrese una opción del menú: ";
		cin>>option;
		
		switch (option) {
			case '1': {
				string status;
				do {
					cout<<"Ingrese el ID: ";
					cin>>ID;
					if (ID < 0) {
						cout<<"El ID no puede ser negativo. Reingrese."<<endl;
					} else if (existeID(lista, ID)) {
						cout<<"El ID ingresado ya existe. Reingrese."<<endl;
					}
				} while(ID < 0 || existeID(lista, ID));
				cout<<"Ingrese la descripción: ";
				cin.ignore();
				getline(cin, descripcion);
				cout<<"Ingrese el desarrollador: ";
				getline(cin, desarrollador);
				
				do {
					cout<<"Ingrese la prioridad: (1: Alta, 2: Media, 3: Baja): ";
					cin>>prioridad;
				} while(prioridad < 1 || prioridad > 3);
				
				do {
					cout<<"Tipos de estados:"<<endl;
					cout<<"1. Pendiente"<<endl;
					cout<<"2. En progreso"<<endl;
					cout<<"3. Completada"<<endl;
					cout<<"Ingrese el estado: ";
					cin>>estado;
					
					switch (estado) {
						case 1:
							status = "Pendiente";
							break;
						case 2:
							status = "En progreso";
							break;
						case 3:
							status = "Completada";
							break;
					default:
						cout<<"El estado ingresado no es válido. Reingrese."<<endl;
					}
				} while(estado < 1 || estado > 3);
				
				do {
					cout<<"Ingrese el tiempo límite (en días): ";
					cin>>limite;
					
					if (limite < 1) cout<<"El límite ingresado no puede ser menor a 1. Reingrese."<<endl;
				} while(limite < 1);
				
				// Llamo a la función con todos los parámetros
				insertarTarea(lista, ID, descripcion, desarrollador, prioridad, status, limite);
				break;
			}
			case '2': {
				if (lista == NULL) {
					cout<<"Primero debe cargar elementos en su lista."<<endl;
				} else {
					string status;
					
					do {
						cout<<"Ingrese el ID: ";
						cin>>ID;
						if (ID < 0) {
							cout<<"El ID no puede ser negativo. Reingrese."<<endl;
						} else if (!existeID(lista, ID)) {
							cout<<"El ID ingresado no existe. Reingrese."<<endl;
						}
					} while(ID < 0 || !existeID(lista, ID));
					
					do {
						cout<<"Tipos de estados:"<<endl;
						cout<<"1. Pendiente"<<endl;
						cout<<"2. En progreso"<<endl;
						cout<<"3. Completada"<<endl;
						cout<<"Ingrese el nuevo estado para la tarea: ";
						cin>>estado;
						
						switch (estado) {
						case 1:
							status = "Pendiente";
							break;
						case 2:
							status = "En progreso";
							break;
						case 3:
							status = "Completada";
							break;
						default:
							cout<<"El estado ingresado no es válido. Reingrese."<<endl;
						}
					} while(estado < 1 || estado > 3);
					
					actualizarEstado(lista, ID, status);
				}
				break;
			}
			case '3':
				if (lista == NULL) {
					cout<<"Primero debe cargar elementos en su lista."<<endl;
				} else {
					do {
						cout<<"Ingrese el ID: ";
						cin>>ID;
						if (ID < 0) {
							cout<<"El ID no puede ser negativo. Reingrese."<<endl;
						} else if (!existeID(lista, ID)) {
							cout<<"El ID ingresado no existe. Reingrese."<<endl;
						}
					} while(ID < 0 || !existeID(lista, ID));
					cout<<"Ingrese el nuevo desarrollador: ";
					cin.ignore();
					getline(cin, desarrollador);
					
					reasignarTarea(lista, ID, desarrollador);
				}
				break;
			case '4':
				if (lista == NULL) {
					cout<<"Primero debe cargar elementos en su lista."<<endl;
				} else {
					eliminarCompletadas(lista);
				}
			case '5': {
					if (lista == NULL) {
						cout<<"Primero debe cargar elementos en su lista."<<endl;
					} else {
						int subOption;
						string status;
						
						do {
							cout<<"1. Ver todas"<<endl;
							cout<<"2. Filtrar por desarrollador"<<endl;
							cout<<"3. Filtrar por estado"<<endl;
							
							cout<<"Ingrese una opción del menú: ";
							cin>>subOption;
							
							switch (subOption) {
							case 1:
								listarTareas(lista);
								break;
							case 2:
								cout<<"Ingrese el nombre del desarrollador: ";
								cin.ignore();
								getline(cin, desarrollador);
								listarTareas(lista, desarrollador);
								break;
							case 3:
								do {
									cout<<"Tipos de estados:"<<endl;
									cout<<"1. Pendiente"<<endl;
									cout<<"2. En progreso"<<endl;
									cout<<"3. Completada"<<endl;
									cout<<"Ingrese el nuevo estado para la tarea: ";
									cin>>estado;
									
									switch (estado) {
									case 1:
										status = "Pendiente";
										break;
									case 2:
										status = "En progreso";
										break;
									case 3:
										status = "Completada";
										break;
									default:
										cout<<"El estado ingresado no es válido. Reingrese."<<endl;
									}
								} while(estado < 1 || estado > 3);
								listarTareas(lista, "", status);
								break;
							default: 
								cout<<"La opción ingresada no es válida. Reingrese."<<endl;
							}
						} while(subOption < 1 || subOption > 3);
					}
				break;
			}
			case '6': {
				int subOption;
				
				do {
					cout<<"1. Buscar por ID"<<endl;
					cout<<"2. Buscar por descripcion (Exacta)"<<endl;
					
					cout<<"Ingrese una opción: ";
					cin>>subOption;
					
					switch (subOption) {
						case 1:
							cout<<"Ingrese el ID de la tarea a buscar: ";
							cin>>ID;
							buscarTarea(lista, ID);
							break;
						case 2:
							cout<<"Ingrese la descripcion de la tarea a buscar: ";
							cin.ignore();
							getline(cin, descripcion);
							buscarTarea(lista, int(""), descripcion);
							break;
					default:
						cout<<"La opción ingresada no es válida. Reingrese."<<endl;
					}
				} while(subOption < 1 || subOption > 2);
			}
				break;
			case '7':
			case '8':
			default:
				cout<<"La opción ingresada no es válida. Reingrese."<<endl;
		}
	} while(option != '8');
	
	return 0;
}

