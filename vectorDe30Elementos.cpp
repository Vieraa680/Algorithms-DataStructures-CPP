#include <iostream>
#define N 5
using namespace std;

int main(int argc, char *argv[]) {
	float vector[5]={}, tuki, sumaTotal = 0, mayores15 = 0;
		
		for (int i=0; i < N; i++) {
			cout<<"Ingrese el valor del elemento"<<endl;
			cin>>tuki;
			vector[i]=tuki;
			if (vector[i] > 15) {
				mayores15++;
			}
			sumaTotal += vector[i];
		}
		
		for (int i = 0; i < N; i++){
			cout<<"\nEl valor de la posición del vector "<<i<<" es: "<<endl;
			cout<<vector[i]<<endl;
		}
		
		cout<<"\nLa suma total de los elementos dentro del vector es: "<<sumaTotal<<endl;
		cout<<"La cantidad de elementos que son mayoresa a 15 es: "<<mayores15;
		
	return 0;
}

