/*

NumerosPersistentes.cpp

Autor: Pazzis Paulino ID: 1103790

Asunto: Crear un programa que indique cual es el numero con mayor grado de persistencia de dos digitos.
 
*/
#include <iostream>

using namespace std;


int MultiplicarDigitos(int numero, int producto){
	
	int digito = numero % 10; //se obtiene el digito de la unidad
	
	int resto = numero / 10; //se obtiene el numero sin el digito de la unidad
	
	if(resto > 0) MultiplicarDigitos(resto, producto * digito); //si ya se tomaron todos los digitos del numero
	else return producto * digito;
}

int CalcularPersistencia(int numero, int persistencia){
	if ( numero / 10 == 0 ) return persistencia; //si el numero solo tiene un digito
	else{
		numero =  MultiplicarDigitos(numero, 1); //multiplica sus digitos
		CalcularPersistencia(numero, persistencia + 1);	//calcula la persistencia
	}
}
int main(){
	int persistencia = 0;
	
	for (int i = 10; i < 100; i++){ //recorre los numeros del 10 al 99
		
		persistencia = 	CalcularPersistencia(i, 0); //calcula su persistencia
		
		if(persistencia > 3) cout << "El numero " << i << " tiene una persistencia de " << persistencia << endl;
	}
	
	return 0;
}



