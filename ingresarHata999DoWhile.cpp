#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num, acum = 0, num1000 = 0, sumP = 0, iN = 0, sumN = 0;
	float promN = 0;
	
	do {
		cout<<"Ingrese el número"<<endl;
		cin>>num;
		acum++;
		
		if (num > 0) {
			sumP = sumP + num;
		}
		
		if (num < 0) {
			iN++;
			sumN = sumN + num;
		}
		
		
		if (num == 1000) {
			num1000++;
		}
	} while(num != 999);
	
	if (iN > 1) 
	promN = sumN / iN;
	
	cout<<"La cantidad de números que se ingresaron es: "<<acum<<endl;
	cout<<"La cantidad de veces que se ingresó el número 1000 fue: "<<num1000<<endl;
	cout<<"La suma de los numeros positivos ingresados es: "<<sumP<<endl;
	cout<<"El promedio de los numeros negativos ingresados es: "<<promN<<endl;
	
	
	
	return 0;
}

