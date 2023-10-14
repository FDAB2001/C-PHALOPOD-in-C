#include <stdio.h>
#include <stdlib.h>
//#include "variables.h"

extern int lamatriz[26][7][2];

extern int turnoinicial;
//valida algunas cosas de la jugada del jugador
int validarJugada(){
    printf("Su posicion: ");
    int posicion=0;
    scanf("%d",&posicion);
    limpiarBuffer();
    enter();
    while ((posicion<1 || posicion>25))
    {
        printf("Posicion invalida, seleccione otra posicion: ");
        scanf("%d",&posicion);
        limpiarBuffer();
        enter();
        for (int i = 1; i < 26; i++)
            {
                if (lamatriz[i][0][0] != '\0'){
                    posicion=0;
                	printf("La posicion tiene un dado \n");
                }
            }
    }

    return posicion;
}
//aca se maneja todo lo que tenga que ver con el jugador
int jugador(int turno){
    int correcto=0;
    while (correcto==0)
    {
        printf("Seleccione en que casilla del 1 al 25 para poner el dado\n");
        printf("Tablero actual: \n");
        imprimirMatriz();
        printf("Tabla de posiciones:\n");
        for(int i=1;i<26;i++){
        	printf("| %d |",i);
        	if (i<10)
        	    printf(" ");
            if (i%5==0)
                enter();
        }
        int jugada=validarJugada();
        lamatriz[jugada][0][0]=1;
        turno=2;
        return turno;

    }
    
}
