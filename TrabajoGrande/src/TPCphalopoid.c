#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
#include "jugador.h"
#include "computadora.h"
#include <stdint.h>

void verificarGanador(int *turno){
	int cont=0;
	int jug=0;
	int AI=0;
	for(int i=1;i<26;i++){
		for(int j=1;j<7;j++){
			 if(lamatriz[i][0][0]==j){
				 if(lamatriz[i][j][0]==1){
					 jug++;
					 cont++;
				 }else if(lamatriz[i][j][0]==2){
					 AI++;
					 cont++;
				 }
			 }
		}
	}if(cont==25){
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
    imprimirMatriz();
    //PONER WHILE TURNO INICIAL
            if (turnoinicial == 1)
                turno=jugador(turno);

            else//aca tiene que estar la compu
            	turno=computadora(turno);
    while (turno != 0)
    { 	printf("Tablero actual: \n");
		imprimirMatriz();
        if (turno==1)
        	turno=jugador(turno);
        else //aca tiene que estar la compu
        	turno=computadora(turno);
        verificarGanador(&turno);
    }
    enter();
    printf("fin");
    return 0;
}
