#include <iostream>
using namespace std;

void mayorDeTres(int uno, int dos, int tres);

int main(int argc, char *argv[]) {
	
	int uno, dos, tres, mayor;
	
	cout<<"Ingrese el primer número: "<<endl;
	cin>>uno;
	cout<<"Ingrese el segundo número: "<<endl;
	cin>>dos;
	cout<<"Ingrese el tercer número: "<<endl;
	cin>>tres;
	
	mayorDeTres(uno, dos, tres);
	return 0;
}

void mayorDeTres(int uno, int dos, int tres) {
	int mayor;
		if (uno > dos && uno > tres) {
			mayor = uno;
		} else if (dos > uno && dos > tres) {
			mayor = dos;
		} else if (tres > uno && tres > dos) {
			mayor = tres;
		}
	cout<<"El número mayor es: "<<mayor;
}

