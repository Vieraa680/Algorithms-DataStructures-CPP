#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int sector;
	int entradas, general, preferencial, tribuna, platea, valor = 0;
	cout<<"Bienvenido! Por favor ingrese el número de entradas a solicitar \n";
	cin>>entradas;
	cout<<"Ahora seleccione el sector \n 1 - General= $300 \n 2 - Preferencial = $500\n 3 - Tribuna = $1500 \n 4 - Platea = $2000 \n Ingrese el sector: ";
 	cin>>sector;
	general = 300;
	preferencial = 500;
	tribuna = 1500;
	platea = 2000;
	switch (sector) {
	case 1: 
		valor = general * entradas;
		break;
	case 2: 
		valor = preferencial * entradas;
		break;
	case 3: 
		valor = tribuna * entradas;
		break;
	case 4: 
		valor = platea * entradas;
		break;
	
	default: cout<<"Error al ingresar el sector \n";
	}
	cout<<"El valor de las entradas es: $"<<valor;
	return 0;
}

