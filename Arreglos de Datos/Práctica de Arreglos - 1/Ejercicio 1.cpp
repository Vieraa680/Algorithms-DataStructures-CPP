#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int V [10];
	
	for (int i = 0; i < 10; i++) {
		cout<<"Cargue el elemento "<<i+1<<endl;
		cin>>V[i];
	}
	
	for (int i = 0; i < 10; i+=2) {
		cout<<"En la posición "<<i<<" se encuentra el elemento: "<<V[i]<<endl;
	}
	return 0;
}

