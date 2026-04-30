#include <iostream>
#define TAM 5
using namespace std;

void cuadrado();
void muestra();

int vec[TAM]={1,2,3,4,5};

int main(int argc, char *argv[]) {
	cuadrado();
	muestra();
	return 0;
}

void cuadrado() {
	for (int i = 0; i < TAM; i++) {
		vec[i]=vec[i]*vec[i];
	}
}

void muestra () {
	for (int i = 0; i < TAM; i++) {
		cout<<vec[i]<<endl;
	}
}
