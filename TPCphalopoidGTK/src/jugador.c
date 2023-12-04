#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "funciones.h"
extern GtkWidget *menu_seleccionar,*izquierdaGTK,*derechaGTK,*arribaGTK,*abajoGTK,*menu_tablero,*explicar_display;
extern int lamatriz[26][7][2];
extern int suma;
extern int decisiontomada;
extern int vector[5];

//void enter();
void dadojugador(int pos, int sumas) { //funcion que sirve para poder identificar a los dados de la compu
	if (decisiontomada == 1) {
		lamatriz[pos][sumas][0] = 1; //la compu se identificara por corchete
	}

	if (decisiontomada == 2) {
		lamatriz[pos][sumas][0] = 2; //la compu se identificara por parentesis
	}


}
void dadoUno(int jugada) {
	lamatriz[jugada][0][0] = 1;
	dadojugador(jugada,1);
}
void sumarDado(int suma,int jugada){
	lamatriz[jugada][0][0] = suma;
	dadojugador(jugada,suma);
}
void dadoMas(int invalido,int jugada,int dif){
	int derecha = lamatriz[jugada + 1][0][0];
	int abajo = lamatriz[jugada + 5][0][0];
	int izquierda = lamatriz[jugada - 1][0][0];
	int arriba = lamatriz[jugada - 5][0][0];
	int comprobar=0;
	suma=0;
	vector[0]=izquierda;
	vector[1]=derecha;
	vector[2]=arriba;
	vector[3]=abajo;
	char bufferIZQ[20],bufferDER[20],bufferARR[20],bufferABA[20];
	if (invalido) {
		for(int i=0;i<4;i++){
			if(i==invalido-1){
				vector[i]=0;
			}
		}
	}
	 //verifica si hay alguna suma posible
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				suma=0;
				if((i!=invalido-1&&j!=invalido-1)&&i!=j){
					suma=vector[i]+vector[j];
				}
				if(suma<=6&&suma!=0){
					comprobar++;
				}
			}
		}
	for(int i=0;i<4;i++){
		if(vector[i]==6){
			vector[i]=0;
		}
	}


	if (comprobar!=0) {
		suma=0;
		//Uno a uno se cambia el valor del label de los botones toggle para representar los numeros adyacentes
		snprintf(bufferIZQ, sizeof(bufferIZQ), "Izquierda %d", vector[0]);
		snprintf(bufferDER, sizeof(bufferDER), "Derecha %d", vector[1]);
		snprintf(bufferARR, sizeof(bufferARR), "Arriba %d", vector[2]);
		snprintf(bufferABA, sizeof(bufferABA), "Abajo %d", vector[3]);

		//Los label se ponen en formato para mostrar
		gtk_button_set_label(GTK_BUTTON(izquierdaGTK),(const gchar*) bufferIZQ);
		gtk_button_set_label(GTK_BUTTON(derechaGTK),(const gchar*) bufferDER);
		gtk_button_set_label(GTK_BUTTON(arribaGTK),(const gchar*) bufferARR);
		gtk_button_set_label(GTK_BUTTON(abajoGTK),(const gchar*) bufferABA);
		gtk_label_set_text(GTK_LABEL(explicar_display), "Seleccionar hasta 4\n numeros cuya suma \n sea menor a 6 y mayor a 2");
		gtk_widget_show(menu_seleccionar);
		gtk_widget_hide(menu_tablero);
	}else{dadoUno(jugada);}

}
void ponerDadojugador(int jugada) {
	int derecha = lamatriz[jugada + 1][0][0];
	int abajo = lamatriz[jugada + 5][0][0];
	int izquierda = lamatriz[jugada - 1][0][0];
	int arriba = lamatriz[jugada - 5][0][0];
	int vector[] = { izquierda, derecha, arriba, abajo, '\0' };
	suma = 0;
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
			dadoMas(invalido,jugada,dif);
		} else {
			dadoUno(jugada);
		}
	}
	//ESQUINAS INICIO
	switch (jugada) {
	case 1:
		suma = derecha + abajo;
		if (derecha != 0 && abajo != 0 && (suma < 7&&suma>1)) {
			sumarDado(suma, jugada);
			lamatriz[jugada + 1][0][0] = '\0';
			lamatriz[jugada + 5][0][0] = '\0';
		} else {
			dadoUno(jugada);
		}
		break;

	case 5:
		suma = izquierda + abajo;
		if (izquierda != 0 && abajo != 0 && (suma < 7&&suma>1)) {
			sumarDado(suma, jugada);
			lamatriz[jugada - 1][0][0] = '\0';
			lamatriz[jugada + 5][0][0] = '\0';
		} else {
			dadoUno(jugada);
		}
		break;
	case 21:
		suma = derecha + arriba;
		if (derecha != 0 && arriba != 0 && (suma < 7&&suma>1)) {
			sumarDado(suma, jugada);
			lamatriz[jugada + 1][0][0] = '\0';
			lamatriz[jugada - 5][0][0] = '\0';
		} else {
			dadoUno(jugada);
		}
		break;
	case 25:
		suma = izquierda + arriba;
		if (izquierda != 0 && arriba != 0 && (suma < 7&&suma>1)) {
			sumarDado(suma, jugada);
			lamatriz[jugada - 1][0][0] = '\0';
			lamatriz[jugada - 5][0][0] = '\0';

		} else {
			dadoUno(jugada);
		}
		break;
	}
	//ESQUINAS FIN

	if (jugada == 6 || jugada == 11 || jugada == 16) {
		suma = derecha + arriba + abajo;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma =suma - vector[i];
			}
			if (vector[i] != 0 && i != 0 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if ((suma < 7&&suma>1) && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 1;
			dadoMas(invalido,jugada,dif);
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada == 10 || jugada == 15 || jugada == 20) {
		suma = izquierda + arriba + abajo;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma = suma-vector[i];
			}
			if (vector[i] != 0 && i != 1 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if ((suma < 7&&suma>1) && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 2;
			dadoMas(invalido,jugada,dif);
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada == 2 || jugada == 3 || jugada == 4) {
		suma = izquierda + abajo + derecha;
		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma = suma-vector[i];
			}
			if (vector[i] != 0 && i != 2 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if ((suma < 7&&suma>1) && dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 3;
			dadoMas(invalido,jugada,dif);
		} else {
			dadoUno(jugada);
		}
	}
	if (jugada > 21 && jugada < 25) {
		suma = izquierda + arriba + derecha;

		int j = 0;
		for (int i = 0; i < 4; i++) {
			if (vector[i] == 6) {
				suma =suma- vector[i];
			}
			if (vector[i] != 0 && i != 3 && vector[i] != 6) {
				dif++;
				ubi[j] = ref[i];
				j++;
			}
		}
		if ((suma < 7&&suma>1)&& dif == 2) {
			sumarDado(suma, jugada);
			for (int i = 0; i < dif; i++) {
				lamatriz[jugada + ubi[i]][0][0] = '\0';
			}
		} else if (dif > 2) {
			int invalido = 4;
			dadoMas(invalido,jugada,dif);
		} else {
			dadoUno(jugada);
		}

	}
}


int jugador(int turno, int jugada) {


	turno = 2;
	ponerDadojugador(jugada);
	int dispox=diceposisdispo();
			if(dispox==0){
				turno=0;
			}
	return turno;
}
