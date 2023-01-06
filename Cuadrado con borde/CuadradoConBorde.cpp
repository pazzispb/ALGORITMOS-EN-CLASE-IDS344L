/*

CuadradoConBorde.cpp
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
#include <windows.h>

using namespace std;

int ancho = 100;
int largo = 24;

void Gotoxy(int x, int y) // se invoca la funcion GoToXY la cual admite dos valores enteros uno para X y otro para Y
{
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void DibujarCuadro(int x1, int x2, int y1, int y2){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //toma control de la consola
	
	int i;
	int nx1, nx2, ny1, ny2;
	nx1 = 60 - x2/2;
	nx2 = 60 + x2/2;
	ny1 = 12 - y2/2;
	ny2 = 12 + y2/2;

	SetConsoleTextAttribute(h, 11); //Amarillo
    for (i=nx1;i<nx2;i++){
		Gotoxy(i,ny1); cout << (char)205; //linea horizontal superior
		Sleep(15);
    }
	
	Gotoxy(nx2,ny1); cout<< (char)187; //esquina superior derecha

	SetConsoleTextAttribute(h, 12); //Amarillo
    for (i=ny1+1;i<ny2;i++){
		Gotoxy(nx2,i); cout << (char)186; //linea vertical derecha
		Sleep(15);
	}
	
	Gotoxy(nx2,ny2); cout<< (char)188; //esquina inferior izquierda
	
	SetConsoleTextAttribute(h, 13); //Amarillo
	for (i=nx2-1;i>nx1;i--){
		Gotoxy(i,ny2); cout << (char)205; //linea horizontal inferior
    	Sleep(15);
	}
    
    Gotoxy(nx1,ny2); cout<< (char)200; //esquina inferior derecha
    
    SetConsoleTextAttribute(h, 14); //Amarillo
    for (i=ny2-1;i>ny1;i--){
		Gotoxy(nx1,i); cout << (char)186; //linea vertical izquierda
		Sleep(15);
	}
	
	Gotoxy(nx1,ny1); cout<< (char)201; //esquina superior izquierda
	
	SetConsoleTextAttribute(h, 7); //Amarillo

}
void EscribirMensaje(string mensaje, int y){
	int nx1;
	nx1 = 60 - mensaje.length()/2;
	Gotoxy(nx1,y);
	
	for(int i=0; i<mensaje.length();i++){
		Sleep(10);
		cout << mensaje[i];	
	}
	Gotoxy(0,largo+1);
}

int main(){
	DibujarCuadro(0, ancho, 0, largo);
	EscribirMensaje("Estructuras De Datos y Algoritmos II", 12);
	return 0;	
}
