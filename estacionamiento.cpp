#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int valorEstacionamiento = 300;
	float precioPorPagar;
	float minutos;
	cout<<"Ingrese los minutos que estuvo estacionado ";
	cin>>minutos;
	minutos = minutos / 60;
	round(minutos);
	cout<<"La cantidad de horas que estuvo estacionado fueron ";
	cout<<minutos;
	cout<<"\n";
	if (minutos >= 1) {
		precioPorPagar = valorEstacionamiento * minutos;
		cout<<"El precio a pagar es ";
		cout<<precioPorPagar;
	}
	return 0;
}

