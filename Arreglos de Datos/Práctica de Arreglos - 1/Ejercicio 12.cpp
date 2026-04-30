#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V[10];
	
	cout<<"Ingrese el primer valor del vector: "<<endl;
	cin>>V[0];
	
	for (int i = 1; i < 10; i++) {
		V[i] = V[i-1] * 2;
	}
	
	for (int i = 0; i < 10; i++) {
		cout<<"El elemento de la posición "<<i<<" es: "<<V[i]<<endl;
	}
	return 0;
}

