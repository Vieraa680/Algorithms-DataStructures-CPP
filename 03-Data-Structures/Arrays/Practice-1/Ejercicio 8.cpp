#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int A[10], B[10], C[10];
	
	cout<<"Carguemos los elementos del Vector A: "<<endl;
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento de la posición "<<i<<endl;
		cin>>A[i];
	}
	
	cout<<"Carguemos los elementos del Vector B: "<<endl;
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento de la posición "<<i<<endl;
		cin>>B[i];
	}
	
	cout<<"Los elementos del Vector resultante de sumas A + B es: "<<endl;
	
	for (int i = 0; i < 10; i++) {
		C[i] = A[i] + B[i];
		cout<<C[i]<<endl;
	}
	
	return 0;
}

