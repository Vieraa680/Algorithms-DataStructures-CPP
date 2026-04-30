#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float num, i, max, ubicacion = 0, ubi;
	
	cout<<"Ingrese la lista de números (el 0 finaliza la lista)"<<endl;
	cin>>num;
	max = num;
	while (num != 0) {
		ubicacion++;
		if(num > max) {
			max = num;
			ubi = ubicacion;
		}
		cout<<"Ingrese la lista de números (el 0 finaliza la lista)"<<endl;
		cin>>num;
	}
	cout<<"El número mayor fue: "<<max<<endl;
	cout<<"Y la ubicación fue: "<<ubi<<endl;
	
	return 0;
}

