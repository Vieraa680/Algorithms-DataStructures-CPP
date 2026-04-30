#include <iostream>
using namespace std;

struct nodo {
	int dato;
	nodo* siguiente;
};

void contarElementosLista(nodo* lista);

bool insertarNodo(nodo *&, int);

int main(int argc, char *argv[]) {
	nodo *lista = NULL;
	int dato;
	
	
	do {
		cout<<"Ingrese el dato (ingrese 0 para cancelar): "<<endl;
		cin>>dato;
	if(insertarNodo(lista, dato)) {
		cout<<"Se insertó con exito "<<dato<<" en la lista."<<endl;
	} else {
		cout<<"Hubo un error, su dato no pudo insertarse."<<endl;
	}
	}while(dato != 0);
	
	contarElementosLista(lista);
	return 0;
}

bool insertarNodo(nodo *& lista, int dt) {
	bool out = false;
	
	if (lista == NULL) {
		lista = new nodo;
		if (lista != NULL) {
			lista -> dato = dt;
			lista -> siguiente = NULL;
			out = true;
		}
	} else {
		nodo * where = lista;
		while (where -> siguiente != NULL) {
			where = where -> siguiente;
		}
		nodo * tmp = new nodo;
		if (tmp != NULL) {
			tmp -> dato = dt;
			tmp -> siguiente = NULL;
			where -> siguiente = tmp;
			out = true;
		}
	}
	return(out);
}
void contarElementosLista(nodo* lista) {
	int contador = 0;

	while (lista != NULL) {
		contador++;
		lista = lista -> siguiente;
	}
	
	cout<<"La lista tiene "<<contador<<" elementos.";
}

