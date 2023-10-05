#include <stdio.h>
#include <stdlib.h>
//#include "variables.h"

extern char lamatriz[26][7][2];

extern int turnoinicial;

int validarJugada(){
    printf("Su posicion: ");
    int posicion=0;
    scanf("%d",&posicion);
    enter();
    while ((posicion<1 || posicion>25))
    {
        printf("Posicion invalida, seleccione otra posicion: ");
        for(int i=0;i<2;i++){
            for(int j=0;j<6;j++){
                if (lamatriz[posicion][j][i]!='/0')
                {
                    printf("La posicion seleccionada tiene un dado, seleccione otra\n");
                    posicion=0;validarJugada;
                }
                
            }
        }
    }
    limpiarBuffer();
    return posicion;
}

void jugador(){
    int correcto=0;
    while (correcto==0)
    {
        printf("Seleccione en que casilla del 1 al 25 para poner el dado\n");
        printf("Tablero actual: \n");
        imprimirMatriz();
        printf("Tabla de posiciones:\n");
        for(int i=1;i<26;i++){
            if (i%5==0)
                enter();
            
            printf("| %d |",i);
        }
        int jugada=validarJugada();
        lamatriz[jugada][1][0]=1;

    }
    
}
