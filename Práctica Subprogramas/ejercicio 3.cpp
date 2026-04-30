#include <iostream>
using namespace std;

int const F = 7;
const int C = 2;

void cargarMatriz (int matriz[][2], int, int);
void mostrarMenu(int matriz[][2], int F, int C);
void Sorteo(int matriz[][2], int F, int C);
void Buscar(int matriz[][2], int F, int C);
void Buscar2(int matriz[][2], int F, int C);
void Copiar(int matriz[][2], int F, int C);
void Ordena(int vector[], int N);
void Muestra(int matriz[][2], int F, int C);

int main(int argc, char *argv[]) {
	int matriz[F][C];
	
	cargarMatriz(matriz, F, C);
	mostrarMenu(matriz, F, C);
	
	return 0;
}

void cargarMatriz(int matriz[][2], int F, int C) {
	
	for (int i = 0; i < F; i++) {
		cout<<"Ingrese el número ganador de la fila "<<i+1<<":"<<endl;
		cin>>matriz[i][0];
		
		while ((matriz[i][0] < 0) || (matriz[i][0] > 1000)) {
			cout<<"El número ingresado no es válido. Ingrese nuevamente: "<<endl;
			cin>>matriz[i][0];
		}
	}
	
	for (int j = 0; j < F; j++) {
		cout<<"Ingrese el premio correspondiente al número de la fila "<<j+1<<":"<<endl;
		cin>>matriz[0][j];
		
		while ((matriz[0][j] < 1) || (matriz[0][j] > 100000)) {
			cout<<"El premio ingresado no es válido. Ingrese nuevamente: "<<endl;
			cin>>matriz[0][j];
		}
	}
	
	cout<<"La matriz cargada es: "<<endl;
	for (int i = 0; i < F; i++) {
		for (int j = 0; j < C; j++) {
			cout<<matriz[i][j]<<endl;
		}
	}
}

void mostrarMenu(int matriz[][2], int F, int C) {
	int opcion;
	
	do {
		cout<<"1.- Número Sorteado"<<endl;
		cout<<"2.- Buscar premio mayor"<<endl;
		cout<<"3.- Buscar número más sorteado"<<endl;
		cout<<"4.- Copiar columna"<<endl;
		cout<<"5.- Ordenar vector"<<endl;
		cout<<"6. Mostrar arreglos"<<endl;
		cout<<"S.- Salir"<<endl;
		cout<<"Ingrese una opción: ";
		cin>>opcion;
		
		switch (opcion) {
		case 1:
			Sorteo(matriz, F, C);
			break;
		case 2:
			Buscar(matriz, F, C);
			break;
		case 3:
			Buscar2(matriz, F, C);
			break;
		case 4:
			Copiar(matriz, F, C);
			break;
		case 5:
			Ordena(matriz, F, C);
			break;
		case 6:
			Muestra(matriz, F, C);
			break;
		case 'S':
		case 's':
			break;
		default:
			cout<<"Opción incorrecta"<<endl;
		}
	} while (opcion != 'S' && opcion != 's');
}

