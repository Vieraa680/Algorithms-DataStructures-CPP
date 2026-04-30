#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int A[10], valor, suma = 0;
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento de la posicion "<<i<<endl;
		cin>>A[i];
	}
	
	do {
		cout<<"Ingrese un valor entre 0 y 9."<<endl;
		cin>>valor;
	} while(valor < 0 or valor > 9);
	
	switch (valor) {
	case 0: 
		suma = A[0] + A[1];
		cout<<"La suma es: "<<suma;
			break;
	case 1: 
		suma = A[0] + A[1] + A[2];
		cout<<"La suma es: "<<suma;
		break;
	case 2: 
		suma = A[1] + A[2] + A[3];
		cout<<"La suma es: "<<suma;
		break;
	case 3: 
		suma = A[2] + A[3] + A[4];
		cout<<"La suma es: "<<suma;
		break;
	case 4:
		suma = A[3] + A[4] + A[5];
		cout<<"La suma es: "<<suma;
		break;
	case 5: 
		suma = A[4] + A[5] + A[6];
		cout<<"La suma es: "<<suma;
		break;
	case 6:
		suma = A[5] + A[6] + A[7];
		cout<<"La suma es: "<<suma;
		break;
	case 7:
		suma = A[6] + A[7] + A[8];
		cout<<"La suma es: "<<suma;
		break;
	case 8:
		suma = A[7] + A[8] + A[9];
		cout<<"La suma es: "<<suma;
		break;
	case 9:
		suma = A[8] + A[9];
		cout<<"La suma es: "<<suma;
		break;
	
	};
	return 0;
}

