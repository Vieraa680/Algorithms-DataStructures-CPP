#include <iostream>
#include <cstring>
#define N 11
using namespace std;

int main(int argc, char *argv[]) {
	char frase[N];
	int i;
	
	cout<<"Ingrese una frase: "<<endl;
	cin.getline(frase, N);
	for (i=N-1; i>=0;i--) {
		cout<<frase[i]<<" ";
	}
	return 0;
}

