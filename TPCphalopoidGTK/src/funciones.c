#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
extern int lamatriz[26][7][2];
#include <gtk/gtk.h>
#include <unistd.h>
extern GtkWidget *tablero_nombre_display,*tablero_nombre_display2,*numdado1,*numdado2;
extern char nombrejugador1Global[50];//nombre del jugador 1 actual que se guardara en un archivo
extern char nombrejugador2Global[50];//nombre del jugador 2 actual que se guardara en un archivo
extern int turno;
int contadorlibre;
char delimitador[] = "/";
char delimitador2[]="=/;:_abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
char newplayer[100];
int j=0;
int valores[3];
int valori[100];
int bloker=0;
int values[100];
int contadorr;
int temp;
int numlinea=0;
int cuenta=0;
char *arraylineas2[100];
void limpiarBuffer(){
	int x=0;
	while((x=getchar())!='\n'&&x!=EOF&&x!=0){}
}

int diceposisdispo(){
int contadoreslibres=0;
for(int i=1;i<26;i++){
			if(lamatriz[i][0][0]=='\0'){
				contadoreslibres++;
			  }
			}
	return(contadoreslibres);
}

int numeroAleatorio(int max, int min) {
	 srand(time(NULL));
	 return (rand() % (max - min + 1)) + min;
 }

int lugareslibres(){
int *posicionesLibres = NULL;
for(int i=1;i<26;i++){
	if(lamatriz[i][0][0]=='\0'){
		contadorlibre++;
		posicionesLibres = (int *)realloc(posicionesLibres, contadorlibre * sizeof(int));
		posicionesLibres[contadorlibre - 1] = i;
	  }
	}
  int posu=numeroAleatorio(contadorlibre-1, 0);
  int posicionfinal=posicionesLibres[posu];
  contadorlibre=0;
  free(posicionesLibres);
  return(posicionfinal);
}

//Funcion que agrega un enter a la consola
void enter(){
    printf("\n");
}

void vaciar_matriz(){
	for(int i=0;i<=26;i++){
		lamatriz[i][0][0]='\0';
}
}
//lamatriz[i][1-6][0]= 1-2 aca
void imprimir_matriz()
{
    for (int i = 1; i < 26; i++)
    {
        if (lamatriz[i][0][0] != 0){
        	if(lamatriz[i][0][0]!=0&&lamatriz[i][0][0]!='\0'&&lamatriz[i][0][0]<0){
        		lamatriz[i][0][0]=lamatriz[i][0][0]*-1;
        		printf("Error detectado");
        	}
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

void stats(char *cadena2, int gano) {
	char delimitador[] = "/";
	char delimitador2[] =
			"=/;:_abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
	char newplayer[1000];
	int j = 0;
	int valores[3];
	int valori[100];
	int bloker = 0;
	int values[100];
	int contador;
	int temp;
	int numlinea = 0;
	int cuenta = 0;
	char *arraylineas2[100];
	int contadorr = 0;
	int contlin = 0;
	FILE *fp;

	fp = fopen("/home/lp1-2023/Documentos/Estadisticas", "r+");
	if (fp == NULL) {
		printf("\nEl archivo no existe. Creando uno nuevo...\n");

		// Abre el archivo en modo escritura para crearlo
		fp = fopen("/home/lp1-2023/Documentos/Estadisticas", "w+");
		if (fp == NULL) {
			printf("Error al crear el archivo.\n");
			exit(EXIT_FAILURE);
		}

		printf("Archivo creado con éxito.\n");
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);

	if (size == 0) {
		printf("El archivo está vacío.\n");
		if (gano == 1) {
			fprintf(fp,
					"/%s:Partidas_Jugadas=1;Partidas_ganadas=1;Partidas_Perdidas=0;\n",
					cadena2);
		} else {
			fprintf(fp,
					"/%s:Partidas_Jugadas=1;Partidas_ganadas=0;Partidas_Perdidas=1;\n",
					cadena2);
		}
		printf("Línea escrita en el archivo.\n");
		fclose(fp);
		return;
	}

	else {
		fp = fopen("/home/lp1-2023/Documentos/Estadisticas", "r");
		char *arrayDeLineas[200];
		int i = 0;
		char linea[200];
		// Leer líneas del archivo
		while (fgets(linea, 200, fp) != NULL && i < 100) {
			arrayDeLineas[i] = malloc(strlen(linea) + 1);
			strcpy(arrayDeLineas[i], linea);
			i++;
			contlin++;
		}

		fclose(fp);

		for (int j = 0; j < i; j++) {
			char *token = strtok(arrayDeLineas[j], delimitador);

			while (token != NULL) {
				char *resultado = strstr(token, cadena2); //estas lineas son las que buscan el nombre en el archivo

				if (resultado != NULL) {
					//printf("Se encontró %s en la linea %d y es %s\n", cadena2, j, resultado);
					//printf("Dice: %s\n",arrayDeLineas[j]);
					numlinea = j;
					bloker = 1;

					contador = 0;
					char *token2 = strtok(arrayDeLineas[numlinea],
							delimitador2);
					while (token2 != NULL && contador < 3) {
						valores[contador] = atoi(token2);
						contador++;
						token2 = strtok(NULL, delimitador2);
					}

					if (gano == 1) {
						sprintf(arrayDeLineas[numlinea],
								"/%s:Partidas_Jugadas=%d;Partidas_ganadas=%d;Partidas_Perdidas=%d;\n",
								cadena2, valores[0] + 1, valores[1] + 1,
								valores[2]);
						//printf("Dice: %s\n",arrayDeLineas[numlinea]);
					}
					if (gano == 0) {
						sprintf(arrayDeLineas[numlinea],
								"/%s:Partidas_Jugadas=%d;Partidas_ganadas=%d;Partidas_Perdidas=%d;\n",
								cadena2, valores[0] + 1, valores[1],
								valores[2] + 1);
						//printf("Dice: %s\n",arrayDeLineas[numlinea]);
					}
					fp = fopen("/home/lp1-2023/Documentos/Estadisticas", "w");

					if (fp == NULL) {
						printf("\nError al abrir el archivo en modo escritura");

					}
					for (int j = 0; j < i; j++) {
						fprintf(fp, "%s", arrayDeLineas[j]);
					}

					fclose(fp);

				}

				// Continuar con el próximo token
				token = strtok(NULL, delimitador);
				contadorr++;
			}

		}

		if (bloker == 0) {
			contlin++;
			fp = fopen("/home/lp1-2023/Documentos/Estadisticas", "w");
			for (int j = 0; j < i; j++) {
				fprintf(fp, "%s", arrayDeLineas[j]);
			}
			if (gano == 1) {
				sprintf(newplayer,
						"/%s:Partidas_Jugadas=1;Partidas_ganadas=1;Partidas_Perdidas=0;",
						cadena2);

			}
			if (gano == 0) {
				sprintf(newplayer,
						"/%s:Partidas_Jugadas=1;Partidas_ganadas=0;Partidas_Perdidas=1;",
						cadena2);
			}
			fprintf(fp, "%s", newplayer);
			fclose(fp);
		}

		//--------------------------------------------------------------------------------------------------//
		//en esta parte se empieza a ordenar el archivo
		for (int i = 0; i < contlin; i++) {
			arraylineas2[i] = strdup(arrayDeLineas[i]);
		} //tuve que meter las lineas del archivo que estaban en arrayDeLineas dentro del arraylineas2 porque al parecer la funcion
		//strtok le hace cosas raras a arrayDeLineas y le deja inutil

		for (int j = 0; j < contlin; j++) { //esta parte lo que hace es meter los valores de las veces que un jugador gano dentro dell array values, por ejemplo, si luis, que gano 3 veces, y esta como primero en el archivolo que pasara es que en values[0] estará el valor 3, y si martin, que gano 274384 veces, y esta en el lugar 15 de la linea,en values[14] estará el valor 274384
			char *token3 = strtok(arrayDeLineas[j], delimitador);
			while (token3 != NULL) {
				contador = 1;
				char *token4 = strtok(arrayDeLineas[j], delimitador2);
				while (token4 != NULL && contador < 4) {
					if (contador == 2) {
						values[cuenta] = atoi(token4);
					}
					contador++;
					token4 = strtok(NULL, delimitador2);
				}
				token3 = strtok(NULL, delimitador);
				cuenta++;
			}
		}

		for (int i = 0; i < contlin; i++) {
			valori[i] = values[i];
		}

		for (int i = 0; i < contlin; i++) { //ordena de mayor a menor
			for (int j = 0; j < contlin; j++) {
				if (values[i] > values[j]) {
					temp = values[i];
					values[i] = values[j];
					values[j] = temp;
				}
			}
		}
		fp = fopen("/home/lp1-2023/Documentos/Estadisticas", "w");

		for (int i = 0; i < contlin; i++) {

			for (j = 0; j < contlin; j++) {

				if (values[i] == valori[j]) { //compara el array viejo de valores ganadores sin ordenar con el nuevo array, la vd no quiero explicar hay sueño
					fprintf(fp, "%s", arraylineas2[j]);
					valori[j] = -1;
					break;
				}
			}
		}
		fclose(fp);

		for (int j = 0; j < i; j++) {
			free(arrayDeLineas[j]);

		}
	}

	return;

}

 void verificarGanador(int modum){
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
   	}
   	char buffer[100];
   	snprintf(buffer, sizeof(buffer), "%d",jug);
   	gtk_label_set_text(GTK_LABEL(numdado1), buffer);
	char buffer2[100];
   	snprintf(buffer2, sizeof(buffer2), "%d",AI);
   	gtk_label_set_text(GTK_LABEL(numdado2), buffer2);
   	if(cont==25){
   		turno=0;

   		if(AI<jug){
   			if(modum==1){
   			char buffer[100];
   			snprintf(buffer, sizeof(buffer), "El ganador es: %s",nombrejugador1Global);
   			gtk_label_set_text(GTK_LABEL(tablero_nombre_display), buffer);
   			stats(nombrejugador1Global,1);
   			stats(nombrejugador2Global,0);
   			return;

   			}else if(modum==2){
   				char buffer[100];
   				snprintf(buffer, sizeof(buffer), "El ganador es: %s",nombrejugador1Global);
   				gtk_label_set_text(GTK_LABEL(tablero_nombre_display), buffer);
   				//sleep(10);
   				stats(nombrejugador1Global,1);
   				return;


   			}

   		}else {
   		char buffer[100];
   		if(modum==1){
   			snprintf(buffer, sizeof(buffer), "El ganador es: %s",nombrejugador2Global);
   			gtk_label_set_text(GTK_LABEL(tablero_nombre_display2), buffer);
   			stats(nombrejugador1Global,0);//pongo en las estadisticas que jugador1 perdio y que jugador2 ganÓ
   			stats(nombrejugador2Global,1);
   		}
   		if(modum==2){
   			snprintf(buffer, sizeof(buffer), "El ganador es: %s",nombrejugador2Global);
   			gtk_label_set_text(GTK_LABEL(tablero_nombre_display2), buffer);
   			//sleep(10);
   			stats(nombrejugador1Global,0);



   		}
   	}


   	}


   }
