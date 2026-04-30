#include <iostream>
using namespace std;

int const F = 3;
int const C = 3;

void cargarMatriz (int matriz[][3], int, int);

void mostrarMinimo (int matriz[][3], int, int);

int main(int argc, char *argv[]) {
	int matriz[F][C];
	
	cargarMatriz(matriz, F, C);
	return 0;
}

void cargarMatriz (int matriz[][3], int F, int C) {
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			cout<<"Cargue el elemento de la posición ["<<i<<"]["<<j<<"]"<<endl;
			cin>>matriz[i][j];
		}
	}
}

void mostrarMinimo (int matriz[][3], int F, int C) {
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			
		}
	}
}

