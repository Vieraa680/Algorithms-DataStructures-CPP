#include <iostream>
#define N 5
using namespace std;

void cargaDatos(int V[N]);

void cambiarSignos(int V[N]);

void mostrarDatos(int V[N]);

int V[N];

int main(int argc, char *argv[]) {
	cargaDatos(V);
	cambiarSignos(V);
	mostrarDatos(V);
	return 0;
}

void cargaDatos (int V[N]) {
	for (int i = 0; i < N; i++) {
		cout<<"Ingrese el valor de la posición "<<i<<": "<<endl;
		cin>>V[i];
	}
}

void cambiarSignos(int V[N]) {
	for (int i = 0; i < N; i++) {
		if (V[i] > 0) {
			V[i] = V[i] * -1;
		} else {
			V[i] = V[i] * -1;
		}
	}
}

void mostrarDatos (int V[N]) {
	
	for (int i = 0; i < N; i++) {
		cout<<"El valor de la posición "<<i<<" es: "<<V[i]<<endl;
}
}

