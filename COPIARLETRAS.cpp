#include <iostream>
#include <cstring>
#define N 100
using namespace std;

int main(int argc, char *argv[]) {
	char cadA[N], cadB[N];
	int j=0;
	
	cout<<"Ingrese su texto: "<<endl;
	cin.getline(cadA, N);
	strcpy(cadB, cadA);
	for (int i = 0; i < strlen(cadA); i++) {
		if (isalpha(cadA[i])) // si el carácter es una letra
		{
			cadB[j] = toupper(cadA[i]); // lo copiamos en mayúscula
			j++; // incrementamos el índice de cadB
		}
	}
	cadB[j] = '\0'; // añadimos el carácter nulo al final de cadB
	cout<<"cadA: "<<cadA<<endl;
	cout<<"cadB: "<<cadB<<endl;

	
	return 0;
}

