#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char opcion;
	float num1, num2, resultado;
	bool salir = false;
	
	while(!salir) {
		cout<<"Calculadora simple"<<endl;
		cout<<"1. Suma"<<endl;
		cout<<"2. Resta"<<endl;
		cout<<"3. Producto"<<endl;
		cout<<"4. División"<<endl;
		cout<<"S. Salir"<<endl;
		cout<<"Elija una opción: ";
		cin>>opcion;
		
		switch (opcion) {
		case '1':
			cout<<"Ingrese el primer número: "<<endl;
			cin>>num1;
			cout<<"Ingrese el segundo número: "<<endl;
			cin>>num2;
			resultado = num1 + num2;
			cout<<"El resultado de la suma es: "<<resultado<<endl;
			break;
		case '2':
			cout<<"Ingrese el primer número: "<<endl;
			cin>>num1;
			cout<<"Ingrese el segundo número: "<<endl;
			cin>>num2;
			resultado = num1 - num2;
			cout<<"El resultado de la resta es: "<<resultado<<endl;
			break;
		case '3':
			cout<<"Ingrese el primer número: "<<endl;
			cin>>num1;
			cout<<"Ingrese el segundo número: "<<endl;
			cin>>num2;
			resultado = num1 * num2;
			cout<<"El resultado del producto es: "<<resultado<<endl;
			break;
		case '4':
			cout<<"Ingrese el primer número: "<<endl;
			cin>>num1;
			do {
				cout<<"Ingrese el segundo número (diferente de 0): "<<endl;
				cin>>num2;
				if (num2 == 0) {
					cout<<"Error: El denominador no puede ser 0."<<endl;
				}
			} while(num2 == 0);
			resultado = num1 / num2;
			cout<<"El resultado de la división es: "<<resultado<<endl;
			break;
		case 'S':
		case 's':
			salir = true;
			break;
		default:
			cout<<"Opción no valida";
		}
	}
	return 0;
}

