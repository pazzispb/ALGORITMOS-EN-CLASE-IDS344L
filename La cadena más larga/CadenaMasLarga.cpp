/*

CadenaMasLarga.cpp

Autor: Pazzis Paulino ID: 1103790

Asunto: Crear un programa que obtenga el numero que genere la cadena mas larga al realizar las siguientes operaciones
 - Si el numero es par, dividir entre 2
 - Si el numero es impart, multiplicar por 3 y sumar 1
 
Cuando se llegue a 4 la cadena debe parar.

*/

#include <iostream>

using namespace std;

bool ValidarPar(int numero){ //return true si es par, false si es impart
	return numero % 2 == 0;
}

int ObtenerLongitudCadena(int numero, int longitud){ //obtiene la longitud de las cadenas que se forman
	if(numero == 4){ //si el numero es 4
		return longitud; //retorna la longitud actual
	}
	else{
		if(ValidarPar(numero)) return ObtenerLongitudCadena(numero / 2, longitud + 1);
		else return ObtenerLongitudCadena(3 * numero + 1, longitud + 1);
	}
}

int main(){
	int mayor = 1;
	for(int i = 2; i <= 99; i++){
		if(ObtenerLongitudCadena(i, 0) > ObtenerLongitudCadena(mayor, 0)){
			mayor = i;
		}
	}
	cout<<"El invitado que forma la cadena mas larga es la numero " << mayor << " con una longitud de " << ObtenerLongitudCadena(mayor, 0) << " de anillos";
	return 0;
}
