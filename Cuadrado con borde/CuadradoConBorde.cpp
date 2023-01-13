#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

int ancho = 119;
int largo = 29;

void Gotoxy(int x, int y) // se invoca la funcion GoToXY la cual admite dos valores enteros uno para X y otro para Y
{
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void EscribirMensaje(string mensaje, int x1, int y1, int x2, int y2){
	int nx1, ny1; //punto para escribir el mensaje y que quede centrado
	
	nx1 = (x1 + x2)/2 - mensaje.length()/2;
	ny1 = (y1 + y2)/2;
	
	Gotoxy(nx1, ny1);
	
	for(int i=0; i<mensaje.length();i++){
		Sleep(10);
		cout << mensaje[i];	
	}
	
	Gotoxy(0,y2+1);
}

void DibujarCuadro(int x1, int x2, int y1, int y2, string mensaje){
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //toma control de la consola
	
	int i;
	
	SetConsoleTextAttribute(h, 11); //azul
    for (i=x1;i<x2;i++){
		Gotoxy(i,y1); cout << (char)205; //linea horizontal superior
		Sleep(15);
    }
	
	Gotoxy(x2,y1); cout<< (char)187; //esquina superior derecha

	SetConsoleTextAttribute(h, 12); //rojo
    for (i=y1+1;i<y2;i++){
		Gotoxy(x2,i); cout << (char)186; //linea vertical derecha
		Sleep(15);
	}
	
	Gotoxy(x2,y2); cout<< (char)188; //esquina inferior izquierda
	
	SetConsoleTextAttribute(h, 13); //morado
	for (i=x2-1;i>x1;i--){
		Gotoxy(i,y2); cout << (char)205; //linea horizontal inferior
    	Sleep(15);
	}
    
    Gotoxy(x1,y2); cout<< (char)200; //esquina inferior derecha
    
    SetConsoleTextAttribute(h, 14); //Amarillo
    for (i=y2-1;i>y1;i--){
		Gotoxy(x1,i); cout << (char)186; //linea vertical izquierda
		Sleep(15);
	}
	
	Gotoxy(x1,y1); cout<< (char)201; //esquina superior izquierda
	
	SetConsoleTextAttribute(h, 7); //Blanco
	
	if(mensaje!="") EscribirMensaje(mensaje, x1, y1, x2, y2);
	
	_getch();

}

int main(){
	DibujarCuadro(0, ancho, 0, largo, "Estructuras de Datos y Algoritmos II");
	return 0;	
}
