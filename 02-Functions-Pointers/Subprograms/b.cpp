#include <iostream>
using namespace std;

const int filas = 3;
const int columnas = 3;

void cargarMatriz(int matriz[][3], int, int);

void comprobarSimetrica(int matriz[][3], int, int);

void mostrarMatriz (int matriz[][3], int, int);

int main(int argc, char *argv[]) {
	
	int matriz[filas][columnas];
	
	cargarMatriz(matriz, filas, columnas);
	
	comprobarSimetrica(matriz, filas, columnas);
	//mostrarMatriz(matriz, filas, columnas);
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

void comprobarSimetrica(int matriz[][3], int filas, int columnas) {
	
	bool simetrica = true;
	
	for(int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] != matriz[i+1][j+1]) {
				simetrica = false;e
			}
		}
	}
	
	if (simetrica = false) {
		cout<<"La matriz es simétrica.";
	} else {
		cout<<"La matriz no es simétrica.";
	}
}



