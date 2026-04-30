#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float *valores, tuki, sumaAlturas = 0, alumnosMasAltos = 0, alumnosMasBajos = 0;
	int cant;
	
		cout<<"Ingrese el tamaño de su vector: "<<endl;
		cin>>cant;
		valores = new float [cant];
		
		for (int i=0; i < cant; i++) {
			cout<<"Ingrese el valor del elemento"<<endl;
			cin>>tuki;
			valores[i]=tuki;
			if (valores[i] > 15) {
				mayores15++;
			}
			sumaTotal += valores[i];
		}
		
		for (int i = 0; i < cant; i++){
			cout<<"\nEl valor de la posición del vector "<<i<<" es: "<<endl;
			cout<<valores[i]<<endl;
		}
		
		cout<<"\nLa suma total de los elementos dentro del vector es: "<<sumaTotal<<endl;
		cout<<"La cantidad de elementos que son mayoresa a 15 es: "<<mayores15;
		
	return 0;
}

