#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	fstream archivo;
	string nombre, linea, palabra, palabraLeida;
	int contPalabra = 0;
	
	cout<<"Ingrese el nombre del archivo: ";
	getline(cin, nombre);
	
	archivo.open(nombre + ".txt", ios::out);
	
	if (archivo.fail()) {
		cout<<"Hubo un error al crear el archivo."<<endl;
		exit(1);
	}
	
	do {
		cout<<"Ingrese el texto para el archivo: "<<endl;
		getline(cin, linea);
		archivo<<linea<<endl;
		cout<<"Ingrese 's' para terminar o <Enter> para seguir..."<<endl;
	} while(cin.get() != 's');
	
	archivo.close();
	
	archivo.open(nombre + ".txt", ios::in);
	
	if (archivo.fail()) {
		cout<<"Hubo un error al abrir el archivo."<<endl;
		exit(2);
	}
	
	cout<<"Ingrese la palabra que quiere buscar: ";
	cin.ignore();
	getline(cin, palabra);
	
	while (archivo>>palabraLeida) {
		if (palabra == palabraLeida) {
			contPalabra++;
		}
	}
	
	cout<<"La cantidad de veces que se encuentra la palabra "<<palabra<<" en el archivo es de "<<contPalabra<<" veces.";
	
	archivo.close();
	return 0;
}

