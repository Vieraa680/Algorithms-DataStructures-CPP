#include <iostream>
#define N 3
#define M 2
using namespace std;

int vectorA[N];

void esParOImpar(int nro);

void potenciarNumero (int nro2);

void cargarVectorB(int vector[]);

void mostrarVectorB(int vectorB[]);

void cargarVectorA(int vectorA[]);

void mostrarVectorA(int vectorA[]);

void matrizC(int matrizC[][M]);

int main(int argc, char *argv[]) {
	
	int vectorB[N+1], MatrizC[N][M], nro, nro2;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<"Ingrese el elemento de la matriz ["<<i+1<<"]["<<j+1<<"]:"<<endl;
			cin>>MatrizC[i][j];
		}
	}
	
	cout<<"\nLa matriz cargada es: \n"<<endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<MatrizC[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\nIngrese un número para comprobar si es par o impar:"<<endl;
	cin>>nro;
	
	esParOImpar(nro);
	
	cout<<"\nIngrese un número para elevar al cuadrado y al cubo:"<<endl;
	cin>>nro2;
	
	potenciarNumero (nro2);
	
	cargarVectorB(vectorB);
	
	mostrarVectorB(vectorB);
	
	cargarVectorA(vectorA);
	
	mostrarVectorA(vectorA);
	
	matrizC(MatrizC);
	
	return 0;
}

void esParOImpar(int nro) {
	
	if (nro %2 == 0) {
		cout<<"El número ingresado es par."<<endl;
	} else {
		cout<<"El número ingresado es impar."<<endl;
	}
}

void potenciarNumero (int nro2) {
	
	int cuadrado = nro2 * nro2;
	int cubo = nro2 * nro2 * nro2;
	
	cout<<"El número elevado al cuadrado es: "<<cuadrado<<endl;
	
	cout<<"El número elevado al cubo es: "<<cubo<<endl;
}

void cargarVectorB(int vectorB[]) {
	
	int sumaPares = 0;
	
	for (int i = 0; i < N+1; i++) {
		cout<<"\nIngrese el elemento de la posición "<<i+1<<": "<<endl;
		cin>>vectorB[i];
	}
	
	for (int i = 0; i < N+1; i++) {
		if (vectorB[i] % 2 == 0) {
			sumaPares += vectorB[i];
		}
	}
	
	cout<<"\nLa suma de los elementos pares es: "<<sumaPares<<endl;
}

void mostrarVectorB(int vectorB[]) {
	
	cout<<"Los elementos del vector B son: "<<endl;
	
	for (int i = 0; i < N+1; i++) {
		cout<<vectorB[i]<<" ";
	}
}

void cargarVectorA(int vectorA[]) {
	cout<<"Cargamos el vector A."<<endl;
	
	for(int i = 0; i < N; i++) {
		cout<<"Ingrese el elemento de la posición ["<<i+1<<"]:"<<endl;
		cin>>vectorA[i];
	}
}

void mostrarVectorA(int vectorA[]) {
	
	cout<<"Los elementos del vector A son: "<<endl;
	
	for (int i = 0; i < N; i++) {
		cout<<vectorA[i]<<" ";
	}
}

void matrizC(int matrizC[][M]) {
	cout<<"asd";
}


