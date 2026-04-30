#include <iostream>
#define N 5
using namespace std;

void cargaDatos(int V[N]);

void mostrarDatos(int V[N]);

int V[N];

int main(int argc, char *argv[]) {
	cargaDatos(V);
	mostrarDatos(V);
	return 0;
}

void cargaDatos (int V[N]) {
	for (int i = 0; i < N; i++) {
		cout<<"Ingrese el valor de la posición "<<i<<": "<<endl;
		cin>>V[i];
	}
}

void mostrarDatos (int V[N]) {
	bool ordenado = true;
	int aux;
	
	for (int i = 0; i < N; i++) {
			if (V[i] < V[i - 1]) {
				ordenado = false;
				break;
		}
	}
	
	if (ordenado) {
		cout<<"El vector está ordenado."<<endl;
	} else {
		cout<<"El vector no está ordenado."<<endl;
	}
}
