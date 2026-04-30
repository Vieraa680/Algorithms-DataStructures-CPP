#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V[10], buscador,  repetidos = 0;
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento numero "<<i+1<<endl;
		cin>>V[i];
	}
	
	cout<<"Ahora ponga el numero a buscar dentro del vector: "<<endl;
	cin>>buscador;
	
	for (int i = 0; i < 10; i++) {
		if (V[i] == buscador) {
			cout<<"El numero se encuentra repetido en la posicion "<<i<<endl;
			repetidos++;
		}
	}
	cout<<"El numero se encontró repetido "<<repetidos<<" veces.";
	return 0;
}

