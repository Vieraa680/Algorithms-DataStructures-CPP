#include <iostream>
using namespace std;

void multiplo(int nro1, int nro2);

int main(int argc, char *argv[]) {
	
	int nro1, nro2;
	
	cout<<"Ingrese el primero número: "<<endl;
	cin>>nro1;
	cout<<"Ingrese el segundo número: "<<endl;
	cin>>nro2;
	
	multiplo(nro1, nro2);
	return 0;
}

void multiplo(int nro1, int nro2) {
	if (nro1%nro2 == 0) {
		cout<<nro2<<" es múltiplo de "<<nro1;
	} else if (nro2%nro1 == 0) {
		cout<<nro1<<" es multiplo de "<<nro2;
	} else {
		cout<<"No son multiplos.";
	}
}

