#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int edad1, edad2, edad3;
	
	edad1 = 13; //Lucas
	edad2 = 13;	//Maicol
	edad3 = 13;	//Mai
	
	if(edad1 == edad2 and edad2 == edad3) {
		cout<<"Son iguales";
	}
	
	if (edad1 < edad2 && edad1 < edad3) {
		cout<<"El menor es Lucas";
	}
	
	if (edad2 < edad1 && edad2 < edad3) {
		cout<<"El menor es Maicol";
	}
	
	if (edad3 < edad2 && edad3 < edad1) {
		cout<<"El menor es Mia";
	}
	return 0;
}

