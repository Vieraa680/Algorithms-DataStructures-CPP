#include <iostream>
#include <fstream>

/*Escribir un programa que reciba del usuario un nombre de archivo de texto y muestre por pantalla cuántas líneas tiene ese archivo, cuantos caracteres son vocales y cuántos consonantes.
*/	
	

using namespace std;

int main(int argc, char *argv[]) {
	fstream archivo;
	string nombre, linea;
	char vocales[] = {'a', 'e', 'i', 'o', 'u'};
	int cantLineas = 0, cantVocales = 0, cantConsonantes = 0;
	
	cout<<"Ingrese el nombre del archivo: ";
	cin>>nombre;
	archivo.open(nombre+".txt", ios::out);
	
	if(archivo.fail()) {
		cout<<"Hubo un error al crear el archivo."<<endl;
		exit(1);
	}
	
	cin.get();
	
	do {
		cout<<"Ingrese el texto para agregar al archivo."<<endl;
		getline(cin, linea);
		archivo<<linea<<endl;
		cout<<"'s' para salir i <Enter> para continuar..."<<endl;
	} while(cin.get() != 's');
		
	archivo.close();
	
	archivo.open(nombre+".txt", ios::in);
	
	if(archivo.fail()) {
		cout<<"Hubo un error al abrir el archivo."<<endl;
		exit(1);
	}
	
	while (getline(archivo, linea)) {
		cantLineas++;
		
		for (int i = 0; i < linea.length(); i++) {
			char letraActual = tolower(linea[i]);
			bool esVocal = false;
			
			for (int j = 0; j < 5; j++) {
				if (letraActual == vocales[j]) {
					esVocal = true;
					break;
				}
			}
			
			if (esVocal) {
				cantVocales++;
			} else if (isalpha(letraActual)) {
				cantConsonantes++;
			}
		}
	}
	
	archivo.close();
	
	cout<<"La cantidad de líneas en el archivo son: "<<cantLineas<<endl;
	cout<<"La cantidad de vocales en el archivo son: "<<cantVocales<<endl;
	cout<<"La cantidad de consonantes en el archivo son: "<<cantConsonantes<<endl;
	
	
	
	return 0;
}

