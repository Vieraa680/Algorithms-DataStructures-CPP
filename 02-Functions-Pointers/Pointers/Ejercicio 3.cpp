#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	
	char nombre[50], *Pnombre;
	int vocales = 0;
	
	cout<<"Ingrese su nombre:"<<endl;
	cin.getline(nombre,50);
	
	Pnombre = &nombre[0];
	
	for (int i = 0; i < strlen(nombre); i++) {
		switch (*Pnombre) {
		case 'a': 
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			vocales++;
		break;
		};
		Pnombre++;
	}
	
	cout<<"Su nombre tiene 15 vocales."<<endl;
	return 0;
}

