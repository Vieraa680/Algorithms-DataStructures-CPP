#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int num;
	cout<<"Ingrese el número para identificar el día de la semana ";
	cin>>num;
	if (num == 1) 
		cout<<"El día es Domingo";
	else 
		if(num == 2) 
			cout<<"El día es Lunes";
		
		else 
			if(num == 3) 
				cout<<"El día es Martes";
			
			else 
				if(num == 4) 
					cout<<"El día es Miércoles";
				
				else 
					if(num == 5) 
						cout<<"El día es Jueves";
					
					else 
						if(num == 6) 
							cout<<"El día es Viernes";
						
						else 
							if(num == 7) 
								cout<<"El día es Sabado";
							
							else 
								if(num != 1 && 2 && 3 && 4 && 5 && 6 && 7) 
									cout<<"El número ingresado no corresponde a un día semanal";
								
								
	return 0;
}

