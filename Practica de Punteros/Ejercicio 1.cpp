#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char A, B, *Pa, *Pb, aux;
	
	Pa = &A;
	Pb = &B;
		
	cout<<"Por favor ingrese el primer carácter: "<<endl;
	cin>>*Pa;
	cout<<"Por favor ingrese el segundo carácter: "<<endl;
	cin>>*Pb;
	cout<<"El primer carácter ingresado es: "<<*Pa<<" y su dirección de memoria es: "<<Pa<<endl;
	cout<<"El segundo carácter ingresado es: "<<*Pb<<" y su dirección de memoria es: "<<Pb<<endl;
	aux = *Pa;
	*Pa = *Pb;
	*Pb = aux;
	cout<<"Ahora si intercambiamos sus lugares, quedaría en primer lugar el carácter "<<*Pa<<" y en segundo lugar el carácter "<<*Pb<<endl;
	return 0;
}

