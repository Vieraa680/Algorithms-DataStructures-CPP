#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n1, n2, S=0;
	cout<<"Ingrese dos números para calcular el producto"<<endl;
	cin>>n1;
	cin>>n2;
	for (int i=0; i<n2; i++) {
		S=S+n1;
		cout<<"El producto es "<<S<<endl;
	}
	return 0;
}

