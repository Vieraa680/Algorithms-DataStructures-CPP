#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char cad[10], letrasA = 0, letrasB = 0;
	
	for (int i = 0; i < 10; i++) {
		cin>>cad[i];
		if (cad[i] == 'a') {
			letrasA++;
		} else if (cad[i] == 'b') {
			letrasB++;
		}
	}
	
	if (letrasA > 0) {
		cout<<"Se encontraron "<<letrasA<<" en la frase."<<endl;
	} else {
		cout<<"No se encontraron letras 'a' en la frase."<<endl;
	}
		if (letrasB > 0) {
		cout<<"Se encontraron "<<letrasB<<" en la frase."<<endl;
	} else {
			cout<<"No se encontraron letras 'b' en la frase."<<endl;
		}
	return 0;
}

