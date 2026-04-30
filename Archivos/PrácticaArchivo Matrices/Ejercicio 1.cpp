#include <iostream>
#include <fstream>
#define N 3
#define M 2
using namespace std;

void ARCHIVO (int matriz[][M], int numeroColumna);

int main(int argc, char *argv[]) {
	
	int matriz[N][M], numeroColumna;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<"Ingrese el elemento de la matriz ["<<i+1<<"]["<<j+1<<"]:"<<endl;;
			cin>>matriz[i][j];
		}
	}
	
	do {
		cout<<"Ingrese un número de columna para trabajar sabiendo que la cantidad de columnas son "<<M<<":"<<endl;
		cin>>numeroColumna;
		if (numeroColumna <= 0 or numeroColumna > M) {
			cout<<"Numero de columna inválido. Reingresar"<<endl;
		}
	} while(numeroColumna < 1 or numeroColumna > M);
	
	ARCHIVO (matriz, numeroColumna);
	return 0;
}

void ARCHIVO (int matriz[][M], int numeroColumna) {
	cout<<"\n";
	
	ofstream archivo;
	
	archivo.open("columna.txt");
	
	if (archivo.fail()) {
		cout<<"Ha habido un error al crear el archivo..."<<endl;
		exit(1);
	}
	
	for (int i = 0; i < N; i++) { 
		archivo<<matriz[i][numeroColumna-1]<<endl; 
	}
	
	archivo.close();
	
	ifstream archivoMostrar;
	
	string contenido;
	
	archivoMostrar.open("columna.txt");
	
	if (archivoMostrar.fail()) {
		cout<<"Ha habido un error al abrir el archivo..."<<endl;
		exit(1);
	}
	
	while(!archivoMostrar.eof()) {
		getline(archivoMostrar, contenido);
		int tamano = contenido.size();
		for (int i = 0; i < tamano; i++) {
			cout<<contenido[i]<<endl;
		}
	}
}

