#include <iostream>
using namespace std;

void cantidadDeDivisores(int nro);

int main(int argc, char *argv[]) {
	
	int nro;
	
	cout<<"Ingrese el número: "<<endl;
	cin>>nro;
	
	cantidadDeDivisores(nro);
	return 0;
}

void cantidadDeDivisores(int nro) {
	int cantidadDeDivisores = 0;
	
	for (int i = 1; i <= nro; i++) {
		if (nro%i == 0) {
			cantidadDeDivisores++;
		}
	}
	cout<<"El número "<<nro<<" tiene "<<cantidadDeDivisores<<" divisores.";
}

