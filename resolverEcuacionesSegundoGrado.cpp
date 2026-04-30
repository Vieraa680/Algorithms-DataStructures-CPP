#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float A, B, C, X;
	
	cout<<"Ingrese el valor de A"<<endl;
	cin>>A;
	cout<<"Ingrese el valor de B"<<endl;
	cin>>B;
	cout<<"Ingrese el valor de C"<<endl;
	cin>>C;
	while(X!= 99) {
		cout<<"Ingrese el valor de X que sea distinto a 99"<<endl;
		cin>>X;
		cout<<"y = "<<A*X*X+B*X+C<<endl;
		break;
	}
	return 0;
}

