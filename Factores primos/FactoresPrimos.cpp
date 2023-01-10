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

bool ValidarEntrada(string entrada){ //true - es valida       false - no es valida 

	for(int i = 0; i < entrada.length(); i++) //recorre todas las posiciones del string de entrada
	{
		if(isdigit(entrada[i]) == false){
				cout << "La entrada debe ser numerica" << endl;
				return false; //si no es una entrada numeerica return falso
		}
	}
	return true;
}

string CapturarEntrada(string mensaje)  
{
	string entrada; //variable para almacenar la entrada
	bool correcta; //variable para verificar si la entrada es valida
	do{
	//se repetira hasta que el usuario ingrese una entrada valida 
		cout << mensaje;
		cin >> entrada; //Tome la entrada por pantalla
		correcta = ValidarEntrada(entrada); //Llama a la funcion para validar la entrada
		if(correcta == false) //si no es valida
		{
			cout << "Entrada no valida." << endl;
			system("pause");
		}
		cout << endl;
	} while (correcta == false); //repetir mientras que la entrada no sea valida
	return entrada; //retorna la entrada
}

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
	
	numero = stoi(CapturarEntrada("Ingrese el numero a descomponer: "));
	
	cout << "La descomposicion es:" << DescomponerFactores(numero, 2, "1");
	
	return 0;
}

