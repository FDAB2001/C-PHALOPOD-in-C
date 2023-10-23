#include <stdio.h>
#include <stdlib.h>

extern int lamatriz[26][7][2];
extern int posiocupada[1];

void dadoUno(int jugada) {
	lamatriz[jugada][0][0] = 1;
	lamatriz[jugada][1][0] = 1;
}
void sumarDado(int suma,int jugada){
	lamatriz[jugada][0][0] = suma;
	lamatriz[jugada][suma][0] = 1;
}
void dadoMas(int invalido,int jugada,int dif){
	int derecha = lamatriz[jugada + 1][0][0];
	int abajo = lamatriz[jugada + 5][0][0];
	int izquierda = lamatriz[jugada - 1][0][0];
	int arriba = lamatriz[jugada - 5][0][0];
	int vector[] = { izquierda, derecha, arriba, abajo, '\0' };
	int suma = 0;
	int resp = 0;
	int comercantidad = 0;
	int terminar = 0;
	int ref[] = { -1, +1, -5, +5, '\0' };
	if (!invalido) {
		for(int i=0;i<4;i++){
			if(vector[i]==invalido-1){
				vector[i]=0;
			}
		}
	}
	printf(
			"Existen mas de 2 dados adyacentes, puede elegir cuantos y cuales eliminar siempre y cuando su suma sea menor a 6\n");
	enter();
	suma = 0;
	while (terminar == 0) {
		while (!resp || resp > dif || resp == 1)
			printf("Seleccione cuantos comer ");
			scanf("%d", &resp);
		limpiarBuffer();
		comercantidad = resp;
		resp = 0;
		enter();
		for (int i = 0; i < comercantidad;) {
			printf(
					"Seleccione (1) izquierda (2) derecha (3) arriba (4) abajo: ");
			while (!resp) {
				scanf("%d", &resp);
				limpiarBuffer();
				for (int j = 0; j < 4 && resp != 0; j++) {
					if (vector[resp - 1] == 0) {
						printf("La posicion seleccionada no tiene un dado \n");
						resp = 0;
					} else if (vector[resp - 1] == 6) {
						printf(
								"La posicion seleccionada tiene un dado de valor 6, semejante acto es invalido \n");
						resp = 0;
					}
				}
			}
			printf("Posicion seleccionada %d \n", resp);
			printf("Suma actual=%d, lo cual sera %d si decides sumar\n", suma,suma+vector[resp-1]);
			printf("¿Aceptas la suma? (1) si (2) no :");
			int temp = 0;
			while (temp > 2 || temp < 1)
				scanf("%d", &temp);
			limpiarBuffer();
			enter();
			if (suma < 7) {
				if (temp == 1) {
					if (suma + vector[resp - 1] < 7) {
						suma += vector[resp - 1];

						lamatriz[jugada + ref[resp - 1]][0][0] = '\0';

						i++;
					} else {
						printf(
								"La posicion seleccionada otorga una suma invalida, secuencia reiniciada");
						resp = 0;
					}
				} else {
					printf("Secuencia reiniciada por negacion a la suma\n");
					resp = 0;
				}
			} else {
				printf("La suma actual es 6, cerrando secuencia");
				comercantidad--;
			}
			resp = 0;
		}
		terminar++;
	}
	sumarDado(suma, jugada);
}
void ponerDadojugador(int jugada) {
	int derecha = lamatriz[jugada + 1][0][0];
	int abajo = lamatriz[jugada + 5][0][0];
	int izquierda = lamatriz[jugada - 1][0][0];
	int arriba = lamatriz[jugada - 5][0][0];
	int vector[] = { izquierda, derecha, arriba, abajo, '\0' };
	int suma = 0;
	int resp = 0;
	int comercantidad = 0;
	int terminar = 0;
	int ref[] = { -1, +1, -5, +5, '\0' };
	int dif = 0;
	int ubi[4];

	if ((jugada > 6 && jugada < 10) || (jugada > 11 && jugada < 15)
			|| (jugada > 16 && jugada < 20)) {
		suma = izquierda + derecha + arriba + abajo;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma -= vector[i];
			}
			if (vector[i] != 0 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if (suma < 7 && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 0;
		} else {
			dadoUno(jugada);
		}
	}
	//ESQUINAS INICIO
	if (jugada == 1) {
		suma = derecha + abajo;
		if (derecha != 0 && abajo != 0 && suma < 7) {
			sumarDado(suma, jugada);
			lamatriz[jugada + 1][0][0] = '\0';
			lamatriz[jugada + 5][0][0] = '\0';
		} else {
			dadoUno(jugada);
		}

	}
	if (jugada == 5) {
		suma = izquierda + abajo;
		if (izquierda != 0 && abajo != 0 && suma < 7) {
			sumarDado(suma, jugada);
			lamatriz[jugada - 1][0][0] = '\0';
			lamatriz[jugada + 5][0][0] = '\0';
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada == 21) {
		suma = derecha + arriba;
		if (derecha != 0 && arriba != 0 && suma < 7) {
			sumarDado(suma, jugada);
			lamatriz[jugada + 1][0][0] = '\0';
			lamatriz[jugada - 5][0][0] = '\0';
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada == 25) {
		suma = izquierda + arriba;
		if (izquierda != 0 && arriba != 0 && suma < 7) {
			sumarDado(suma, jugada);
			lamatriz[jugada - 1][0][0] = '\0';
			lamatriz[jugada - 5][0][0] = '\0';

		} else {
			dadoUno(jugada);
		}
	}
	//ESQUINAS FIN

	if (jugada == 6 || jugada == 11 || jugada == 16) {
		suma = derecha + arriba + abajo;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma -= vector[i];
			}
			if (vector[i] != 0 && i != 0 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if (suma < 7 && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 1;
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada == 10 || jugada == 15 || jugada == 20) {
		suma = izquierda + arriba + abajo;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma -= vector[i];
			}
			if (vector[i] != 0 && i != 1 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if (suma < 7 && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 2;
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada == 2 || jugada == 3 || jugada == 4) {
		suma = izquierda + abajo + derecha;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma -= vector[i];
			}
			if (vector[i] != 0 && i != 2 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if (suma < 7 && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 3;
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada > 21 && jugada < 25) {
		suma = izquierda + arriba + derecha;

		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma -= vector[i];
			}
			if (vector[i] != 0 && i != 3 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if (suma < 7 && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 4;
		} else {
			dadoUno(jugada);
		}

	}
}

int validarJugada() {
	int posicion = 0;
	while ((posicion < 1 || posicion > 25)) {
		printf("Seleccione una posicion: ");
		scanf("%d", &posicion);
		limpiarBuffer();
		enter();
		if (lamatriz[posicion][0][0] != '\0'||lamatriz[posicion][0][0]!=0) {
			printf("La posicion tiene un dado");
			enter();
			posicion = 0;
		}
	}
	return posicion;
}

int jugador(int turno) {

	printf("Seleccione en que casilla del 1 al 25 para poner el dado\n");

	int jugada = validarJugada();
	posiocupada[1] = jugada;
	turno = 2;
	ponerDadojugador(jugada);
	return turno;
}
