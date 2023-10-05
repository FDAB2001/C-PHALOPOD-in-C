#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
#include "jugador.h"
#include "computadora.h"
#include <stdint.h>
//Funcion que liwmpia el buffer

typedef enum
{
	ROJO,
	VERDE
}color;

typedef struct
{
	uint8_t valorDado;//NUmero del 1 al 6
	color colorDado; //color del dado

}casilla;

casilla tablero[5][5];

void limpiarBuffer(){
	int x=0;
	while((x=getchar())!='\n'&&x!=EOF&&x!=0){}
}

//Funcion que agrega un enter a la consola

void enter(){
    printf("\n");
}

void imprimirMatriz()
{
    for (int i = 1; i < 26; i++)
    {
        if (i % 5 == 0)
            enter();
        if (lamatriz[i][0][0] != '\0')
            printf(" %c ", lamatriz[i][0][0]);
        else
            printf(" - ");
    }
}

int verificarTurno()
{
    int n = 0;
    while (n != 1 && n != 2)
        scanf("%d", &n);
    limpiarBuffer();
    return n;
}

int main()
{
    int turno = 0;
    while (turno != 2)
    {
        if (turno == 0)
        {
            printf("Seleccione quien juega primero \n 1 para jugador primero \n 2 para la computadora primero");
            turnoinicial = verificarTurno();
        }
        imprimirMatriz();
        if (turnoinicial == 1)
            jugador();
        else
            computadora();
    }
    return 0;
}
