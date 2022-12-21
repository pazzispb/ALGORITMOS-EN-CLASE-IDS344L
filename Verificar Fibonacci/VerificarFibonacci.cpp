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


int CalcularFibonacci(int anterior, int siguiente, int n){
	if(n == 0){
		return siguiente;	
	}
	else{
		return CalcularFibonacci(siguiente, anterior + siguiente, n-1);	
	}
}

int main(){
	int numero = 0;
	cout << "Ingrese el numero a verificar: ";
	cin >> numero;
	bool pertenece = false;
	
	for(int i = 1; i <= 99; i++){
		
		int fibonacci = CalcularFibonacci(0, 1, i);
		
		if (fibonacci > numero) break;
		else if (fibonacci == numero) {
			pertenece = true;	
		}
	}
	if(numero == 0) pertenece = true; 
	
	cout << (pertenece ? "El numero pertenece" : "El numero no pertenece");
	return 0;
}


