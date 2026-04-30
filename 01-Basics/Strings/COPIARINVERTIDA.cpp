#include <iostream>
#include <cstring>
#include <conio.h>
#define N 100
using namespace std;

int main(int argc, char *argv[]) {
	char cadA[N], cadB[N];
	int i=0;
	
	cout<<"Ingrese su texto: "<<endl;
	cin.getline(cadA, N);
	for (i = strlen(cadA); i >= 0; i--) {
		cout<<cadA[i];
	}

	return 0;
}

