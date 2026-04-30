#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	
	string texto;
	ofstream archivo;
	
	archivo.open("arq.txt");
	
	if(archivo.fail()) {
		cout<<"Ha habido un error al crear el archivo...";
		exit(1);
	}
	
	cout<<"Ingrese el texto que desea escribir en el archivo:"<<endl;
	getline(cin, texto);
	if (texto != "0") {
		archivo<<texto;
	} else {
		cout<<"Se ingresó 0. Se terminó el programa.";
	}
	archivo.close();
	
	archivo.open("arq.txt");
	
	cout<<"El texto ingresado es: "<<texto;
	
	archivo.close();
	return 0;
}

