#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int R, X, numMayor, acumMen=0, acumMay=0, valorXmenor;
	
	cout<<"ingrese un nunmero dentro de los reales"<<endl;
	cin>>R;
	do{
		cout<<"ingrese un conjunto de numeros"<<endl;
			cin>>X;
		if(X>R)
			numMayor++;
		acumMay=acumMay+X;
		if(X<R and X>0){
			valorXmenor++;
			acumMen=acumMen+X;}
		
	} while(X!=0);
	
	cout<<"la cantidad de numeros mayores a R es :"<<numMayor<<endl;
	cout<<"el promedio de los valores positivos mayores a R es :"<<acumMen/X<<endl;
	cout<<"el porcentaje de los valores positivos mayores a R es :"<<(acumMay*100)/X;
	return 0;
}

