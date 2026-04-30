#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	
	string contenidoAux;
	char opcion;
	string ubicacionCarpeta, nombreArchivo, ubicacionCompleta, contenido;
	ifstream archivo;
	
	cout<<"Ingrese la ubicación de la carpeta en la que se encuentra su archivo:"<<endl;
	getline(cin, ubicacionCarpeta);
	fflush(stdin);
	
	cout<<"Ingrese el nombre de su archivo:"<<endl;
	cin>>nombreArchivo;
	
	ubicacionCompleta = ubicacionCarpeta + nombreArchivo + ".txt";
	
	archivo.open(ubicacionCompleta);
	
	if(archivo.fail()) {
		cout<<"\nHa habido un error al crear el archivo...";
		exit(1);
	}
	
	while(!archivo.eof()) {
		getline(archivo, contenido);
		contenidoAux = contenido;
	}
	
	archivo.close();
	
	ofstream archivoNuevo;
	
	cout<<"Ingrese S para guardar en otra dirección o ingrese N para guardar en la misma dirección que su archivo actual:"<<endl;
	cin>>opcion;
	if(opcion == 'S' or opcion == 's') {
		cout<<"Ingrese la ubicación de la carpeta en la que guardará su archivo:"<<endl;
		getline(cin, ubicacionCarpeta);
		fflush(stdin);
		
		cout<<"Ingrese el nuevo nombre de su archivo:"<<endl;
		cin>>nombreArchivo;
		
		ubicacionCompleta = ubicacionCarpeta + nombreArchivo + ".txt";
		
		archivo.open(ubicacionCompleta);
	} else if (opcion == 'N' or opcion == 'n') {
		cout<<"Ingrese el nuevo nombre de su archivo:"<<endl;
		cin>>nombreArchivo;
		archivo.open(nombreArchivo + ".txt");
		int tamano = contenido.size();
		for (int i = 0; i < tamano; i++) {
			contenido[i] = toupper(contenido[i]);
		}
		archivoNuevo<<contenido;
	}
	
	
	archivo.close();
	
	return 0;
}

