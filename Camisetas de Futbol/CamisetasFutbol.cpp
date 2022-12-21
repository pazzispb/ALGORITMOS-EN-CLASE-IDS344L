/*

CamisetasFutbol.cpp
Materia - Estructuras de Datos y Algoritmos II

Asunto: 
Dos amigos juegan en el mismo equipo de futbol y tienen su propio numero dorsal marcado en su camiseta.
Um dia el entrenador ve que el cuadrado de la suma de sus respectivos numeros es el numero de cuatro cifras que se ve cuando estan 
el uno junto al otro

Autor:  Pazzis Paulino 1103790
        Huan Hao Wu 1104326
        Johan Contreras 1106473
        Luis Adames 1106170
        Paola Saldana 1104081
        
Fecha: 15 - Diciembre - 2022

*/

#include <iostream>

using namespace std;

int CalcularSumaCuadrado(int n1, int n2);

int main(){
	for(int i = 0; i <= 99; i++){
		for(int j = 0; j <= 99; j++){
			if(i != j){
				int sumaCuadrado = CalcularSumaCuadrado(i, j);
				if(sumaCuadrado / 10000 > 0) continue; 
				if(sumaCuadrado == i*100 + j){
					cout << "No. Jugador 1:" << i << " \tNo. Jugador 2:" << j << endl;
				};
			}
		}
	}
	return 0;
}

int CalcularSumaCuadrado(int n1, int n2){
	int suma = n1 + n2;
	return suma * suma;
}

