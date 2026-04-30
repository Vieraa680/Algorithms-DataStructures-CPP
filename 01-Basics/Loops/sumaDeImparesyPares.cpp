#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n, sumaPar = 0, sumaImpar = 0;
	cin>>n;
	for(int i=1; i<n; i++) {
		if(i%2 == 0) {
			sumaPar += 1;
		} else {
			sumaImpar += i;
		}
	}
	cout<<"La suma de los números pares es: "<<sumaPar<<endl;
	cout<<"La suma de los números impares es: "<<sumaImpar<<endl;
	return 0;
}

