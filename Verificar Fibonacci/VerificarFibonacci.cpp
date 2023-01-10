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
	numero = stoi(CapturarEntrada("Ingrese el numero a verificar como fibonacci: "));
	
	bool pertenece = VerificarFibonacci(0,1,numero);
		
	cout << (pertenece ? "El numero pertenece" : "El numero no pertenece");
	return 0;
}
