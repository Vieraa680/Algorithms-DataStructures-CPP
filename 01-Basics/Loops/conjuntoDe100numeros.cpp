#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num, negativos = 0, mayores50 = 0, entre25y45 = 0;
	
	for (int i=0; i < 10; i++) {
		cout<<"Ingrese el número:"<<endl;
		cin>>num;
		
		if (num < 0) {
			negativos++;
		} else if (num > 50){
			mayores50++;
		} else if(num >= 25 && num <= 45) {
			entre25y45++;
		}
	}
	cout<<"Cantidad de números negativos: "<<negativos<<endl;
	cout<<"Cantidad de números mayores a 50: "<<mayores50<<endl;
	cout<<"Cantidad de números entre 25 y 45: "<<entre25y45<<endl;
	return 0;
}

