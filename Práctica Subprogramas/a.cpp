#include <iostream>
using namespace std;

const int filas = 3;
const int columnas = 3;

void cargarMatriz(int matriz[][3], int, int);

void cuadrado (int matriz[][3], int filas, int columnas);

void mostrarMatriz (int matriz[][3], int, int);

int main(int argc, char *argv[]) {
	int matriz[filas][columnas];
	
	cargarMatriz(matriz, filas, columnas);
	cuadrado(matriz, filas, columnas);
	mostrarMatriz(matriz, filas, columnas);
	return 0;
}

void cargarMatriz(int matriz[][3], int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout<<"Coloque el elemento de la posición ["<<i<<"]["<<j<<"]"<<endl;
			cin>>matriz[i][j];
		}
	}
}

void cuadrado (int matriz[][3], int filas, int columas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columas; j++) {
			matriz[i][j] = matriz[i][j] * matriz[i][j];
		}
	}
}

void mostrarMatriz (int matriz[][3], int filas, int columas) {
	cout<<"El resultado de elevar al cuadrado cada elemento de la matriz es: "<<endl;
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}

