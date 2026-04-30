#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	char cad[5];
	
	for (int i = 0; i < 5; i++) {
		cin>>cad[i];
	}
	
	for (int i = 5; i > 0; i--) {
		cout<<cad[i];
	}
	
	return 0;
}

