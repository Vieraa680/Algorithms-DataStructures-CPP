#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int numA;
	int numB;
	cout<<"Ingrese el primer número ";
	cin>>numA;
	cout<<"Ingrse el segundo número ";
	cin>>numB;
	if (numA > numB)
		cout<<"El primer número ingreasdo es mayor al segundo";
	 else 
		if (numA == numB)
			cout<<"El primer número ingreasdo es igual al segundo número";
		 else 
			cout<<"Los números ingresados no son iguales";
		
	return 0;
}

