#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	string nombre, linea, extension;
	ofstream archivo;
	
	cout<<"Ingrese el nombre del archivo:"<<endl;
	cin>>nombre;
	cout<<"Ingrese la extensión de su archivo (.txt, .mp3, .mp4, etc)"<<endl;
	cin>>extension;
	archivo.open(nombre + extension);
	
	if (archivo.fail()) {
		cout<<"Ha habido un error al crear el archivo...";
		exit(1);
	}
	
	if(extension == ".txt") {
	archivo<<"Primera línea";
	}
	
	archivo.close();
	return 0;
}

