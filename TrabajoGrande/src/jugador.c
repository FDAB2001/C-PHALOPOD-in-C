#include <stdio.h>
#include <stdlib.h>
//#include "variables.h"

extern char lamatriz[26][7][2];
extern int posiocupada[1];

//valida algunas cosas de la jugada del jugador
int validarJugada(){
    int posicion=0;
    while ((posicion<1 || posicion>25))
    {
        printf("Seleccione una posicion: ");
        scanf("%d",&posicion);
        limpiarBuffer();
        enter();
        if(lamatriz[posicion][0][0]!='\0'){
            		printf("La posicion tiene un dado");
            		enter();
            		posicion=0;
            	}
    }
    return posicion;
}
//aca se maneja lo que tenga que ver con el jugador
int jugador(int turno){

        printf("Seleccione en que casilla del 1 al 25 para poner el dado\n");
        printf("Tablero actual: \n");
        imprimirMatriz();
        int jugada=validarJugada();
        lamatriz[jugada][0][0]='1';
        posiocupada[1]=jugada;
        lamatriz[jugada][1][0]='1';
        turno=2;
        return turno;
}
