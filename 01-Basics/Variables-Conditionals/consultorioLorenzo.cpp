#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int pago = 0, montoTotal = 0, cita, duracionTratamiento;
	 
		cout<<"Ingrese su número de cita: "<<endl;
		cin>>cita;
		cout<<"Ingrese cuantas sesiones durará su tratamiento: "<<endl;
		cin>>duracionTratamiento;
	
	if (cita == 1 or cita == 2 or cita == 3) {
		pago = 200;
		montoTotal=pago*duracionTratamiento;
		cout<<"El costo por cita es: "<<pago<<endl;
		cout<<"El costo total del tratamiento es: "<<montoTotal;
	} else if (cita == 4 or cita == 5) {
		pago = 150;
		montoTotal=pago*duracionTratamiento;
		cout<<"El costo por cita es: "<<pago<<endl;
		cout<<"El costo total del tratamiento es: "<<montoTotal;
	} else if (cita == 6 or cita == 7 or cita == 8) {
		pago = 100;
		montoTotal=pago*duracionTratamiento;
		cout<<"El costo por cita es: "<<pago<<endl;
		cout<<"El costo total del tratamiento es: "<<montoTotal;
	} else if (cita >= 9) {
		pago = 50;
		montoTotal=pago*duracionTratamiento;
		cout<<"El costo por cita es: "<<pago<<endl;
		cout<<"El costo total del tratamiento es: "<<montoTotal;
	}
	return 0;
}

