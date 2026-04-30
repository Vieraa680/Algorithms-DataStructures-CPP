#include <iostream>
#define N 5
using namespace std;

int main(int argc, char *argv[]) {
	
	struct Clientes {
		char nombre[30], estado[10];
		int cantidadProductos;
		float precio;
	}
	cliente[N];
	fflush(stdin);
	for (int i = 0; i < N; i++) {
		cout<<"Ingrese el nombre del cliente "<<i+1<<endl;
		cin.getline(cliente[i].nombre, 30);
		cout<<"Ingrese la cantidad de productos solicitada: "<<endl;
		cin>>cantidadProductos;
		cout<<"Ingrese el estado del cliente ((moroso, pagado): "<<endl;
		cin.getline(cliente[i].estado, 10);
		if (strcmp(cliente[i].estado, ) == 'pagado' or strcmp(cliente[i].estado) == 'Pagado')
	}
	
	if (
	cout<<"Lista de clientes morosos: "<<endl;
	
	for (int i = 0; i < N; i++) {
		
	}
	
	
	return 0;
}

