#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int minutos, horas;
	cout<<"Ingrese los minutos ";
	cin>>minutos; 
	horas = minutos/60;
	cout<<"Corresponde a "<<horas; 
	cout<< " horas";
	minutos = minutos%60;
	cout<<" y a "<<minutos;
	cout<<" minutos";
	return 0;
}

