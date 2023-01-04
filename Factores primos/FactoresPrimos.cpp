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
	for(int i = 2; i <= sqrt(n); i++){
		if( n%i == 0) return false;
	}
	return true; //si llega aqui significa que es primo
}

int ObtenerPrimo(int divisor){
	int primo = divisor + 1;
	if(ValidarPrimo(primo) == false) return ObtenerPrimo(primo); //si no es primo vuelve a llamar a la funcion
	else return primo; //si es primo retorna ese valor
}

string DescomponerFactores(int n, int divisor, string factores){
	if(n == 1){
		return factores;	
	}
	else{
		if( n%divisor == 0) { //si es divisor
			return DescomponerFactores( n/divisor, divisor, factores + "x" + to_string(divisor));	
		}
		else{
			int primo = ObtenerPrimo(divisor); //si no es divisor busca el proximo primo para dividir
			return DescomponerFactores( n, primo, factores); //vuelve a llamar la funcion
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

