#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char sexo;
	int dia, mes, cM = 0, cF = 0, primerS = 0, segundoS = 0;
	
	cout<<"Ingrese su Sexo (F o M)"<<endl;
	cin>>sexo;
	cout<<"Ingrese su día de Nacimiento: "<<endl;
	cin>>dia;
	cout<<"Ingrese su mes de Nacimiento: "<<endl;
	cin>>mes;
	
		while(sexo != 'B') {
			if (sexo == 'F') {
				cF++;
			} else if (sexo == 'M') {
				cM++;
			}
			if (mes >= 1 && mes <= 6) {
				primerS++;
			} else if (mes >= 7 && mes <= 12) {
				segundoS++;
			}
			cout<<"Ingrese su Sexo (F o M)"<<endl;
			cin>>sexo;
			if (sexo != 'B') {
			cout<<"Ingrese su día de Nacimiento: "<<endl;
			cin>>dia;
			cout<<"Ingrese su mes de Nacimiento: "<<endl;
			cin>>mes;
			}
		}
		cout<<"La cantidad de mujeres es: "<<cF<<endl;
		cout<<"La cantidad de hombres es: "<<cM<<endl;
		cout<<"La cantidad de nacidos en el primer Semestre es: "<<primerS<<endl;
		cout<<"La cantidad de nacidos en el segundo Semestre es: "<<segundoS<<endl;
	return 0;
}

