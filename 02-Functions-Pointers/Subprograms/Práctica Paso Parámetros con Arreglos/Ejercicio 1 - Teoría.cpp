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

void cargaDatos(int V[N]) {
	for (int i = 0; i < N; i++) {
		cout<<"Ingrese el valor de la posición "<<i<<": "<<endl;
		cin>>V[i];
	}
}

void mostrarDatos(int V[N]){
	int result = 0;
	
	for (int i = 0; i < N; i++) {
		result += V[i];
	}
	cout<<"El resultado total de la suma de los elementos es: "<<result<<endl;
}

