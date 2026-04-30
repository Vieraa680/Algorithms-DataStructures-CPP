#include <iostream>
using namespace std;

struct Node {
	int unidad;
	float km;
	Node *next;
};

int calculateFactorial(int number) {
	int factorial = 1;
	for (int i = 1; i <= number; i++) {
		factorial *= i;
	}
	return factorial;
}

void LISTA() {
	Node *head = ;
}

int main(int argc, char *argv[]) {
	char option;
	do {
		cout<<"1.-Calcular factorial"<<endl;
		cout<<"2.-Cargar una lista"<<endl;
		cout<<"3.-Cargar datos a un archivo"<<endl;
		cout<<"F-f Finalizar"<<endl;
		cout<<"Ingrese una opción para continuar: "; cin>>option;
		cout<<endl;
		switch (option) {
		case '1': {
			int number;
			bool loop = false;
			do {
				cout<<(loop ? "El número debe ser positivo. Vuelva a ingresar un número: " : "Ingrese un número para calcular su factorial: "); cin>>number;
				
				if (number < 0) {
					loop=true;
				} else {
					loop=false;
					int result = calculateFactorial(number);
					cout<<"El factorial de "<<number<<" es: "<<result<<endl<<endl;
				}
			} while(number < 0);
			break;
		}
		case '2':
			cout<<"a";
			break;
		}
	} while (tolower(option) != 'f');
	return 0;
}
