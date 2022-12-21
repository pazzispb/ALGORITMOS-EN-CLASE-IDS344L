/*

FactoresPrimos.cpp
Materia - Estructuras de Datos y Algoritmos II

Asunto: 
Descomponer un numero en factores primos

Autor:  Pazzis Paulino 1103790
        Huan Hao Wu 1104326
        Johan Contreras 1106473
        Luis Adames 1106170
        Paola Saldana 1104081
        
Fecha: 15 - Diciembre - 2022

*/

#include <iostream>
#include <cmath>

using namespace std;

bool ValidarPrimo(int n){ //n es la posicion en la serie de numeros primos
	int contador = 0;
	for(int i = 2; i <= n-1; i++){
		if( n%i == 0) contador++;
	}
	return (contador == 0); //retorna true si es primo, false si no lo es
}

int ObtenerPrimo(int divisor){
	int primo = divisor;
	do{
		primo++;
	}while(ValidarPrimo(primo) == false);
	
	return primo;
}

string DescomponerFactores(int n, int divisor, string factores){
	if(n == 1){
		return factores;	
	}
	else{
		if( n%divisor == 0) {
			return DescomponerFactores( n/divisor, divisor, factores + "x" + to_string(divisor));	
		}
		else{
			int primo = ObtenerPrimo(divisor);
			return DescomponerFactores( n, primo, factores);
		}
	}
}

int main(){
	int numero = 0;
	cout << "Ingrese el numero a verificar: ";
	cin >> numero;
	cout << DescomponerFactores(numero, 2, "1");
	return 0;
}

