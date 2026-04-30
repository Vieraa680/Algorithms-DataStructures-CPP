#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float costo, descuento, costoFinal;
	cout<<"Ingrese el precio del producto \n";
	cin>>costo;
	if (costo >= 200) 
		descuento = (costo * 0.15);
	else if (costo > 100 && costo < 200)
		descuento = costo * 0.12;
	else if (costo <= 100)
		descuento = costo * 0.1;
	costoFinal = costo - descuento;
	cout<<"Se aplicó un descuento de: $"<<descuento<<endl;
	cout<<"El precio del producto final sería de: $"<<costoFinal;
	return 0;
}

