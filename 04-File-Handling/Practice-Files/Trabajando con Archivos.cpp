#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	ofstream archivo;
	
	archivo.open("C:\\Users\\Usuario\\Documents\\Algortimos y Estructuras de Datos\\Archivos\\datos.txt");
	
	if(archivo.fail()) {
		cout<<"Ha habido un error al crear el archivo...";
		exit(1);
	}
	
	archivo<<"Primera línea ingresada..."<<endl;
	archivo<<"Segunda línea ingresada..."<<endl;
	archivo<<"Tercera línea ingresada..."<<endl;
	archivo.close();
	return 0;
}

