#include <iostream>
using namespace std;

struct Node {
	int unidad;
	float km;
	Node *next;
};

int calculateFactorial(int number) {
	int response = 1;
	
	for (int i = 1; i <= number; i++) {
		response *= i;
	}
	return response;
}

void LISTA(Node *&lista) {
	Node *node = NULL, *aux2 = NULL, *aux3 = NULL;
	int unidadMax;
	float kmTotal;
	
		do {
			node = new Node;
			do {
				cout<<"Ingrese la unidad de colectivo: ";cin>>node-> unidad;
				if (node-> unidad < 0) {
					cout<<"El número de unidad debe ser positivoo. Reingrese."<<endl;
				}
			} while(node-> unidad < 0);
			
			if (node-> unidad == 0) {
				cout<<"Saliendo de la carga de lista."<<endl;
				break;
			}
			
			do {
				cout<<"Ingrese la cantidad de kilometros recorridos: ";cin>>node-> km;
				if (node-> km < 0) {
					cout<<"La cantidad de km recorrido debe ser positivoo. Reingrese."<<endl;
				}
			} while(node-> km < 0);
			
			if (lista == NULL) {
				lista = node;
				node->next = NULL;
			} else {
				aux2 = lista;
				
				while(aux2 != NULL){
					aux3 = aux2;
					aux2 = aux2->next;
				}
				aux3->next = node;
				node->next = NULL;
			}
		} while (node-> unidad != 0);
		
		aux2 = lista;
		kmTotal = aux2->km;
		unidadMax = aux2->unidad;
		while(aux2 != NULL) {
			cout<<endl<<endl;
			cout<<"Unidad de colectivo: "<<aux2->unidad<<endl;
			cout<<"Km recorridos: "<<aux2->km<<endl;
			
			if (aux2->km > kmTotal) {
				unidadMax = aux2->unidad;
				kmTotal += aux2->km;
			}
			aux2 = aux2->next;
		}
		cout<<"La unidad con máximo recorrido fue la número "<<unidadMax<<" con "<<kmTotal<<" km recorridos."<<endl;
}


int main(int argc, char *argv[]) {
	char option;
	Node *lista = NULL;
	
	do {
		cout<<"Menu:"<<endl;
		cout<<"1.- Calcular factorial"<<endl;
		cout<<"2.- Cargar una lista"<<endl;
		cout<<"3.- Cargar datos a un archivo"<<endl;
		cout<<"F-f Finalizar"<<endl;
		cout<<"Ingrese una opción: ";cin>>option;
		
		switch (option) {
		case '1': {
			int number, response;
			
			do {
				cout<<"Ingrese el número para calcular el factorial: ";cin>>number;
				if (number < 0) {
					cout<<"El número debe ser positivo.Reingrese."<<endl;
				}
				response = calculateFactorial(number);
				
				cout<<"El factorial del número "<<number<<" es: "<<response<<endl<<endl;
			} while(number < 0);
			break;
		}
		case '2':
			LISTA(lista);
			break;
		};
	} while (tolower(option) != 'f');
	
	return 0;
}
