#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern char lamatriz[26][7][2];
extern int posiocupada[1];
extern int turnoinicial;

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
int computadora(turno){
	int contadordeposis=0;
	turno=1;
	enter();
	if(turnoinicial==2){
		srand(time(NULL));
		int numerorandom = rand() % 25 + 1;
		lamatriz[numerorandom][0][0]='1';
		turnoinicial=1;
		return(turno);
	}else{

		if(posiocupada[1]==1){
			if(lamatriz[2][0][0]=='\0'){
				lamatriz[2][0][0]='1';
				return(turno);
			}


				if(lamatriz[6][0][0]=='\0'){
					lamatriz[6][0][0]='1';
					return(turno);

				}

			}

		if(posiocupada[1]>1 && posiocupada[1]<5){
			if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
				lamatriz[posiocupada[1]-1][0][0]='1';
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]='1';
							return(turno);
						}
			if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
							lamatriz[posiocupada[1]+5][0][0]='1';
							return(turno);
						}
		}

		if(posiocupada[1]==6 || posiocupada[1]==11 || posiocupada[1]==16 ){
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
				lamatriz[posiocupada[1]-5][0][0]='1';
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]='1';
							return(turno);
						}
			if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
							lamatriz[posiocupada[1]+5][0][0]='1';
							return(turno);
						}

		}

		if(posiocupada[1]==21){
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
							lamatriz[posiocupada[1]-5][0][0]='1';
							return(turno);
						}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]='1';
							return(turno);
						}
		}

		if(posiocupada[1]==25){
					if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
									lamatriz[posiocupada[1]-5][0][0]='1';
									return(turno);
								}
					if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
									lamatriz[posiocupada[1]-1][0][0]='1';
									return(turno);
								}
				}


		if(posiocupada[1]>21 && posiocupada[1]<25){
			if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
				lamatriz[posiocupada[1]-1][0][0]='1';
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]='1';
							return(turno);
						}
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
							lamatriz[posiocupada[1]-5][0][0]='1';
							return(turno);
						}
		}

		if(posiocupada[1]==10 || posiocupada[1]==15 || posiocupada[1]==20 ){
					if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
						lamatriz[posiocupada[1]-5][0][0]='1';
						return(turno);
					}
					if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
									lamatriz[posiocupada[1]-1][0][0]='1';
									return(turno);
								}
					if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
									lamatriz[posiocupada[1]+5][0][0]='1';
									return(turno);
								}

				}


		if((posiocupada[1]>6 && posiocupada[1]<10) || (posiocupada[1]>11 && posiocupada[1]<15) || (posiocupada[1]>16 && posiocupada[1]<20)){
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
										lamatriz[posiocupada[1]+1][0][0]='1';
										return(turno);
									}
						if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
										lamatriz[posiocupada[1]-5][0][0]='1';
										return(turno);
									}
						if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
								lamatriz[posiocupada[1]+5][0][0]='1';
								return(turno);
															}
						if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
						lamatriz[posiocupada[1]-1][0][0]='1';
						return(turno);
															}
		}

		if(posiocupada[1]==5){
					if(lamatriz[2][0][0]=='\0'){
						lamatriz[4][0][0]='1';
						return(turno);
					}


						if(lamatriz[6][0][0]=='\0'){
							lamatriz[10][0][0]='1';
							return(turno);

						}

					}




		srand(time(NULL));
		int numerorandom = rand() % 25 + 1;
		while(lamatriz[numerorandom][0][0]!='\0'){
			srand(time(NULL));
			numerorandom = rand() % 25 + 1;
			lamatriz[numerorandom][0][0]='1';
			return(turno);

		}


	}

return(turno);


}

