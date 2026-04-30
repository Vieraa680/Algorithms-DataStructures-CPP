#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V[10];
	bool ascendente = true;
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento de la posicion "<<i<<endl;
		cin>>V[i];
	}
	
	for (int i = 1; i < 10; i++) {
		if (V[i] < V[i-1]) {
			ascendente = false;
		}
	}
	
	if (ascendente) {
		cout<<"El vector es ascendente."<<endl;
	} else {
		cout<<"El vector no es ascendente."<<endl;
	}
	return 0;
}

