#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;

struct nodo {
	string fecha;
	float temperaturas [24];
	float humedades [24];
	bool estadosDeRiego [24];
	nodo *next;
};

bool fechaValida(int dia, int mes, int anio) {
	if (mes < 1 || mes > 12 || dia < 1) {
		return false;
	}
	
	int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) {
		diasMes[2] = 29;
	}
	
	return dia <= diasMes[mes];
}

bool tempValida(float temp) {
	if (temp < -10 || temp > 50) {
		return false;
	}
	
	return true;
}

bool humedadValida(float humedad) {
	if (humedad < 0 || humedad > 100) {
		return false;
	}
	
	return true;
}

bool estadoRiegoValido(char option) {
	char letter = toupper(option);
	if (letter != 'S' && letter != 'N') {
		return false;
	}
	
	return true;
}

bool fechaExiste(nodo *&lista, const string &fecha) {
	nodo *aux = lista;
	while (aux != NULL) {
		if (aux->fecha == fecha) {
			return true;
		}
		aux = aux->next;
	}
	return false;
}

void registrarNuevoDia(nodo *&lista) {
	nodo *aux = new nodo;
	int dia, mes, anio;
	char estadoRiego;
	float temp, humedad;
	string nuevaFecha;
	stringstream ss;
	
	do {
		cout<<"Ingrese el día: ";
		cin>>dia;
		cout<<"Ingrese el mes: ";
		cin>>mes;
		cout<<"Ingrese el año: ";
		cin>>anio;
		
		if (!fechaValida(dia, mes, anio)) {
			cout<<"Fecha inválida. Reingrese."<<endl;
			continue;
		}
		
		ss.str("");
		ss.clear();
		ss<<dia<<"/"<<mes<<"/"<<anio;
		nuevaFecha = ss.str();
		
		if (fechaExiste(lista, nuevaFecha)) {
			cout<<"La fecha ya existe. Ingrese una fecha diferente."<<endl;
		}
		
	} while (!fechaValida(dia, mes, anio) || fechaExiste(lista, nuevaFecha));
	
	aux->fecha = nuevaFecha;
	
	for (int i = 0; i < 4; i++) {
		cout<<"\nMedición para la hora "<<i<<":"<<endl;
		
		do {
			cout<<"Ingrese la temperatura: ";
			cin>>temp;
			
			if (!tempValida(temp)) {
				cout<<"Temperatura inválida. Reingrese"<<endl;
			}
		} while(!tempValida(temp));
		aux->temperaturas[i] = temp;
		
		do {
			cout<<"Ingrese la húmedad: ";
			cin>>humedad;
			
			if (!humedadValida(humedad)) {
				cout<<"Húmedad inválida. Reingrese"<<endl;
			}
		} while(!humedadValida(humedad));
		aux->humedades[i] = humedad;
		
		do {
			cout<<"Ingrese el estado de riego (S/N): ";
			cin.ignore();
			cin>>estadoRiego;
			
			if (!estadoRiegoValido(estadoRiego)) {
				cout<<"Estado de riego inválido. Reingrese"<<endl;
			}
		} while(!estadoRiegoValido(estadoRiego));
		aux->estadosDeRiego[i] = (toupper(estadoRiego) == 'S');
	}
	aux->next = lista;
	lista = aux;
}

void listarMediciones(nodo *&lista) {
	nodo *aux = NULL;
	int dia, mes, anio;
	string fecha;
	bool encontrado = false;
	
	do {
		cout<<"Ingrese el día: ";
		cin>>dia;
		cout<<"Ingrese el mes: ";
		cin>>mes;
		cout<<"Ingrese el año: ";
		cin>>anio;
		
		if (!fechaValida(dia, mes, anio)) {
			cout<<"Fecha inválida. Reingrese."<<endl;
		}
	} while (!fechaValida(dia, mes, anio));
	
	stringstream ss;
	ss<<dia<<"/"<<mes<<"/"<<anio;
	fecha = ss.str();
	
	aux = lista;
	
	cout<<endl<<"Hora | Temperatura | Humedad | Riego"<<endl;
	
	while(aux != NULL) {
		if (aux->fecha.compare(fecha) == 0) {
			for (int i = 0; i < 4; i++) {
				if (i < 10) {
					cout<<"0"<<i<<" | "<<aux->temperaturas[i]<<" | "<<aux->humedades[i]<<" | "<<(aux->estadosDeRiego[i] ? "Si" : "No")<<endl;
				}
				if (i >= 10) {
					cout<<i<<" | "<<aux->temperaturas[i]<<" | "<<aux->humedades[i]<<" | "<<(aux->estadosDeRiego[i] ? "Si" : "No")<<endl;
				}
			}
			encontrado = true;
			break;
		}
	aux = aux->next;
	}
	
	if (!encontrado) {
		cout<<endl<<"No se encontró datos para esa fecha."<<endl;
	}
}

void analizarDia(nodo *&lista) {
	nodo *aux = NULL;
	int dia, mes, anio;
	float sumadorTemp = 0, tempPromedio, tempMax, tempMin, sumHumedad = 0, humedadPromedio, totalHorasRiego = 0; 
	string fecha;
	bool encontrado = false;
	
	do {
		cout<<"Ingrese el día: ";
		cin>>dia;
		cout<<"Ingrese el mes: ";
		cin>>mes;
		cout<<"Ingrese el año: ";
		cin>>anio;
		
		if (!fechaValida(dia, mes, anio)) {
			cout<<"Fecha inválida. Reingrese."<<endl;
		}
	} while (!fechaValida(dia, mes, anio));
	
	stringstream ss;
	ss<<dia<<"/"<<mes<<"/"<<anio;
	fecha = ss.str();
	
	aux = lista;
	tempMax = aux->temperaturas[0];
	tempMin = aux->temperaturas[0];
	
	while(aux != NULL) {
		if (aux->fecha.compare(fecha) == 0) {
			for (int i = 0; i < 4; i++) {
				//Sumo todas las temperaturas
				sumadorTemp += aux->temperaturas[i];
				
				//Temperatura máxima y mínima
				if (aux->temperaturas[i] > tempMax) {
					tempMax = aux->temperaturas[i];
				} else if (aux->temperaturas[i] < tempMin) {
					tempMin = aux->temperaturas[i];
				}
				
				//Sumo todas las húmedades
				sumHumedad += aux->humedades[i];
				
				if (aux->estadosDeRiego[i]) {
					totalHorasRiego += aux->estadosDeRiego[i];
				}
			}
			encontrado = true;
			break;
		}
		aux = aux->next;
	}
	
	if (!encontrado) {
		cout<<endl<<"No se encontró datos para esa fecha."<<endl;
	}
	
	tempPromedio = (sumadorTemp/24);
	humedadPromedio = (sumHumedad/24);
	
	cout<<"La temperatura promedio fue: "<<tempPromedio<<endl;
	cout<<"La temperatura máxima fue: "<<tempMax<<endl;
	cout<<"La temperatura mínima fue: "<<tempMin<<endl;
	cout<<"La húmedad promedio fue: "<<humedadPromedio<<endl;
	cout<<"Las horas totales de riego activo fue de: "<<totalHorasRiego<<endl;
}

void exportarResumen(nodo *&lista) {
	float tempPromedio, humedadPromedio;
	ofstream archivo("resumen_invernadero.txt");
	if (!archivo.is_open()) {
			cout<<"Error al abrir el archivo."<<endl;
			return;
	}
	
	nodo *aux = lista;
	
	while (aux != NULL) {
		float sumadorTemp = 0, sumHumedad = 0;
		int totalHorasRiego = 0;
		
		for (int i = 0; i < 24; i++) {
			sumadorTemp += aux->temperaturas[i];
			sumHumedad += aux->humedades[i];
			if (aux->estadosDeRiego[i]) {
				totalHorasRiego++;
			}
		}
		
		tempPromedio = (sumadorTemp/24);
		humedadPromedio = (sumHumedad/24);
		
		archivo<<"Fecha: "<<aux->fecha<<endl;
		archivo<<"Temperatura promedio: "<<tempPromedio<<endl;
		archivo<<"Humedad promedio: "<<humedadPromedio<<endl;
		archivo<<"Horas de riego: "<<totalHorasRiego<<endl;

		archivo<<"--------------------------" <<endl;
		aux = aux->next;
	}
	
	archivo.close();
	cout<<"Resumen exportado exitosamente."<<endl;
}

int main(int argc, char *argv[]) {
	nodo *lista = NULL;
	char option;
	do {
		cout<<"Menú de operaciones"<<endl;
		cout<<"1) Registrar Nuevo Día"<<endl;
		cout<<"2) Listar Mediciones de un Día"<<endl;
		cout<<"3) Analizar Día"<<endl;
		cout<<"4) Exportar Resumen"<<endl;
		cout<<"5) Cerrar Sistema"<<endl;
		
		cout<<"Ingrese una opción del menú: ";
		cin>>option;
		
		switch (option) {
			case '1': 
				registrarNuevoDia(lista);
				break;
			case '2':
				listarMediciones(lista);
				break;
			case '3':
				analizarDia(lista);
				break;
			case '4':
				exportarResumen(lista);
				break;
		}
	} while(option != '5');
	
	return 0;
}

