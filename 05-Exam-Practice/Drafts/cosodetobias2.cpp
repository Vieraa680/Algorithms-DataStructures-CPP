#include <iostream>
using namespace std;
/*primer punto del parcial de la parte practica*/
int main(int argc, char *argv[]) {
	int nro, cont=1, cont_pares=0;
	float promedio=0;
	cout<<"ingrese nro"<<endl;
	cin>>nro;
	
	while(nro!=-50 and cont<100){
		cont++;
		if(nro%2==0)
			cont_pares++;
		promedio=promedio+nro;
		
		cout<<"ingrese numero"<<endl;
		cin>>nro;
	}
	cout<<"la cantidad de numeros ingresados es "<<cont<<endl;
	cout<<"el porcentaje de numeros pares es "<<cont_pares*100/cont<<endl;
	cout<<"promedio de los numeros ingresados es "<<promedio/cont<<endl;
	
	
	return 0;
}

