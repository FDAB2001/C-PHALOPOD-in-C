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



void ponerDado(int jugada){
	// EJEMPLO PARA ENTENDER LA MATRIZ
			// CASO : tenes un dado 1 que queres meter en 8
			//lamatriz[8][0][0]= 1, esto ahora quiere decir que pusiste tu dado, luego:
			//lamatriz[8][1][0]= 2, esto quiere decir que la computadora puso el dado
			// CASO : en las posiciones 7 y 9 hay dados ricos de unidad 3 y decidiste comer ambos dados
			//lamatriz[8][0][0]=3+3 (ya que la suma de ambos dados es 3+3)
			//lamatriz[8][3+3][0]=2 (ya que vos sos la AI)
	if((jugada>6&&jugada<10)||(jugada>11&&jugada<15)||(jugada>16&&jugada<20)){
		//si la jugada esta en "medio" de la matriz se puede sumar cosas de arriba abajo izquierda y derecha
		//
	}
	if(jugada==1||jugada==5||jugada==21||jugada==25){
		//si la jugada esta en las esquinas, abajo derecha o abajo izquierda o arriba derecha o arriba izquieda, solo estas 4 opciones hay
	}
	if(jugada==2||jugada==3||jugada==4){
		//si la jugada esta en la primera fila, abajo derecha e izquierda
	}
	if(jugada==6||jugada==11||jugada==16){
		// si la jugada esta en la primera columna, arriba abajo y derecha
	}
	if(jugada==10||jugada==15||jugada==20){
		// si la jugada esta en la quinta columna, arriba abajo e izquieda
		}
	if(jugada==6||jugada==11||jugada==16){
			// si la jugada esta en la ultima fila, arriba izquieda y derecha
		}
}

void verificarGanador(int *turno){
	int cont=0;
	int jug=0;
	int AI=0;
	for(int i=1;i<26;i++){
		for(int j=1;j<7;j++){
			if(lamatriz[i][j][0]==1){
				jug++;
				cont++;
			}else if(lamatriz[i][j][0]==2){
				AI++;
				cont++;
			}
		}
	}
	enter();
	if(cont==25){
		*turno=0;
		if(AI<jug)
			printf("Gana el jugador");
		else printf("Gana LA MAQUINARIA");
	}


}
int main()
{
    int turno = 0;
    printf("Seleccione quien juega primero \n 1 para jugador primero \n 2 para la computadora primero \n");
    turnoinicial = verificarTurno();
    tablaPosiciones();
            if (turnoinicial == 1)
                turno=jugador(turno);
            else//aca tiene que estar la compu
            	turno=computadora(turno);
            	//turno=jugador(turno);
    while (turno != 0)
    {
        if (turno==1)
        	turno=jugador(turno);
        else //aca tiene que estar la compu pero como no funciona pongo el jugador otv
        	turno=computadora(turno);
        verificarGanador(&turno);
    }
    enter();
    printf("fin");
    return 0;
}

