#include <stdlib.h>
#include <time.h>

extern int lamatriz[26][7][2];
extern int posiocupada[1]; //aca se guarda la posicion que eligio el usuario
extern int turnoinicial; //"Traigo" el valor del turnoinicial para saber quien comienza
int contador=0; //valor que usaremos despues
int arrayposiciones[4]; //array con las posiciones con dados alrededor de donde puso la compu su dado


void ponerDado(int jugada){
	//printf("Jgada vale %d\n",jugada);
	printf("jugada vale %d\n",jugada);

	//en esta funcion, lo que pasa es que recibe el parametro de la posicion donde la compu eligio poner su dado,
	//y lo que hace la funcion es revisar si se puede sumar algo, y lo hace dividiendo en secciones:
	//las esquinas 1,5,21,25; las filas de arriba: 2<x<5; las filas de abajo 21<x<25;
	//las columnas del costado izquierdo y derecho respectivamente: x == 6 || 11 || 16 ; x == 10 || 15 || 20
	//y la seccion mas grande que seria el bloque del medio: 6<x<10;11<x<15;16<x<20

	if((jugada>1)&&(jugada<5)){

contador=0;
		    if (lamatriz[jugada - 1][0][0] != '\0')
		        contador++;
		    if (lamatriz[jugada + 1][0][0] != '\0')
		        contador++;
		     if (lamatriz[jugada + 5][0][0] != '\0')
		        contador++;
//aca lo que hace el contador es contar las veces que encunetra que en una posicion no esta vacio, osea, hay un dado
//primero a la izquierda, depues a la derecha y despues abajo del dado

		printf("contador vale %d\n",contador);

if(contador<2){
	lamatriz[jugada][1][0]=2;
}

		if(contador==2){
			//si el contador llega a 2, solo sumara la posicion izq (jugada-1) y derecha(jugada+1), y revisa si se puede sumar para no pasar de 7 y si las posiciones estan vacias, si una de ellas esta vacia, ya no se suma obviamente
			if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-1][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-1][0][0])<7){
				lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada-1][0][0];

				int suma=lamatriz[jugada][0][0];
				lamatriz[jugada][suma][0]=2; //estas dos lineas para lo que sirven es para identificar que es el dado de la compu

				lamatriz[jugada+1][0][0]=0;
				lamatriz[jugada-1][0][0]=0;// como ya se sumo, vuelvo su valor a cero
			} //eso es basicamente lo que hago todo el rato en esta funcion

			if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0])<7){
				lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0];

				int suma=lamatriz[jugada][0][0];
				lamatriz[jugada][suma][0]=2;

				lamatriz[jugada+1][0][0]=0;
				lamatriz[jugada+5][0][0]=0;
			}

			if(lamatriz[jugada-1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0' && (lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0])<7){
				lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0];

				int suma=lamatriz[jugada][0][0];
				lamatriz[jugada][suma][0]=2;

				lamatriz[jugada-1][0][0]=0;
				lamatriz[jugada+5][0][0]=0;

			}
			contador=0;
			return; //y el return obvio para salir ya de la funcion porque ya se cumplio una de las condiciones
		}
		if(contador==3 && (lamatriz[jugada-1][0][0]+lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0])<7){
			//si el contador llega a 3 significa que hay 3 dados para que pueda sumar
			lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0];

			int suma=lamatriz[jugada][0][0];
			lamatriz[jugada][suma][0]=2;

			lamatriz[jugada-1][0][0]=0;
			lamatriz[jugada+1][0][0]=0;
			lamatriz[jugada+5][0][0]=0;

			int jugada2=jugada+1;
			int jugada3=jugada-1;
			int jugada4=jugada+5; //estas declaraciones son solamente para poder imprimir como se ve a continuacion
			printf("La compu eligió sumar las posiciones %d,%d y %d\n",jugada2,jugada3,jugada4);
			contador=0;
			return;

		}

	}

	if(jugada==1){

				if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0])<7){
					lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0];

					int suma=lamatriz[jugada][0][0];
					lamatriz[jugada][suma][0]=2;

					lamatriz[jugada+1][0][0]=0;
					lamatriz[jugada+5][0][0]=0;
				}
				contador=0;
				return;

		}//termina

	if(jugada==5){

					if(lamatriz[jugada-1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0' && (lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0])<7){
						lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[jugada-1][0][0]=0;
						lamatriz[jugada+5][0][0]=0;
					}
					contador=0;
					return;

			}//termina

	if(jugada==21){

						if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada+1][0][0]=0;
							lamatriz[jugada-5][0][0]=0;
						}
						contador=0;
						return;

				}//termina

	if(jugada==25){

						if(lamatriz[jugada-1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada-1][0][0]=0;
							lamatriz[jugada-5][0][0]=0;
						}
						contador=0;
						return;

				}

	if((jugada>21)&&(jugada<25)){
contador=0;

			    if (lamatriz[jugada - 1][0][0] != '\0')
			        contador++;
			    if (lamatriz[jugada + 1][0][0] != '\0')
			        contador++;
			     if (lamatriz[jugada - 5][0][0] != '\0')
			        contador++;


			printf("contador vale %d\n",contador);



			if(contador==2){
				if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-1][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-1][0][0])<7){
					lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada-1][0][0];

					int suma=lamatriz[jugada][0][0];
					lamatriz[jugada][suma][0]=2;

					lamatriz[jugada+1][0][0]=0;
					lamatriz[jugada-1][0][0]=0;
				}

				if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0])<7){
					lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0];

					int suma=lamatriz[jugada][0][0];
					lamatriz[jugada][suma][0]=2;

					lamatriz[jugada+1][0][0]=0;
					lamatriz[jugada-5][0][0]=0;
				}

				if(lamatriz[jugada-1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0])<7){
					lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0];

					int suma=lamatriz[jugada][0][0];
					lamatriz[jugada][suma][0]=2;

					lamatriz[jugada-1][0][0]=0;
					lamatriz[jugada-5][0][0]=0;


				}
				contador=0;
				return;
			}

			if(contador==3 && (lamatriz[jugada-1][0][0]+lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0])<7){
				lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0];

				int suma=lamatriz[jugada][0][0];
				lamatriz[jugada][suma][0]=2;

				lamatriz[jugada-1][0][0]=0;
				lamatriz[jugada+1][0][0]=0;
				lamatriz[jugada-5][0][0]=0;

				int jugada2=jugada+1;
				int jugada3=jugada-1;
				int jugada4=jugada-5;
				printf("La compu eligió sumar las posiciones %d,%d y %d\n",jugada2,jugada3,jugada4);
				contador=0;
				return;

			}



		}//termina

	if((jugada==6)||(jugada==11)||(jugada==16)){ //comienza
contador=0;

				    if (lamatriz[jugada +5][0][0] != '\0')
				        contador++;
				    if (lamatriz[jugada + 1][0][0] != '\0')
				        contador++;
				     if (lamatriz[jugada - 5][0][0] != '\0')
				        contador++;


				printf("contador vale %d\n",contador);



				if(contador==2 && (lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0])<7){
					if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0'){
						lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[jugada+1][0][0]=0;
						lamatriz[jugada+5][0][0]=0;
					}

					if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0])<7){
						lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[jugada+1][0][0]=0;
						lamatriz[jugada-5][0][0]=0;
					}

					if(lamatriz[jugada+5][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada-5][0][0]+lamatriz[jugada+5][0][0])<7){
						lamatriz[jugada][0][0]=lamatriz[jugada+5][0][0]+lamatriz[jugada-5][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[jugada+5][0][0]=0;
						lamatriz[jugada-5][0][0]=0;


					}
					contador=0;
					return;
				}

				if(contador==3 && (lamatriz[jugada+5][0][0]+lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0])<7){ //si el contador llega a 3 significa que hay 3 dados para que pueda sumar
					lamatriz[jugada][0][0]=lamatriz[jugada+5][0][0]+lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0];

					int suma=lamatriz[jugada][0][0];
					lamatriz[jugada][suma][0]=2;

					lamatriz[jugada+5][0][0]=0;
					lamatriz[jugada+1][0][0]=0;
					lamatriz[jugada-5][0][0]=0;

					int jugada2=jugada+1;
					int jugada3=jugada+5;
					int jugada4=jugada-5;
					printf("La compu eligió sumar las posiciones %d,%d y %d\n",jugada2,jugada3,jugada4);
					contador=0;
					return;

				}

			}//termina

	if((jugada==10)||(jugada==15)||(jugada==20)){ //comienza

contador=0;
					    if (lamatriz[jugada +5][0][0] != '\0')
					        contador++;
					    if (lamatriz[jugada - 1][0][0] != '\0')
					        contador++;
					     if (lamatriz[jugada - 5][0][0] != '\0')
					        contador++;


					printf("contador vale %d\n",contador);



					if(contador==2 && (lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0])<7){
						if(lamatriz[jugada-1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0'){
							lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada-1][0][0]=0;
							lamatriz[jugada+5][0][0]=0;
						}

						if(lamatriz[jugada-1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada-1][0][0]=0;
							lamatriz[jugada-5][0][0]=0;
						}

						if(lamatriz[jugada+5][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada-5][0][0]+lamatriz[jugada+5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada+5][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada+5][0][0]=0;
							lamatriz[jugada-5][0][0]=0;


						}
						contador=0;
						return;
					}

					if(contador==3 && (lamatriz[jugada+5][0][0]+lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0])<7){ //si el contador llega a 3 significa que hay 3 dados para que pueda sumar
						lamatriz[jugada][0][0]=lamatriz[jugada+5][0][0]+lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[jugada+5][0][0]=0;
						lamatriz[jugada-1][0][0]=0;
						lamatriz[jugada-5][0][0]=0;

						int jugada2=jugada-1;
						int jugada3=jugada+5;
						int jugada4=jugada-5;
						printf("La compu eligió sumar las posiciones %d,%d y %d\n",jugada2,jugada3,jugada4);
						contador=0;
						return;

					}

				}//termina

	if((jugada>6 && jugada<10) || (jugada>11 && jugada<15) || (jugada>16 && jugada<20)){ //comienza
		//este es el bloque denso, se pueden sumar de a 4 y de todas las direcciones, entonces lo que hago es
		//almacenar en en array las posiciones donde se cumplio la condicion del if que vemos abajo para depues agarrar esos valores
		//y sumar
contador=0;

					    if (lamatriz[jugada +5][0][0] != '\0'){
					        arrayposiciones[contador]=jugada +5; //meto las posiciones donde se encontro un dado en el array en la posicion contador, esto para usar despues
					    	contador++;
					    }
					    if (lamatriz[jugada + 1][0][0] != '\0'){
					    	arrayposiciones[contador]=jugada +1;
					    	contador++;
					    }
					     if (lamatriz[jugada - 5][0][0] != '\0'){
					    	 arrayposiciones[contador]=jugada -5;
					    	 contador++;
					     }
					     if (lamatriz[jugada -1][0][0] != '\0'){
					    	 arrayposiciones[contador]=jugada -1;
					    	 contador++;
					     }



					printf("contador vale %d\n",contador);



					if(contador==2){
						if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada+5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada+5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada+1][0][0]=0;
							lamatriz[jugada+5][0][0]=0; //suma lo que hay a su derecha y lo que hay abajo
						}

						if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada+1][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada+1][0][0]=0;
							lamatriz[jugada-5][0][0]=0;//suma lo que hay a su derecha y lo que hay arriba
						}

						if(lamatriz[jugada+5][0][0]!='\0' && lamatriz[jugada-5][0][0]!='\0' && (lamatriz[jugada+5][0][0]+lamatriz[jugada-5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada+5][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada+5][0][0]=0;
							lamatriz[jugada-5][0][0]=0;//suma lo que hay arriba y lo que hay abajo
						}

						if(lamatriz[jugada-5][0][0]!='\0' && lamatriz[jugada-1][0][0]!='\0' && (lamatriz[jugada-5][0][0]+lamatriz[jugada-1][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada-5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada-1][0][0]=0;
							lamatriz[jugada-5][0][0]=0; //suma lo que hay a su izquierda y lo que hay abajo
						}

						if(lamatriz[jugada+5][0][0]!='\0' && lamatriz[jugada-1][0][0]!='\0' && (lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+5][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada-1][0][0]=0;
							lamatriz[jugada+5][0][0]=0;//suma lo que hay a su izquierda y lo que hay arriba
						}

						if(lamatriz[jugada+1][0][0]!='\0' && lamatriz[jugada-1][0][0]!='\0' && (lamatriz[jugada+1][0][0]+lamatriz[jugada-1][0][0])<7){
							lamatriz[jugada][0][0]=lamatriz[jugada-1][0][0]+lamatriz[jugada+1][0][0];

							int suma=lamatriz[jugada][0][0];
							lamatriz[jugada][suma][0]=2;

							lamatriz[jugada+1][0][0]=0;
							lamatriz[jugada-1][0][0]=0;//suma lo que hay a su derecha y lo que hay a su izquierda
						}


						contador=0;
						return;
					}

					int posi1=arrayposiciones[0];
					int posi2=arrayposiciones[1];
					int posi3=arrayposiciones[2];
					int posi4=arrayposiciones[4];
					//aca es donde entra el array de posiciones, tenia miedo de que me diga que me ponga algo raro si
					//ponia directamente arrayposiciones[4], por eso declare cada un entero para cada posicion


					if(contador==3 && (lamatriz[posi1][0][0]+lamatriz[posi2][0][0]+lamatriz[posi3][0][0])<7){ //si el contador llega a 3 significa que hay 3 dados para que pueda sumar

						lamatriz[jugada][0][0]=lamatriz[posi1][0][0]+lamatriz[posi2][0][0]+lamatriz[posi3][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[posi1][0][0]=0;
						lamatriz[posi2][0][0]=0;
						lamatriz[posi3][0][0]=0;

						printf("La compu eligió sumar las posiciones %d,%d y %d\n",posi1,posi2,posi3);
						contador=0;
						return;

					}


					if(contador==4 && (lamatriz[posi1][0][0]+lamatriz[posi2][0][0]+lamatriz[posi3][0][0]+lamatriz[posi4][0][0])<7){ //si el contador llega a 3 significa que hay 4 dados para que pueda sumar


						lamatriz[jugada][0][0]=lamatriz[posi1][0][0]+lamatriz[posi2][0][0]+lamatriz[posi3][0][0]+lamatriz[posi4][0][0];

						int suma=lamatriz[jugada][0][0];
						lamatriz[jugada][suma][0]=2;

						lamatriz[posi1][0][0]=0;
						lamatriz[posi2][0][0]=0;
						lamatriz[posi3][0][0]=0;
						lamatriz[posi4][0][0]=0;

						printf("La compu eligió sumar las posiciones %d,%d,%d y %d\n",posi1,posi2,posi3,posi4);
						contador=0;
						return;

										}



				}//termina
lamatriz[jugada][1][0]=2;

return;

}
int computadora(turno){

	turno=1;

	if(turnoinicial==2){

		srand(time(NULL));
		int numerorandom = rand() % 26;
		lamatriz[numerorandom][0][0]=1;
		printf("\n numero random %d",numerorandom);
		printf("\n posicion %d",lamatriz[numerorandom][0][0]);
		turnoinicial=1;
		return(turno); //en el caso de que el usuario quiera que la compu comience, tira uno random
	}else{
		//yo no sabia que podia ser simplemente random la posicion que elegia la compu, entonces su funcionamiento, que es de lo mas
		//basico, seria el siguiente:agarra la posicion que eligio el usuario y la compu ve si puede colocar su dado arriba, abajo,
		//a la izquierda o a la derecha, y si no puede, tira uno random, y se dividen como en la fucncion de arriba (computadora):
		//columnas izquierda y derecha, filas de arriba y abajo, y el bloque denso del medio

		if(posiocupada[1]==1){
			if(lamatriz[2][0][0]=='\0'){
						lamatriz[2][0][0]=1;
						ponerDado(2);
						return(turno);
					}

			if(lamatriz[6][0][0]=='\0'){
				lamatriz[6][0][0]=1;
				ponerDado(6);
				return(turno);
			}
		}

		if(posiocupada[1]>1 && posiocupada[1]<5){
			if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
				lamatriz[posiocupada[1]-1][0][0]=1;
				ponerDado(posiocupada[1]-1);
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							ponerDado(posiocupada[1]+1);
							return(turno);
						}
			if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
							lamatriz[posiocupada[1]+5][0][0]=1;
							ponerDado(posiocupada[1]+5);
							return(turno);
						}
		}

		if(posiocupada[1]==6 || posiocupada[1]==11 || posiocupada[1]==16 ){
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
				lamatriz[posiocupada[1]-5][0][0]=1;
				ponerDado(posiocupada[1]-5);
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							ponerDado(posiocupada[1]+1);
							return(turno);
						}
			if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
							lamatriz[posiocupada[1]+5][0][0]=1;
							ponerDado(posiocupada[1]+5);
							return(turno);
						}

		}

		if(posiocupada[1]==21){
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
							lamatriz[posiocupada[1]-5][0][0]=1;
							ponerDado(posiocupada[1]-5);
							return(turno);
						}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							ponerDado(posiocupada[1]+1);
							return(turno);
						}
		}

		if(posiocupada[1]==25){
					if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
									lamatriz[posiocupada[1]-5][0][0]=1;
									ponerDado(posiocupada[1]-5);
									return(turno);
								}
					if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
									lamatriz[posiocupada[1]-1][0][0]=1;
									ponerDado(posiocupada[1]-1);
									return(turno);
								}
				}


		if(posiocupada[1]>21 && posiocupada[1]<25){
			if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
				lamatriz[posiocupada[1]-1][0][0]=1;
				ponerDado(posiocupada[1]-1);
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							ponerDado(posiocupada[1]+1);
							return(turno);
						}
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
							lamatriz[posiocupada[1]-5][0][0]=1;
							ponerDado(posiocupada[1]-5);
							return(turno);
						}
		}

		if(posiocupada[1]==10 || posiocupada[1]==15 || posiocupada[1]==20 ){
					if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
						lamatriz[posiocupada[1]-5][0][0]=1;
						ponerDado(posiocupada[1]-5);
						return(turno);
					}
					if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
									lamatriz[posiocupada[1]-1][0][0]=1;
									ponerDado(posiocupada[1]-1);
									return(turno);
								}
					if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
									lamatriz[posiocupada[1]+5][0][0]=1;
									ponerDado(posiocupada[1]+5);
									return(turno);
								}

				}


		if((posiocupada[1]>6 && posiocupada[1]<10) || (posiocupada[1]>11 && posiocupada[1]<15) || (posiocupada[1]>16 && posiocupada[1]<20)){
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
										lamatriz[posiocupada[1]+1][0][0]=1;
										ponerDado(posiocupada[1]+1);
										return(turno);
									}
						if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
										lamatriz[posiocupada[1]-5][0][0]=1;
										ponerDado(posiocupada[1]-5);
										return(turno);
									}
						if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
								lamatriz[posiocupada[1]+5][0][0]=1;
								ponerDado(posiocupada[1]+5);
								return(turno);
															}
						if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
						lamatriz[posiocupada[1]-1][0][0]=1;
						ponerDado(posiocupada[1]-1);
						return(turno);
															}
		}

		if(posiocupada[1]==5){
					if(lamatriz[4][0][0]=='\0'){
						lamatriz[4][0][0]=1;
						ponerDado(4);

						return(turno);
					}


						if(lamatriz[10][0][0]=='\0'){
							lamatriz[10][0][0]=1;
							ponerDado(10);
							return(turno);

						}

					}

		//ya si ningun if se cumple, se crea un numero aleatorio que debe cumplir que no sea cero y que la posicion de este numero
		//random debe estar vacio
		printf("vale pene 123 \n");
		srand(time(NULL));
		int numerorandom = rand() % 25 + 1;

		while(lamatriz[numerorandom][0][0]!='\0' || numerorandom==0){
			srand(time(NULL));
			numerorandom = rand() % 25 + 1;
			printf("\n vale peneeeeeeeee \n");
		}
		lamatriz[numerorandom][0][0]=1;

		ponerDado(numerorandom);

		return(turno);

	}

return(turno);


}
