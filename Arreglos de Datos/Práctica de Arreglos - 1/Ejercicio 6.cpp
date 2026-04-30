#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V[10], intervalo1, intervalo2;
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento para la posición "<<i<<endl;
		cin>>V[i];
	}
	
	cout<<"Ingrese el primer intervalo: "<<endl;
	cin>>intervalo1;
	cout<<"Ingrese el segundo intervalo: "<<endl;
	cin>>intervalo2;
	
	for (int i = 0; i < 10; i++) {
		if (V[i] >= intervalo1 && V[i] <= intervalo2) {
			cout<<V[i]<<endl;
		}
	}
	return 0;
}

