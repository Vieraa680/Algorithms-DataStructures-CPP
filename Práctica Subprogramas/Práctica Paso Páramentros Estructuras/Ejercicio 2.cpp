#include <iostream>

using namespace std;

struct Alumno {
	char nombre[30];
	float nota1;
	float nota2;
	float nota3;
	float nota4;
	float promedio;
};

void cargarDatos(struct Alumno &);

void mostrarDatos(struct Alumno);

int main(int argc, char *argv[]) {
	
	struct Alumno A;
	cargarDatos(A);
	mostrarDatos(A);
	return 0;
}

void cargarDatos(struct Alumno &A) {
	cout<<"Ingrese el nombre de alumno: "<<endl;
	cin.getline(A.nombre,30);
	
	do {
		cout<<"Ingrese la nota del primer parcial: "<<endl;
		cin>>A.nota1;
		if (A.nota1 < 0 && A.nota1 > 10) {
			cout<<"La nota está fuera del intérvalo de notas. Reintente"<<endl;
		}
	} while(A.nota1 < 0 && A.nota1 > 10);
	
	do {
		cout<<"Ingrese la nota del segundo parcial: "<<endl;
		cin>>A.nota2;
		if (A.nota2 < 0 && A.nota2 > 10) {
			cout<<"La nota está fuera del intérvalo de notas. Reintente"<<endl;
		}
	} while(A.nota2 < 0 && A.nota2 > 10);
	
	do {
		cout<<"Ingrese la nota del tercer parcial: "<<endl;
		cin>>A.nota3;
		if (A.nota3 < 0 && A.nota3 > 10) {
			cout<<"La nota está fuera del intérvalo de notas. Reintente"<<endl;
		}
	} while(A.nota3 < 0 && A.nota3 > 10);
	
	do {
		cout<<"Ingrese la nota del cuarto parcial: "<<endl;
		cin>>A.nota3;
		if (A.nota3 < 0 && A.nota3 > 10) {
			cout<<"La nota está fuera del intérvalo de notas. Reintente"<<endl;
		}
	} while(A.nota3 < 0 && A.nota3 > 10);
	
	A.promedio = (A.nota1 + A.nota2 + A.nota3 + A.nota4) / 4;
	
}

void mostrarDatos(struct Alumno A) {
	cout<<"El promedio es: "<<A.promedio;
}
