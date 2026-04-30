#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float nota;
	
	do {
		cout<<"Ingresar una nota entre 0 y 10 (Si ingresa una nota mal, se volverá a reingresar"<<endl;
		cin>>nota;
	} while(nota < 0 or nota > 10 );
	
		if (nota >= 6 && nota <= 10) {
			cout<<"Aprobado"<<endl;
		} else {
			cout<<"Desaprobado"<<endl;
		}
	return 0;
}

