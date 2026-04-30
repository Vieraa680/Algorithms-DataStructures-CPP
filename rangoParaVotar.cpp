#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad;
	cout<<"Ingrese su edad para saber si puede votar \n";
	cin>>edad;
	if(edad >= 16)
		cout<<"Tu edad está en el rango válido para votar";
	else 
		cout<<"Tu edad no está en el rango válido para votar";
	return 0;
}

