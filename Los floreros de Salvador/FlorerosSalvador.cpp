/*

FlorerosSalvador.cpp

Autor: Pazzis Paulino ID: 1103790

Asunto: Crear un programa que indique cuantos floreros le quedan a salvador por vender.

Hace algún tiempo Salvador compro 100 floreros para
venderlos en un mercadillo. La semana pasada, despues de
haber vendido algunos de ellos en los días anteriores, tenia los
floreros ordenados en 6 filas, con el mismo numero de unidades
en cada una de ellas. En esta semana vendió 8 floreros y en la
actualidad tiene los que le quedan , ordenados en 11 filas, con el
mismo numero de floreros en cada una.

*/

#include <iostream>

using namespace std;

int main(){
	int contador = 0;
	for (int i = 0; i <= 100; i++){
		if((100 - i) % 6 == 0){
			if((100 - (i + 8)) % 11 == 0){
				contador++;
				cout << "OPCION " << contador <<endl;
				cout << "Salvador tiene  " << 100 - (i + 8) << " floreros" << endl;
				cout << "Vendio " << (i+8) << endl << endl;
			}	
		}		
	}
	return 0;
}

