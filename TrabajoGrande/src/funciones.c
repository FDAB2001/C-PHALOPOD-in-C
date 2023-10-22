#include <stdio.h>
#include <stdlib.h>
extern int lamatriz[26][7][2];
void limpiarBuffer(){
	int x=0;
	while((x=getchar())!='\n'&&x!=EOF&&x!=0){}
}

//Funcion que agrega un enter a la consola

void enter(){
    printf("\n");
}
//lamatriz[i][1-6][0]= 1-2 aca
void imprimirMatriz()
{
    for (int i = 1; i < 26; i++)
    {
        if (lamatriz[i][0][0] != 0){
            for(int j=0;j<6;j++){
            	if(lamatriz[i][0][0]==j){
            		if(lamatriz[i][j][0]==1){
            			printf("(%d)",lamatriz[i][0][0]);
            		}
            		else{printf("[%d]",lamatriz[i][0][0]);}
            	}
            }
        }else
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

 void llenarmatriz(){
	 for(int i=1;i<26;i++){
		 lamatriz[i][0][0]=0;
	 }
 }

 void imprimirDecision(){
	 printf("La posicion tiene dados cuya suma es mejor a 6, ¿cual quieres comer? \n (1) izquierda \n (2) derecha \n (3) arriba \n (4) abajo" );

 }
