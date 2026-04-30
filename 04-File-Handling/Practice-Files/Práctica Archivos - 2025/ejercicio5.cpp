#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream archivo1;
	ifstream archivo2;
	ofstream archivoNuevo;
	
	char letra;
	string nombrePrimer, nombreSegundo, nombreNuevo;
	
	cout<<"Ingrese el nombre del primer archivo: ";
	getline(cin, nombrePrimer);
	
	cout<<"Ingrese el nombre del segundo archivo: ";
	getline(cin, nombreSegundo);
	
	cout<<"Ingrese el nombre del nuevo archivo: ";
	getline(cin, nombreNuevo);
	
	archivo1.open(nombrePrimer + ".txt");
	archivo2.open(nombreSegundo + ".txt");
	archivoNuevo.open(nombreNuevo + ".txt");
	
	if (archivo1.fail()) {
		cout<<"Hubo un error al abrir el primer archivo."<<endl;
		exit(1);
	}
	
	if (archivo2.fail()) {
		cout<<"Hubo un error al abrir el segundo archivo."<<endl;
		exit(2);
	}
	
	if (archivoNuevo.fail()) {
		cout<<"Hubo un error al crear el nuevo archivo."<<endl;
		exit(3);
	}
	
	while(archivo1.get(letra)) {
		archivoNuevo<<letra;
	}
	
	while(archivo2.get(letra)) {
		archivoNuevo<<letra;
	}
	
	archivo1.close();
	archivo2.close();
	archivoNuevo.close();
	
	return 0;
}
