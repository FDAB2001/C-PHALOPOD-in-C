#include <stdio.h>
#include <stdlib.h>
#include <time.h>
extern int lamatriz[26][7][2];
void limpiarBuffer(){
	int x=0;
	while((x=getchar())!='\n'&&x!=EOF&&x!=0){}
}

//Funcion que agrega un enter a la consola
void enter(){
    printf("\n");
}

void vaciar_matriz(){
	for(int i=0;i<=26;i++){
		lamatriz[i][0][0]='\0';
		for (int j=0;j<=7;j++){
			lamatriz[i][j][0]='\0';
			for(int k=0;k<=2;k++){
				lamatriz[i][j][k]='\0';
			}
		}
	}
}
//lamatriz[i][1-6][0]= 1-2 aca
void imprimir_matriz()
{
    for (int i = 1; i < 26; i++)
    {
        if (lamatriz[i][0][0] != 0){
            for(int j=0;j<7;j++){
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
int verificarTurno(int n)
{

    while (n != 1 && n != 2 && n!=3){
        printf("\nOpcion no disponible, eliga otro valor: ");
    	scanf("%d", &n);
    }
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

 void decirturnoini(int n){
	 if(n==1){
		 printf("El destino eligió que usted jugará primero.\n");
	 }
	 if(n==2){
	 		 printf("El destino eligió que la compu juegue primero.\n");
	 	 }

 }

 void decirparente(int n){
	 if(n==1){
	 		 printf("El destino eligió que usteded será parentesis.\n");
	 	 }
	 	 if(n==2){
	 	 		 printf("El destino eligió que la compu sea parentesis.\n");
	 	 	 }
 }

 int numeroAleatorio(int max, int min) {
	 srand(time(NULL));
	 return (rand() % (max - min + 1)) + min;
 }
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
