#include <iostream>
#include <cmath>
using namespace std;

// Realizar un programa que pida 2 valores enteros por teclado y muestre por pantalla el siguiente menú: 

// MENU

//1. Suma
//2.Resta
//3. Multiplicación
//4. Divide
//5. Potencia
//6. Factorial
//S. Salir

// El usuario debe elegir una de las opciones y mostrar el resultado por pantalla

//Se sugiere llamar al procedimiento: "void operacion (int n1, int n2, char oper, float, float &result, int &error)"
//siendo n1 y n2: parametros por valor (indica el tipo de operacion
// oper: parámetro por referencia donse se va a almacenar el resultado de la operación.
// error: parametro por referencia donde se va a almacenar "-1" si hubo problemas (división o factorial) o "1" si tuvo exito la operación
void operacion(int n1, int n2, char oper, float &result, int &error);

int main(int argc, char *argv[]) {
	int n1, n2;
	char oper;
	float result = 0;
	int error = 0;
	
	cout<<"Ingrese el primer número: "<<endl;
	cin>>n1;
	cout<<"Ingrese el segundo número: "<<endl;
	cin>>n2;
	
	cout<<"\n";
	
	cout<<"Menú"<<endl;
	
	cout<<"1. Suma"<<endl<<
		"2. Resta"<<endl<<
		"3. Multiplicación"<<endl<<
		"4. Divide"<<endl<<
		"5. Potencia"<<endl<<
		"6. Factorial"<<endl<<
		"S. Salir"<<endl;
	
	cout<<endl<<"Elija una opción del menú: "<<endl;
	cin>>oper;
	
	operacion(n1, n2, oper, result, error);
	
	//operacion(nro1, nro2, oper, &result, &error);
	return 0;
}

void operacion(int n1, int n2, char oper, float &result, int &error) {
	switch (oper) {
	case '1':
		result = n1 + n2;
		cout<<"El resultado de la suma es: "<<result;
		break;
	case '2':
		result = n1 - n2;
		cout<<"El resultado de la resta es: "<<result;
		break;
	case '3':
		result = n1 * n2;
		cout<<"El resultado de la multiplicación es: "<<result;
		break;
	case '4':
		if (n2 > 0) {
			cout<<"No se puede dividir por 0."<<endl;
		}
		result = n1 / n2;
		cout<<"El resultado de la división es: "<<result;
		break;
	case '5':
		result = pow(n1,n2);
		cout<<"El resultado de la potencia es: "<<result;
		break;
	case '6':
		result = n1 + n2;
		cout<<"El resultado de la suma es: "<<result;
		break;
	case 'S':
		result = n1 + n2;
		cout<<"El resultado de la suma es: "<<result;
		break;
	case 's':
		result = n1 + n2;
		cout<<"El resultado de la suma es: "<<result;
		break;
	}
}

//void operacion(int n1, int n2, char oper, float &result, int &error) {
	//cin>>n1;
//}


