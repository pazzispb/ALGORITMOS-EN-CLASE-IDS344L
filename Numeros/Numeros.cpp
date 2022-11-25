/*

Numeros.cpp

ASUNTOS:
La profesora explicaba a sus alumnos las propiedades de los numeros enteros. Les mostro como el 
numero 8833 es igual a 88^2 + 33^2 y prosiguo su clase. Como es habitual Gleidy no prestaba atencion,
asi advirtio que la hora que marcaba el reloj sin coma mostraba la misma propiedad, esto quiere decir que el cuadrado de
los numeros que indicaba la hora al cuadrado mas los que indicaban los minutos al cuadrado daba el numero sin coma.

AUTOR: Pazzis Paulino 1103790

ASIGNATURA: IDS344 Estructura de Datos y Algoritmos

*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	int hora = 24, minuto = 60; //Maximos
	int numero = 0; //numero que cumple
	
	int contador = 0;
	
	for(int i = 0; i < hora; i++){
		for(int j = 0; j < minuto; j++){
			
			numero = i*100 + j;
			
			if(i*i + j*j == numero) 
			{
				contador++;
				cout << "Opcion "<< contador <<" : " << i << ":" << j << endl;	
			}
		}
	}
}
