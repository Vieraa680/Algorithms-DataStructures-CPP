#include <iostream>
#include <cstring>
#define N 20
using namespace std;

int main(int argc, char *argv[]) {
	char frase[N];
	int i, contadorA = 0, contadorB = 0;
	
	cout<<"Ingrese una frase: "<<endl;
	cin.getline(frase, N);
	cout<<"La frase ingresada es: "<<frase<<endl;
	for (i=0; i<N;i++) {
		if (frase[i] == 'a') {
			contadorA++;
		} else if (frase[i] == 'b') {
			contadorB++;
		}
	}
	
	cout<<"La cantidad de letras 'a' ingresadas son: "<<contadorA<<endl;
	cout<<"La cantidad de letras 'b' ingresadas son: "<<contadorB<<endl;
	return 0;
}

