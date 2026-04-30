#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V[5];
	
	for (int i = 0; i < 5; i++) {
		cout<<"Cargue el elemento numero "<<i+1<<endl;
		cin>>V[i];
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = +1; j < 5 ; j++)
		if (V[i] == V[j]) {
			cout<<"El número que se repite es: "<<V[i]<<endl;
		}
	}
	return 0;
}

