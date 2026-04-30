#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int anio;
	cout<<"Ingrese el año ";
	cin>>anio;
	if (anio%4 == 0 && anio%100 != 0 && anio%400 == 0 ) { 
		cout<<"El año es bisiesto ";
	} else { 
		cout<<"El año no es bisiesto"; }
	return 0;
}

