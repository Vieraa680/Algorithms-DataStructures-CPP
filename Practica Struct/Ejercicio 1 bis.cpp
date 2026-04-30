#include <iostream>
#include <cstring>
#define N 3
using namespace std;

int main(int argc, char *argv[]) {
	
	int mayor = 0, menor = 0;
	char nombreMayor[20], nombreMenor[20];
	struct Persona {
		char Nombre[20];
		int edad;
		float sueldo;
	}
	persona[N];
	for(int i = 0; i < N; i++) {
		fflush(stdin);
		cout<<"Ingrese el nombre para la persona "<<i+1<<":"<<endl;
		cin.getline(persona[i].Nombre,20);
		cout<<"Ingrese la edad: "<<endl;
		cin>>persona[i].edad;
		cout<<"Ingrese el sueldo: "<<endl;
		cin>>persona[i].sueldo;
		if (persona[i].sueldo > mayor) {
			mayor = persona[i].sueldo;
			strcpy(nombreMayor, persona[i].Nombre);
		} else if (persona[i].sueldo < mayor) {
			menor = persona[i].sueldo;
			strcpy(nombreMenor, persona[i].Nombre);
		}
	}
	
	cout<<"La persona con mayor sueldo es "<<nombreMayor<<" con un sueldo de: "<<mayor<<endl;
	cout<<"La persona con menor sueldo es "<<nombreMenor<<" con un sueldo de: "<<menor<<endl;
	
	cout<<"Los datos de cada persona cargada son: "<<endl;
	
	for(int i = 0; i < N; i++) {
		cout<<"Persona "<<i+1<<":"<<endl;
		cout<<"Nombre: "<<persona[i].Nombre<<endl;
		cout<<"Edad: "<<persona[i].edad<<endl;
		cout<<"Sueldo: "<<persona[i].sueldo<<endl;
	}
	return 0;
}

