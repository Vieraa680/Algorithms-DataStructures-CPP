#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V[10];
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento de la posición "<<i<<endl;
		cin>>V[i];
	}
	
	for (int i = 0; i < 10; i++) {
		if (i%2 == 0) {
			cout<<V[i]<<endl;
		}
	}
	return 0;
}

