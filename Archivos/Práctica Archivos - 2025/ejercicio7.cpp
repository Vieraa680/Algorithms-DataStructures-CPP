#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	fstream archivo;
	
	string nombre, linea, palabra, sustituto, palabraLeida;
	
	cout<<"Ingrese el nombre del archivo: ";
	getline(cin, nombre);
	
	archivo.open(nombre + ".txt", ios::out);
	
	if (archivo.fail()) {
		cout<<"Hubo un error al crear el archivo.";
		exit(1);
	}
	
	do {
		cout<<"Ingrese el contenido del archivo: "<<endl;
		getline(cin, linea);
		archivo<<linea<<endl;
		cout<<"Ingrese 's' para salir o <Enter> para continuar..."<<endl;
	} while(cin.get() != 's');
	
	archivo.close();
	
	cout<<"Ingrese la palabra a buscar: ";
	cin.ignore();
	getline(cin, palabra);
	
	cout<<"Ingrese el reemplazo: ";
	getline(cin, sustituto);
	
	archivo.open(nombre + ".txt", ios::in);
	
	while (archivo>>palabraLeida) {
		if (palabra == palabraLeida) {
			archivo<<sustituto;
		}
	}
	
	archivo.close();
	return 0;
}

