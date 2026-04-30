#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	fstream arch;
	
	arch.open("prueba.txt", fstream::out);
	if(arch.fail()) {
		cout<<"Hubo un error al abrir el archivo"<<endl;
		exit(1);
	}
	
	arch.close();
	return 0;
}

