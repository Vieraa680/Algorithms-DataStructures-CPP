#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float Base, Altura, Area;
		cout<<"Introduzca la base\n";
		cin>>Base;
		cout<<"Introduzca la altura\n";
		cin>>Altura;
		Area = Base * Altura;
		cout<<"El área del terreno según los datos ingresados es de " <<Area;
	return 0;
}

