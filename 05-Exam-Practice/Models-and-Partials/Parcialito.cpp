#include <iostream>
#define N 20
using namespace std;

int main(int argc, char *argv[]) {
	char option;
	int VEC[N];
	float Matriz[3][4];
	bool cargaVec = false, cargaMatriz = false; 
	
	do {
		cout<<"Menú:"<<endl;
		cout<<"1. Vector"<<endl;
		cout<<"2. Matriz"<<endl;
		cout<<"3. Muestra"<<endl;
		cout<<"S. Salir"<<endl;
		
		cout<<"Ingrese una opción del menú: ";
		cin>>option;
		
		switch (tolower(option)) {
			case '1':
				for (int i = 0; i < N; i++) {
					cout<<"Ingrese el valor para la posición "<<i+1<<": ";
					cin>>VEC[i];
					cargaVec = true;
					if (VEC[i] == 0) break;
				}
				break;
			case '2': {
				float sumaFilas = 0;
				float mayorSuma = 0;
				int indiceColumnaMayor;

				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++) {
						cout<<"Ingrese el valor para la posición ["<<i+1<<","<<j+1<<"]: " ;
						cin>>Matriz[i][j];
					}
					cargaMatriz = true;
				}
				
				for (int j = 0; j < 4; j++) {
					int sumaColumnaActual = 0;
					for (int i = 0; i < 3; i++) {
						sumaColumnaActual += Matriz[i][j];
					}
					
					if (sumaColumnaActual > mayorSuma) {
						mayorSuma = sumaColumnaActual;
						indiceColumnaMayor = j+1;
					}
				}
				
				cout<<"La mayor suma entre en las columnas sucede en la columna "<<indiceColumnaMayor<<" con un resultado de: "<<mayorSuma<<endl;
					
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++) {
						sumaFilas+= Matriz[i][j];
					}
					cout<<"El promedio de la fila "<<i+1<<" es: "<<sumaFilas/4<<endl;
					sumaFilas = 0;
					cout<<endl;
				}
				break;
			}
			case '3': {
				char verOption;
				do {
					cout<<endl<<"Menú:"<<endl;
					cout<<"1- Mostrar elementos del vector."<<endl;
					cout<<"2- Mostrar elementos de la matriz."<<endl;
					cout<<"S- Volver atrás."<<endl;
					
					cout<<"Ingrese la opción: ";
					cin>>verOption;
					
					switch (toupper(verOption)) {
						case '1':
							if (!cargaVec) {
								cout<<"Para mostrar el vector primero debe cargar uno."<<endl;
							} else {
								for (int i = 0; i < N; i++ ) {
									cout<<VEC[i]<<", ";
								}	
							}
							break;
						case '2':
							if (!cargaMatriz) {
								cout<<"Para mostrar la matriz primero debe cargar una."<<endl;
							} else {
							for (int i = 0; i < 3; i++) {
								for (int j = 0; j < 4; j++) {
									cout<<Matriz[i][j]<<"  ";
								}
								cout<<endl;
							}
							}
							break;
						case 'S':
							cout<<endl;
							break;
					default: cout<<"Opción no válida. Reingrese."<<endl;
					}
				} while(toupper(verOption) != 'S');
				
				break;
			}
			default: cout<<"Opción no válida. Reingrese."<<endl; 
		}
	} while(tolower(option) != 's');
	return 0;
}

