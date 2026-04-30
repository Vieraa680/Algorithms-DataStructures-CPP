#include <iostream>
#include <fstream>
using namespace std;

struct Inventario {
	string codigo;
	string nombre;
	string categoria;
	float precio;
	int cantidad;
	string proveedor;
	Inventario* siguiente;
};

void menu() {
	cout<<"1. Agregar producto"<<endl;
	cout<<"2. Actualizar Stock"<<endl;
	cout<<"3. Modificar precio"<<endl;
	cout<<"4. Eliminar producto"<<endl;
	cout<<"5. Buscar producto"<<endl;
	cout<<"6. Listar productos"<<endl;
	cout<<"7. Guardar inventario en archivo"<<endl;
	cout<<"8. Salir"<<endl;
}

void agregarProducto(Inventario*& lista, string codigo, string nombre, string categoria, float precio, int cantidad, string proveedor) {
	Inventario* nuevo_nodo = new Inventario();
	
	nuevo_nodo->codigo = codigo;
	nuevo_nodo->nombre = nombre;
	nuevo_nodo->categoria = categoria;
	nuevo_nodo->precio = precio;
	nuevo_nodo->cantidad = cantidad;
	nuevo_nodo->proveedor = proveedor;
	nuevo_nodo->siguiente = NULL;
	
	if (lista == NULL || nombre < lista->nombre){
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
		cout<<"--- Producto agregado correctamente al inicio de la lista ---"<<endl<<endl;
	} else {
		Inventario* aux = lista;
		
		while (aux->siguiente != NULL && aux->siguiente->nombre < nombre) {
			aux = aux->siguiente;
		}
		
		nuevo_nodo->siguiente = aux->siguiente;
		aux->siguiente = nuevo_nodo;
		cout<<"--- Producto ordenado alfabeticamente ---"<<endl<<endl;
	}
}

bool existeCodigo(Inventario* lista, string codigo) {
	Inventario* aux = lista;
	
	while (aux != NULL) {
		if (aux->codigo == codigo) return true;
		aux = aux->siguiente;
	}
	return false;
}

void actualizarStock(Inventario*& lista, string codigo, int stock) {
	Inventario* aux = lista;
	bool encontrado = false;
	
	while (aux != NULL) {
		if (aux->codigo == codigo) encontrado = true;
		aux = aux->siguiente;
	}
	
	if (encontrado) {
		aux->cantidad = stock;
		cout<<"--- La cantidad de stock del producto fue actualizada ---"<<endl<<endl;
	} else {
		cout<<"--- No se encontró ningún producto con el código "<<codigo<<" ---"<<endl<<endl;
	}
}

void modificarPrecio(Inventario*& lista, string codigo, float precio) {
	Inventario* aux = lista;
	bool encontrado = false;
	
	while (aux != NULL) {
		if (aux->codigo == codigo) encontrado = true;
		aux = aux->siguiente;
	}
	
	if (encontrado) {
		aux->precio = precio;
		cout<<"--- El precio del producto fue actualizado ---"<<endl<<endl;
	} else {
		cout<<"--- No se encontró ningún producto con el código "<<codigo<<" ---"<<endl<<endl;
	}
}

void eliminarProducto(Inventario*& lista, string codigo) {
	Inventario* actual = lista;
	Inventario* anterior = NULL;
	bool eliminado = false;
	
	while (actual != NULL) {
		if (actual->codigo == codigo) {
			if (actual->cantidad == 0) {
				Inventario* aBorrar = actual;
				
				if (anterior == NULL) {
					lista = actual->siguiente;
					anterior = lista;
				} else {
					anterior->siguiente = actual->siguiente;
					actual = actual->siguiente;
				}
				
				delete aBorrar;
			}
			eliminado = true;
			break;
		} else {
			anterior = actual;
			actual = actual->siguiente;
		}
	}
	
	if (eliminado) {
		cout<<"--- El producto fue eliminado correctamente ---"<<endl<<endl;
	} else {
		cout<<"--- El producto no fue eliminado porque su stock no era cero ---"<<endl<<endl;
	}
}

void buscarProducto(Inventario* lista, string codigo = "", string nombre = "") {
	Inventario* aux = lista;
	
	while (aux != NULL) {
		bool mostrar = false;
		
		if (codigo != "" && aux->codigo == codigo) {
			mostrar = true;
		} else if (nombre != "" && aux->nombre == nombre) {
			mostrar = true;
		};
		
		if (mostrar) {
			cout<<"Código de producto: "<<aux->codigo<<endl;
			cout<<"Nombre del producto: "<<aux->nombre<<endl;
			cout<<"Categoría: "<<aux->categoria<<endl;
			cout<<"Precio: "<<aux->precio<<endl;
			cout<<"Cantidad en stock: "<<aux->cantidad<<endl;
			cout<<"Proveedor: "<<aux->proveedor<<endl;
		}
		
		aux = aux->siguiente;
	};
}

void listarProductos(Inventario* lista, string categoria = "") {
	Inventario* aux = lista;
	
	while (aux != NULL) {
		bool coincidencia = false;
		
		if (categoria == "") {
			coincidencia = true;
		} else if (categoria != "" && aux->categoria == categoria) {
			coincidencia = true;
		}
		
		if (coincidencia) {
			cout<<"Código de producto: "<<aux->codigo<<endl;
			cout<<"Nombre del producto: "<<aux->nombre<<endl;
			cout<<"Categoría: "<<aux->categoria<<endl;
			cout<<"Precio: "<<aux->precio<<endl;
			cout<<"Cantidad en stock: "<<aux->cantidad<<endl;
			cout<<"Proveedor: "<<aux->proveedor<<endl;
		}
		
		aux = aux->siguiente;
	}
}

void GuardarEnArchivo(Inventario* lista) {
	Inventario* aux = lista;
	ofstream archivo("inventario.txt");
	
	while (aux != NULL) {
		archivo<<"Código de producto: "<<aux->codigo<<endl;
		archivo<<"Nombre del producto: "<<aux->nombre<<endl;
		archivo<<"Categoría: "<<aux->categoria<<endl;
		archivo<<"Precio: "<<aux->precio<<endl;
		archivo<<"Cantidad en stock: "<<aux->cantidad<<endl;
		archivo<<"Proveedor: "<<aux->proveedor<<endl;
		archivo<<endl;
		aux = aux->siguiente;
	}
	
	archivo.close();
	
	cout<<"--- El inventario se guardo en un archivo de texto correctamente ---"<<endl<<endl;
}

void liberarMemoria(Inventario*& lista) {
	Inventario* aux;
	
	while (lista != NULL) {
		aux = lista;
		lista = lista->siguiente;
		delete aux;
	}
}

int main(int argc, char *argv[]) {
	Inventario* lista = NULL;
	
	char option;
	string codigo, nombre, categoria, proveedor;
	float precio;
	int cantidad;
	
	do {
		menu();
		cout<<"Ingrese una opción del menú: ";
		cin>>option;
		
		switch (option) {
			case '1':
				char subOption;
				
				cout<<endl;
				// Ingresar código de producto
				do {
					cout<<"Ingrese el código del producto: ";
					cin.ignore();
					getline(cin, codigo);
					
					if (existeCodigo(lista, codigo)) cout<<"El código ingresado ya existe. Reingrese."<<endl;
				} while(existeCodigo(lista, codigo));
				
				cout<<"Ingrese el nombre del producto: ";
				getline(cin, nombre);
				
				// Seleccionar categoria
				do {
					cout<<"Categorias: "<<endl;
					cout<<"1. Computadoras"<<endl;
					cout<<"2. Smartphones"<<endl;
					cout<<"3. Accesorios"<<endl;
					cout<<"4. Audio"<<endl;
					
					cout<<"Ingrese una categoria: ";
					cin>>subOption;
					
					switch (subOption) {
						case '1':
							categoria = "Computadoras";
							break;
						case '2':
							categoria = "Smartphones";
							break;
						case '3':
							categoria = "Accesorios";
							break;
						case '4':
							categoria = "Audio";
							break;
					default:
						cout<<"La opción ingresada no es válida. Reingrese."<<endl;
					}
				} while(subOption != '1' && subOption != '2' && subOption != '3' && subOption != '4');
				
				// Ingresar precio
				do {
					cout<<"Ingrese el precio del producto: ";
					cin>>precio;
					
					if (precio <= 0) cout<<"El precio debe ser positivo. Reingrese."<<endl;
				} while(precio <= 0);
				
				// Ingresar Stock
				do {
					cout<<"Ingrese la cantidad de stock: ";
					cin>>cantidad;
					
					if (cantidad < 0) cout<<"La cantidad de stock no puede ser negativo. Reingrese."<<endl;
				} while(cantidad < 0);
				
				// Ingresar proveedor
				cout<<"Ingrese el nombre del proveedor: ";
				cin.ignore();
				getline(cin, proveedor);
				
				agregarProducto(lista, codigo, nombre, categoria, precio, cantidad, proveedor);
				break;
			case '2':
				if (lista == NULL) {
					cout<<"La lista se encuentra vacía, primero debe cargarla. Reintente."<<endl<<endl;
				} else {
					cout<<"Ingrese el código de producto: ";
					cin.ignore();
					getline(cin, codigo);
					
					do {
						cout<<"Ingrese la nueva cantidad de stock para el producto: ";
						cin>>cantidad;
						
						if (cantidad < 0) cout<<"La nueva cantidad no puede ser negativa. Reingrese."<<endl;
					} while(cantidad < 0);
					
					actualizarStock(lista, codigo, cantidad);
				}
				break;
			case '3':
				if (lista == NULL) {
					cout<<"La lista se encuentra vacía, primero debe cargarla. Reintente."<<endl<<endl;
				} else {
					cout<<"Ingrese el código de producto: ";
					cin.ignore();
					getline(cin, codigo);
					
					do {
						cout<<"Ingrese el nuevo precio del producto: ";
						cin>>precio;
						
						if (precio < 0) cout<<"El nuevo precio no puede ser negativo. Reingrese."<<endl;
					} while(precio < 0);
					modificarPrecio(lista, codigo, precio);
				}
				break;
			case '4':
				if (lista == NULL) {
					cout<<"La lista se encuentra vacía, primero debe cargarla. Reintente."<<endl<<endl;
				} else {
					cout<<"Ingrese el código de producto: ";
					cin.ignore();
					getline(cin, codigo);
					
					eliminarProducto(lista, codigo);
				}
				break;
			case '5':
				if (lista == NULL) {
					cout<<"La lista se encuentra vacía, primero debe cargarla. Reintente."<<endl<<endl;
				} else {
					char subOption;
					
					do {
						cout<<"1. Buscar por código"<<endl;
						cout<<"2. Buscar por nombre (Exacto)"<<endl;
						cout<<"Ingrese una opción del menú: ";
						cin>>subOption;
						
						switch (subOption) {
							case '1':
								cout<<"Ingrese el código del producto a buscar: ";
								cin.ignore();
								getline(cin, codigo);
								buscarProducto(lista, codigo);
								break;
							case '2':
								cout<<"Ingrese el nombre del producto a buscar: ";
								cin.ignore();
								getline(cin, nombre);
								buscarProducto(lista, "", nombre);
						default:
							cout<<"La opción ingresada no es válida. Reingrese."<<endl;
						}
					} while(subOption != '1' && subOption != '2');
				}
				break;
			case '6':
				if (lista == NULL) {
					cout<<"La lista se encuentra vacía, primero debe cargarla. Reintente."<<endl<<endl;
				} else {
					char subOption;
					
					do {
						cout<<"1. Ver todos"<<endl;
						cout<<"2. Buscar por categoria"<<endl;
						cout<<"Ingrese una opción del menú: ";
						cin>>subOption;
						
						switch (subOption) {
						case '1':
							listarProductos(lista);
							break;
						case '2':
							char categoriasOption;
							
							do {
								cout<<"Categorias: "<<endl;
								cout<<"1. Computadoras"<<endl;
								cout<<"2. Smartphones"<<endl;
								cout<<"3. Accesorios"<<endl;
								cout<<"4. Audio"<<endl;
								
								cout<<"Ingrese una categoria: ";
								cin>>categoriasOption;
								
								switch (categoriasOption) {
								case '1':
									categoria = "Computadoras";
									break;
								case '2':
									categoria = "Smartphones";
									break;
								case '3':
									categoria = "Accesorios";
									break;
								case '4':
									categoria = "Audio";
									break;
								default:
									cout<<"La opción ingresada no es válida. Reingrese."<<endl;
								}
							} while(categoriasOption != '1' && categoriasOption != '2' && categoriasOption != '3' && categoriasOption != '4');
							listarProductos(lista, categoria);
						default:
							cout<<"La opción ingresada no es válida. Reingrese."<<endl;
						}
					} while(subOption != '1' && subOption != '2');
				}
				break;
			case '7':
				GuardarEnArchivo(lista);
				break;
			case '8':
				liberarMemoria(lista);
				cout<<"Saliendo...."<<endl;
		default:
			cout<<"La opción ingresada no es válida. Reingrese."<<endl;
		}
	} while(option != '8');
	return 0;
}

