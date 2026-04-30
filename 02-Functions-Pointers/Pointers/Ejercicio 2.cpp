#include <iostream>
#define N 5
using namespace std;

// 	cout<<"Programa para cargar un vector de N elementos.";

int main(int argc, char *argv[]) {
	float V[N], *Pv, nro, repetido = 0;
	
	
	for (int i = 0; i < N; i++) {
		cout<<"Ingrese el elemento "<<i<<" del vector: "<<endl;
		cin>>V[i];
	}
	
	Pv = V;
	
	cout<<"Ingrese el número que quiere buscar: "<<endl;
	cin>>nro;
	for (int i = 0; i < N; i++) {
		if(*Pv == nro) {
			repetido++;
		}
		Pv++;
	}
	
	if (repetido > 0) { 
		cout <<"El número " <<nro<<" está presente en el vector "<<repetido<<" veces."<<endl;
	} else {
		cout<<"El número "<<nro<<" no está presente en el vector."<<endl;
	}
	return 0;
}

