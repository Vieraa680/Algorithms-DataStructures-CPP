#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float sueldoSemanal, sueldoHora;
	int horas;
	cout<<"Ingrese el sueldo por hora del trabajador \n";
	cin>>sueldoHora;
	cout<<"Ingrese las horas trabajadas esta semana \n";
	cin>>horas;
	if (horas > 40) {
		sueldoSemanal = (sueldoHora*horas)*2;
			cout<<"El sueldo semanal teniendo en cuenta que el empleado trabajo mas de 40 horas es "<<sueldoSemanal;
	} else {
		sueldoSemanal = (sueldoHora*horas);
		cout<<"El sueldo semanal teniendo en cuenta que el empleado trabajo más de 40 horas es "<<sueldoSemanal;
	}
	return 0;
}

