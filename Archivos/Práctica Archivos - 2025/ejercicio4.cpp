#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream archivo_original;
	ofstream archivo_copia;
	
	string original, copia;
	char letra;
	
	cout<<"Ingrese el nombre del archivo original: ";
	getline(cin, original);
	
	cout<<"Ingrese el nombre para la copia del archivo: ";
	getline(cin, copia);
	
	archivo_original.open(original + ".txt");
	archivo_copia.open(copia + ".txt");
	
	if(archivo_original.fail()) {
		cout<<"Hubo un error al abrir el archivo original."<<endl;
		exit(1);
	}
	
	if(archivo_copia.fail()) {
		cout<<"Hubo un error al crear el archivo copia."<<endl;
		exit(2);
	}
	
	while (archivo_original.get(letra)) {
		archivo_copia<<(char)toupper(letra);
	}
	
	archivo_original.close();
	archivo_copia.close();
	
	return 0;
}
