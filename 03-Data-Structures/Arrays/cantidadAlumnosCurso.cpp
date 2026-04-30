#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int cantidadAlumnos, cAlumnos = 0, aprobados = 0, max = 0, min = 0, cDiez = 0, cMenores6 = 0;
	float p1, p2, promedio;
	char option;
	cout<<"Ingrese la cantida de alumnos anotados en el curso: "<<endl;
	cin>>cantidadAlumnos;
	
	if (cantidadAlumnos >= 1) {
		do {
		cout<<"\n Menú: "<<endl;
		cout<<"1.- Cargar notas de parciales y mostrar la cantidad de aprobados"<<endl;
		cout<<"2.- Cargar las notas del 1er parcial y mostrar la mayor y menor nota."<<endl;
		cout<<"3.- Cargar las notas del 2do parcial y mostrar si hubo algún 10(diez) y la cantidad de notas entre 0 y 6"<<endl;
		cout<<"S.- Salir"<<endl;
		
		cout<<"Para continuar elija una opción..."<<endl;
		cin>>option;
		
		switch (option) {
		case '1':
			do {
				cout<<"Ingrese la nota del primer parcial: "<<endl;
				cin>>p1;
				cout<<"Ingrese la nota del segundo parcial: "<<endl;
				cin>>p2;
				promedio = (p1 + p2) / 2;
				if (promedio >= 6) {
					aprobados++;
				}
				cAlumnos++;
			} while(cAlumnos < cantidadAlumnos);
			cout<<"La cantidad de alumnos que aprobaron son: "<<aprobados;
			break;
		case '2':
			do {
				cout<<"Ingrese la nota del primer parcial: "<<endl;
				cin>>p1;
				if (p1 > max) {
					max = p1;
				} else {
					min = p1;
				}
				min = p1;
				cAlumnos++;
			} while(cAlumnos < cantidadAlumnos);
			cout<<"La nota más alta obtenida en el primer parcial es: "<<max<<endl;
			cout<<"La nota más baja obtenida en el primer parcial es: "<<min<<endl;
			break;
		case '3': 
			do {
				cout<<"Ingrese la nota del segundo parcial: "<<endl;
				cin>>p2;
				if (p2 == 10) {
					cDiez++;
				} else if (p2 >= 0 && p2 <= 5.99) {
					cMenores6++;
				}
				min = p1;
				cAlumnos++;
			} while(cAlumnos < cantidadAlumnos);
			cout<<"La cantidad de dieces sacados es: "<<cDiez<<endl;
			cout<<"La cantidad de notas entre 0 y 5,99 es: "<<cMenores6<<endl;
			break;
		}
	} while (option != 'S' && option != 's');
	} else {
		cout<<"Introdujo un valor incorrecto"<<endl;
	}
	return 0;
}

