#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	ifstream archivo;
	string ubicacionCarpeta, nombreArchivo, ubicacionCompleta, extensionArchivo, contenido;
	int vocales = 0;
	
	cout<<"Ingrese la ubicación de la carpeta en la que se encuentra su archivo:"<<endl;
	getline(cin, ubicacionCarpeta);
	fflush(stdin);
	
	cout<<"Ingrese el nombre de su archivo:"<<endl;
	cin>>nombreArchivo;
	
	cout<<"Ingrese la extensión de su archivo (.txt, mp3, mp4, etc):"<<endl;
	cin>>extensionArchivo;
	
	ubicacionCompleta = ubicacionCarpeta + nombreArchivo + extensionArchivo;
	
	archivo.open(ubicacionCompleta);
	
	if(archivo.fail()) {
		cout<<"\nHa habido un error al crear el archivo...";
		exit(1);
	}
	
	while(!archivo.eof()) {
		getline(archivo, contenido);
		int tamano = contenido.size();
		for (int i = 0; i < tamano; i++) {
			if (contenido[i] == 'a' || contenido[i] == 'e' || contenido[i] == 'i' || contenido[i] == 'o' || contenido[i] == 'u') {
				vocales++;
			}	
		}
	}
	cout<<"El archivo tiene "<<vocales<<" vocales en su texto."<<endl;

	archivo.close();
	return 0;
}

