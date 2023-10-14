#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern char lamatriz[26][7][2];
extern int posiocupada[1];
extern int turnoinicial;

int computadora(turno){
	int contadordeposis=0;
	turno=1;
	enter();
	if(turnoinicial==2){
		srand(time(NULL));
		int numerorandom = rand() % 25 + 1;
		lamatriz[numerorandom][0][0]=1;
		turnoinicial=1;
		return(turno);
	}else{

		if(posiocupada[1]==1){
			if(lamatriz[2][0][0]=='\0'){
				lamatriz[2][0][0]=1;
				return(turno);
			}


				if(lamatriz[6][0][0]=='\0'){
					lamatriz[6][0][0]=1;
					return(turno);

				}

			}

		if(posiocupada[1]>1 && posiocupada[1]<5){
			if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
				lamatriz[posiocupada[1]-1][0][0]=1;
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							return(turno);
						}
			if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
							lamatriz[posiocupada[1]+5][0][0]=1;
							return(turno);
						}
		}

		if(posiocupada[1]==6 || posiocupada[1]==11 || posiocupada[1]==16 ){
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
				lamatriz[posiocupada[1]-5][0][0]=1;
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							return(turno);
						}
			if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
							lamatriz[posiocupada[1]+5][0][0]=1;
							return(turno);
						}

		}

		if(posiocupada[1]==21){
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
							lamatriz[posiocupada[1]-5][0][0]=1;
							return(turno);
						}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							return(turno);
						}
		}

		if(posiocupada[1]==25){
					if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
									lamatriz[posiocupada[1]-5][0][0]=1;
									return(turno);
								}
					if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
									lamatriz[posiocupada[1]-1][0][0]=1;
									return(turno);
								}
				}


		if(posiocupada[1]>21 && posiocupada[1]<25){
			if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
				lamatriz[posiocupada[1]-1][0][0]=1;
				return(turno);
			}
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
							lamatriz[posiocupada[1]+1][0][0]=1;
							return(turno);
						}
			if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
							lamatriz[posiocupada[1]-5][0][0]=1;
							return(turno);
						}
		}

		if(posiocupada[1]==10 || posiocupada[1]==15 || posiocupada[1]==20 ){
					if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
						lamatriz[posiocupada[1]-5][0][0]=1;
						return(turno);
					}
					if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
									lamatriz[posiocupada[1]-1][0][0]=1;
									return(turno);
								}
					if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
									lamatriz[posiocupada[1]+5][0][0]=1;
									return(turno);
								}

				}


		if((posiocupada[1]>6 && posiocupada[1]<10) || (posiocupada[1]>11 && posiocupada[1]<15) || (posiocupada[1]>16 && posiocupada[1]<20)){
			if(lamatriz[posiocupada[1]+1][0][0]=='\0'){
										lamatriz[posiocupada[1]+1][0][0]=1;
										return(turno);
									}
						if(lamatriz[posiocupada[1]-5][0][0]=='\0'){
										lamatriz[posiocupada[1]-5][0][0]=1;
										return(turno);
									}
						if(lamatriz[posiocupada[1]+5][0][0]=='\0'){
								lamatriz[posiocupada[1]+5][0][0]=1;
								return(turno);
															}
						if(lamatriz[posiocupada[1]-1][0][0]=='\0'){
						lamatriz[posiocupada[1]-1][0][0]=1;
						return(turno);
															}
		}

		if(posiocupada[1]==5){
					if(lamatriz[2][0][0]=='\0'){
						lamatriz[4][0][0]=1;
						return(turno);
					}


						if(lamatriz[6][0][0]=='\0'){
							lamatriz[10][0][0]=1;
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

