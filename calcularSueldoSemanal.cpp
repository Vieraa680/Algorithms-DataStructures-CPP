#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int horasTrabajadas, sueldo = 400, horasExtras, total = 0;
	
	cout<<"Ingrese sus horas trabajadas"<<endl;
	cin>>horasTrabajadas;
	
	if (horasTrabajadas > 40) {
		horasExtras = horasTrabajadas - 40;
		horasExtras = horasExtras*(sueldo*2);
		total = 40 * sueldo;
		total = total + horasExtras;
	} else {
		total = horasTrabajadas*sueldo;
	}
	cout<<"El sueldo total es: "<<total;
	return 0;
}

