#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float n1,n2,resultado;
	char operador;
	cout<<"Ingrese el primer número"<<endl;
	cin>>n1;
	cout<<"Ingrese el segundo número"<<endl;
	cin>>n2;
	cout<<"Ingrese el operador"<<endl<<"+ para sumar los números"<<endl<<"- para restar los números"<<endl<<"* para multiplicar los numeros"<<endl<<"/ para dividir los números"<<endl;
	cin>>operador;
	switch (operador) {
	case '+':{
		cout<<"entro aca";
		resultado = n1 + n2;
		break;}
	case '-':
		resultado = n1 - n2;
		break;
	case '*':
		resultado = n1 * n2;
		break;
	case '/':
		if (n2 != 0)
		resultado = n1 / n2;
		else 
			cout<<"No se puede dividir por 0";
		break;
	default:
		cout<<"Error al seleccionar el símbolo";
	}
	if (resultado)
	cout<<"El resultado es "<<resultado;
	else 
		cout<<"El cálculo no se puedo hacer";
	return 0;
}

