#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	fstream archivo;
	string linea;
	char letra;
	
	archivo.open("algoritmos.txt", ios::out);
	
	if(archivo.fail()) {
		cout<<"Hubo un error al crear el archivo."<<endl;
		exit(1);
	}
		
	do {
		cout<<"Ingrese el texto para agregar al archivo: "<<endl;
		getline(cin, linea);
		archivo<<linea<<endl;
		cout<<"'0' para salir o <Enter> para continuar..."<<endl;
	} while(cin.get() != '0');
	
	archivo.close();
	
	archivo.open("algoritmos.txt", ios::in);
	
	while (archivo.get(letra)) {
		cout<<letra;
	}
	
	archivo.close();
	return 0;
}

