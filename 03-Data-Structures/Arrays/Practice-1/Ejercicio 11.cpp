#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int A[10], suma = 0, superan = 0;
	float promedio = 0;
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento de la posición "<<i<<endl;
		cin>>A[i];
		suma += A[i];
	}
	
	promedio = suma / 10;
	
	cout<<"El promedio es: "<<promedio<<endl;
	
	for (int i = 0; i < 10; i++) {
		if (A[i] > promedio) {
		superan++;
		}
	}
	
	cout<<"Hay "<<superan<<" numeros que superan el promedio."<<endl;
	
	return 0;
}

