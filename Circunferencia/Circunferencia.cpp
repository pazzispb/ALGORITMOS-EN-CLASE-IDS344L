/*

circulo.cpp
Materia - Estructuras de Datos y Algoritmos II

Asunto: 

Realizar un programa que trace la forma de un circulo al ingresar el radio del mismo

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

string CapturarEntrada(string mensaje);
bool ValidarEntrada(string entrada);

// Maximo radio del circulo
const int radio_maximo = 10;

int main() {
    // input del radio
    int radio;
    radio = stoi(CapturarEntrada("Entra el radio del circulo: "));

    // Comprobar sea positivo y menor al maximo
    if (radio <= 0 || radio > radio_maximo) {
        cout << "Error, el numero no se encuentra en el rango recomendado para dibujar un circulo en consola" << endl;
        return 1;	
    }

    // loop para las y, negativo - positivo
    for (int y = -radio_maximo; y <= radio_maximo; y++) { // -radiomaximo corresponde a la parte vertical negativa del plano y radio maximo a la partevertical positiva
        // loop para las x, negativo - positivo
        for (int x = -radio_maximo; x <= radio_maximo; x++) { // en x -radiomaximo es la parte izquiera y radiomaximo la derecha
            // calcular tamano del grid y realizar coordenadas polares
            float x_escala = (x) * (radio_maximo * 2 ) / (radio_maximo * 2.0); // si pones el +1 como -6, se va a poner redondito en algunos radios 
            float y_escala = (y) * (radio_maximo * 2 ) / (radio_maximo * 2.0);
            // teniendo los puntos, calculamos el radio 
            float r = sqrt(x_escala * x_escala + y_escala * y_escala);
            // comprobamos que el circulo este en el radio
            if (round(r) == radio) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        // despues de cada fila, se deja un espacio
        cout << endl;
    }

    return 0;
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
