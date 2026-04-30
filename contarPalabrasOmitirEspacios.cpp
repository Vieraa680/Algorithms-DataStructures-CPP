#include <iostream>
#include <cstring>
#include <cctype>
#define N 100
using namespace std;

int main(int argc, char *argv[]) {
	char Cad[N];
	int i, longitud, palabras = 1;
 	
	cout<<"Ingrese su texto: "<<endl;
	cin.getline(Cad, N);
	longitud = strlen(Cad);
	for (i = 0; i < longitud; i++) {
		if (Cad[i] == ' ') {
			palabras++;
		}
	}
	
	cout << "La cantidad de palabras es: " << palabras << "\n";
	cout << "La cantidad de letras es: " << longitud << "\n";
	
	
	cout<<Cad<<endl;
	return 0;
}

