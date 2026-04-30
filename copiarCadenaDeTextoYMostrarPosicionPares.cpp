#include <iostream>
#include <cstring>
#define N 20
using namespace std;

int main(int argc, char *argv[]) {
	char Cad[N], CadCopy[N];
	int i;
	
	cout<<"Ingrese la frase: "<<endl;
	cin.getline(Cad, N);
	cout<<"La frase ingresada es: "<<Cad<<endl;
	strcpy(CadCopy, Cad);
	for (i = 0; i < strlen(CadCopy); i++) {
		CadCopy[i] = tolower(CadCopy[i]);
	}
	cout<<"La frase que fue copiada y pasada a minúscula es: "<<CadCopy<<endl;
	cout<<"Ahora voy a mostrar solamente los elementos pares: "<<endl;
	for (i = 0; i < strlen(CadCopy); i+=2) {
		cout<<"En la posición "<<i<<" se encuentra el elemento: "<<CadCopy[i]<<endl;
	}
	return 0;
}

