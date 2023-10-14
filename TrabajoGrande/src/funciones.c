/*
 * funciones.c
 *
 *  Created on: 14 oct. 2023
 *      Author: lp1-2023
 */
#include <stdio.h>
#include <stdlib.h>
extern char lamatriz[26][7][2];
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
        if (lamatriz[i][0][0] != '\0')
            printf(" %c ", lamatriz[i][0][0]);
        else
            printf(" - ");
        if (i % 5 == 0)
                    enter();
    }
}
//verifica si el turno que metio el jugador es correcto
int verificarTurno()
{
    int n = 0;
    while (n != 1 && n != 2)
        scanf("%d", &n);
    limpiarBuffer();
    return n;
}

 void tablaPosiciones(){
	 printf("Tabla de posiciones:\n");
	         for(int i=1;i<26;i++){
	         	printf("| %d |",i);
	         	if (i<10)
	         	    printf(" ");
	             if (i%5==0)
	                 enter();
	         }
 }
