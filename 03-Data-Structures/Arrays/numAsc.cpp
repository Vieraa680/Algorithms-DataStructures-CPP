#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num, numPrev = -1;
	bool ascendente = true;
	
	cout<<"Ingrese un número"<<endl;
	cin>>num;
	
	while (num >= 0) {
		cout<<"Ingrese un número"<<endl;
		cin>>num;
		if (numPrev != -1 && num < numPrev) {
			ascendente = false;
			break;
		}
		numPrev = num;
		cout<<"Ingrese un número"<<endl;
		cin>>num;
	}
	if (ascendente) {
	cout<<"La lista es ascendente"<<endl;
	} else {
		cout<<"La lista no es ascendente";
	}
	
	return 0;
}

