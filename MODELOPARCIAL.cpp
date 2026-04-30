#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int user, pass1, pass2, pass3;
	float saldo=1000;
	char option;
	
	do {
		cout<<"Ingrese el usuario (4 dígitos): ";
		cin>>user;
		
		if (user < 1000 || user > 9999) cout<<"El usuario debe tener 4 dígitos."<<endl;
	} while(user < 1000 && user > 9999);
	
	do {
		cout<<"Ingrese la contraseña (3 cifras consecutivas): ";
		cin>>pass1>>pass2>>pass3;
		
		if ((pass1 > pass2) && pass2 < pass3) cout<<"La contraseña debe ser consecutiva."<<endl;
	} while((pass1 > pass2) && pass2 < pass3);
	
	cout<<"El saldo inicial es 1000."<<endl;
	
	do {
		cout<<"a- Hacer depósitos."<<endl;
		cout<<"b- Retiros."<<endl;
		cout<<"c- Consultar su saldo."<<endl;
		cout<<"d- Salir."<<endl;
		
		cout<<"Ingrese una opción: ";
		cin>>option;
		
		switch(tolower(option)) {
			case 'a':
				float deposito;
				do {
					cout<<"Ingrese el monto para depositar: ";
					cin>>deposito;
					
					if (deposito < 0) cout<<"El depósito no puede ser negativo."<<endl;
				} while(deposito < 0);
				saldo+=deposito;
				cout<<"Su nuevo saldo es: "<<saldo<<endl;
				break;
			case 'b':
				float retiro;
				do {
					cout<<"Ingrese el monto a retirar: ";
					cin>>retiro;
					
					if (retiro > saldo) cout<<"El retiro no puede ser mayor al saldo."<<endl;
					if (retiro < 0) cout<<"El retiro no puede ser negativo."<<endl;
				} while(retiro < 0 || retiro > saldo);
				saldo-=retiro;
				cout<<"Su nuevo saldo es: "<<saldo<<endl;
				break;
		case 'c':
				cout<<"Su saldo actual es: "<<saldo;
				break;
			}
		
	} while(option != 'd');
	
	return 0;
}

