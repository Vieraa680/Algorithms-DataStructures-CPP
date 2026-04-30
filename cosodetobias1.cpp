#include <iostream>
using namespace std;
/*punto 2 del parcial de la parte practica*/
int main(int argc, char *argv[]) {
	int N, nro, cont_impares;
	
	do{
		cout<<"ingrese N"<<endl;
		cin>>N;
	} while(N%2==0);
	
	
	for(int i=0; i<N; i++){
		cout<<"ingrese nro"<<endl;
		cin>>nro;
		
		if(nro%2!=0 and nro>-10 and nro<10)
			cont_impares++;
		
		if(nro%2==0 and nro!=2 and nro!=4)
			cout<<nro<<endl;
	}
	cout<<"la cantidad de numeros impares entre -10 y 10 es: "<<cont_impares<<endl;
	return 0;
}

