#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num, sum = 0;
	
	do {
		cout<<"Ingrese el número a sumar"<<endl;
		cin>>num;
		sum = sum + num; 
		}
		while (sum <= 100);
		cout << "El valor acumulado antes de superar 100 es: " << sum - num;
	return 0;
}

