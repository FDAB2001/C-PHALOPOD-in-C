#ifndef VARIABLES_H_
#define VARIABLES_H_
//la primera dimension es la posicion, la segunda es el numero del dado, la tercera es si es del jugador (0) o la maquina (1)

#include <gtk/gtk.h>
int posiocupada[1];
int lamatriz[26][7][2];
//de quien es el turno inicial
int turnoinicial;
int decisiontomada=0;
int turno = 0;
int turnoinicial;
int decisionturno;
int jugar_pressed;
int turnoinicial;
int jugadaGTK;
int modo=0;
int suma=0;
int vector[] = { 0, 0, 0, 0, '\0' };
char nombrejugador1Global[50];
char nombrejugador2Global[50];
#endif //VARIABLES_H_
