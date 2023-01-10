/*

VerificarFibonacci.cpp
Materia - Estructuras de Datos y Algoritmos II

Asunto: 
Verificar que un numero pertenece a la serie de fibonacci

Autor:  Pazzis Paulino 1103790
        Huan Hao Wu 1104326
        Johan Contreras 1106473
        Luis Adames 1106170
        Paola Saldana 1104081
        
Fecha: 15 - Diciembre - 2022

*/

#include <iostream>

using namespace std;


int VerificarFibonacci(int anterior, int siguiente, int numero){
	if(numero == anterior){
		return true;	
	}
	else if(numero < anterior){
		return false;
	}
	else{
		return VerificarFibonacci(siguiente, anterior + siguiente, numero);	
	}
}

int main(){
	int numero = 0;
	cout << "Ingrese el numero a verificar: ";
	cin >> numero;
	
	
	bool pertenece = VerificarFibonacci(0,1,numero);
		
	cout << (pertenece ? "El numero pertenece" : "El numero no pertenece");
	return 0;
}
