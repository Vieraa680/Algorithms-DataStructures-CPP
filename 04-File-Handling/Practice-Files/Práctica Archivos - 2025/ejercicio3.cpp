#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream archivo;
	string nombre;
	string telefono;
	
	archivo.open("usuarios.txt");
	
	if (archivo.fail()) {
		cout<<"Hubo un error al crear el archivo."<<endl;
		exit(1);
	}
	
	do {
		cout<<"Ingrese el nombre: ";
		getline(cin, nombre);
		cout<<"Ingrese el telefono (0 para salir): ";
		getline(cin, telefono);
		
		if (telefono != "0") {
			archivo<<"Nombre: "<<nombre<<" - Telefono: "<<telefono<<endl;
		}
		
	} while(telefono != "0");
	
	archivo.close();
	return 0;
}

