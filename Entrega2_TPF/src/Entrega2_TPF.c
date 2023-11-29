#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
#include "jugador.h"
#include "computadora.h"
#include <stdint.h>
#define GET_WIDGET(builder, name) GTK_WIDGET(gtk_builder_get_object(builder, name))
//el filepath del glade para rapido acceso y uso
#define GLADE_FILE_PATH "Tpfinal2.glade"
//macro para los 25 botones, asi es mas facil escribir codigo
#define conectar(i, func) g_signal_connect(tablero[i], "clicked", G_CALLBACK(func), tablero[i])
extern int jugadaGTK;
extern int lamatriz[26][7][2];
extern int decisiontomada;
void vaciar_matriz();
int numeroAleatorio();
void imprimir_matriz();
void actualizar_GTK();
const gchar *nombre_jugador = NULL;
const gchar *nombre_jugador2 = NULL;
extern int jugar_pressed;
extern int modo;
extern int suma;
extern int vector[5];
int temp1;
int temp2;
int temp3;
int temp4;
GtkBuilder *constructor;
//Ventana opciones
GtkWidget *menu_opciones, *opciones_jcj, *opciones_JCIA,
		*opciones_iacia, *opciones_corchetes, *opciones_parentesis,
		*opciones_aleatorio, *opciones_jugar, *opciones_salir,*opciones_nombre,*opciones_nombre2;
//Ventana creadores
GtkWidget *menu_creadores, *creadores_salir;

//Ventana como jugar
GtkWidget *menu_como_jugar, *como_jugar_cerrar;
//Ventana tablero
GtkWidget *menu_tablero, *tablero_reiniciar, *tablero_opciones,
		*tablero_como_jugar, *tablero_creditos,*tablero_nombre_display,*tablero_nombre_display2;
//Botones
GtkWidget *BOTON1,*BOTON2,*BOTON3,*BOTON4,*BOTON5,*BOTON6,*BOTON7,*BOTON8,*BOTON9,*BOTON10,*BOTON11,*BOTON12,*BOTON13,*BOTON14,*BOTON15,*BOTON16,*BOTON17,*BOTON18,*BOTON19,*BOTON20,*BOTON21,*BOTON22,*BOTON23,*BOTON24,*BOTON25;
//Ventana seleccionar
GtkWidget *menu_seleccionar,*seleccionar_confirmar,*izquierdaGTK,*derechaGTK,*arribaGTK,*abajoGTK,*suma_display,*explicar_display;
void declarar_widgets() {
	//Declaraciones de la ventana opciones
	menu_opciones = GET_WIDGET(constructor, "menu_opciones");
	opciones_jcj = GET_WIDGET(constructor, "menu_opciones_jcj");
	opciones_JCIA = GET_WIDGET(constructor, "menu_opciones_jugador_contra_IA");
	opciones_iacia = GET_WIDGET(constructor, "menu_opciones_iacia");
	opciones_corchetes = GET_WIDGET(constructor, "menu_opciones_corchetes");
	opciones_parentesis = GET_WIDGET(constructor, "menu_opciones_parentesis");
	opciones_aleatorio = GET_WIDGET(constructor, "menu_opciones_aleatorio");
	opciones_nombre = GET_WIDGET(constructor, "menu_opciones_nombre");
	opciones_nombre2= GET_WIDGET(constructor, "menu_opciones_nombre2");
	opciones_jugar = GET_WIDGET(constructor, "menu_opciones_jugar");
	opciones_salir = GET_WIDGET(constructor, "menu_opciones_salir");

	//Declaraciones de la ventana creadores
	menu_creadores = GET_WIDGET(constructor, "menu_creadores");
	creadores_salir = GET_WIDGET(constructor, "menu_creadores_salir");
	//Declaraciones de la ventana como jugar
	menu_como_jugar = GET_WIDGET(constructor, "menu_como_jugar");
	como_jugar_cerrar = GET_WIDGET(constructor, "menu_como_jugar_cerrar");
	//Declaraciones tablero
	menu_tablero = GET_WIDGET(constructor, "menu_tablero");
	tablero_nombre_display = GET_WIDGET(constructor,
			"menu_tablero_nombre_display");
	tablero_nombre_display2=GET_WIDGET(constructor,
			"menu_tablero_nombre_display2");
	tablero_reiniciar = GET_WIDGET(constructor, "menu_tablero_reiniciar");
	tablero_opciones = GET_WIDGET(constructor, "menu_tablero_opciones");
	tablero_como_jugar = GET_WIDGET(constructor, "menu_tablero_como_jugar");
	tablero_creditos = GET_WIDGET(constructor, "menu_tablero_creditos");
	//Declaraciones menu seleccionar
	menu_seleccionar= GET_WIDGET(constructor, "menu_seleccionar");
	seleccionar_confirmar=GET_WIDGET(constructor, "menu_seleccionar_confirmar");
	suma_display=GET_WIDGET(constructor,"menu_seleccionar_sumadisplay");
	explicar_display=GET_WIDGET(constructor,"menu_seleccionar_explicar");
	izquierdaGTK=GET_WIDGET(constructor,"menu_seleccionar_izquierda");
	derechaGTK=GET_WIDGET(constructor,"menu_seleccionar_derecha");
	arribaGTK=GET_WIDGET(constructor,"menu_seleccionar_arriba");
	abajoGTK=GET_WIDGET(constructor,"menu_seleccionar_abajo");


	//Declaraciones botones
	BOTON1 = GET_WIDGET(constructor, "menu_tablero_boton_1");
	BOTON2 = GET_WIDGET(constructor, "menu_tablero_boton_2");
	BOTON3 = GET_WIDGET(constructor, "menu_tablero_boton_3");
	BOTON4 = GET_WIDGET(constructor, "menu_tablero_boton_4");
	BOTON5 = GET_WIDGET(constructor, "menu_tablero_boton_5");
	BOTON6 = GET_WIDGET(constructor, "menu_tablero_boton_6");
	BOTON7 = GET_WIDGET(constructor, "menu_tablero_boton_7");
	BOTON8 = GET_WIDGET(constructor, "menu_tablero_boton_8");
	BOTON9 = GET_WIDGET(constructor, "menu_tablero_boton_9");
	BOTON10 = GET_WIDGET(constructor, "menu_tablero_boton_10");
	BOTON11 = GET_WIDGET(constructor, "menu_tablero_boton_11");
	BOTON12 = GET_WIDGET(constructor, "menu_tablero_boton_12");
	BOTON13 = GET_WIDGET(constructor, "menu_tablero_boton_13");
	BOTON14 = GET_WIDGET(constructor, "menu_tablero_boton_14");
	BOTON15 = GET_WIDGET(constructor, "menu_tablero_boton_15");
	BOTON16 = GET_WIDGET(constructor, "menu_tablero_boton_16");
	BOTON17 = GET_WIDGET(constructor, "menu_tablero_boton_17");
	BOTON18 = GET_WIDGET(constructor, "menu_tablero_boton_18");
	BOTON19 = GET_WIDGET(constructor, "menu_tablero_boton_19");
	BOTON20 = GET_WIDGET(constructor, "menu_tablero_boton_20");
	BOTON21 = GET_WIDGET(constructor, "menu_tablero_boton_21");
	BOTON22 = GET_WIDGET(constructor, "menu_tablero_boton_22");
	BOTON23 = GET_WIDGET(constructor, "menu_tablero_boton_23");
	BOTON24 = GET_WIDGET(constructor, "menu_tablero_boton_24");
	BOTON25 = GET_WIDGET(constructor, "menu_tablero_boton_25");
}

//1 jcj 2 jcia 3 iacia

//Las siguientes 6 funciones togglean el boton seleccionado al mismo tiempo que destoglea el resto de botones
//En el menu opciones, los primeros 3 botones toggleables
void TOGLEADO_JCJ(GtkToggleButton *widget, gpointer data) {
	if (gtk_toggle_button_get_active(widget)) {
		// Botón JCJ activado
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_JCIA), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_iacia), FALSE);
		modo=1;
	}
}

void TOGLEADO_JCIA(GtkToggleButton *widget, gpointer data) {
	if (gtk_toggle_button_get_active(widget)) {
		// Botón JUGADOR CONTRA IA activado
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_jcj), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_iacia), FALSE);
		modo=2;
	}
}
void TOGLEADO_IACIA(GtkToggleButton *widget, gpointer data) {
	if (gtk_toggle_button_get_active(widget)) {
		// Botón IACIA activado
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_JCIA), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_jcj), FALSE);
		modo=3;
	}
}
//En el menu opciones, los segundos 3 botones toggleables
void TOGLEADO_PAR(GtkToggleButton *toggle_button, gpointer data) {
	if (gtk_toggle_button_get_active(toggle_button)) {
		// Botón PARENTESIS activado
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_corchetes),
				FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_aleatorio),
				FALSE);
		decisiontomada=1;//cuando decisiontomada==1, el usuario quiere ser parentesis, compu será corchete
	}
}
void TOGLEADO_COR(GtkToggleButton *toggle_button, gpointer data) {
	if (gtk_toggle_button_get_active(toggle_button)) {
		// Botón CORCHETES activado
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_parentesis),
				FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_aleatorio),
				FALSE);
		decisiontomada=2;//cuando decisiontomada==2, el usuario quiere ser corchete, compu será parentesis



	}
}

void TOGLEADO_ALE(GtkToggleButton *toggle_button, gpointer data) {
	if (gtk_toggle_button_get_active(toggle_button)) {
		// Botón ALEATORIO activado
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_corchetes),
				FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(opciones_parentesis),
				FALSE);
		decisiontomada= numeroAleatorio(2, 1);
	}
}

//Funcion del tablero
void ABRIR_TABLERO(GtkWidget *widget, gpointer data) {
	if (decisiontomada!=0 && modo!=0) {
		if(decisiontomada==2){
		computadora(1);
		actualizar_GTK();
		}
		jugar_pressed = 0; // Así el loop termina cuando se presiona salir

		// Obtén el nombre del jugador del widget de entrada de texto
		// desde aquí se manejan los nombres de los jugadores si se seleccionó 1
		const gchar *nombre = gtk_entry_get_text(GTK_ENTRY(opciones_nombre));
		const gchar *nombre2 = gtk_entry_get_text(GTK_ENTRY(opciones_nombre2));

		if (modo == 1) {
			// Verifica que el nombre no esté vacío antes de asignarlo
			if (nombre2 != NULL && g_strcmp0(nombre2, "") != 0) {
				// Limita la longitud del nombre para evitar desbordamientos
				const gsize max_length2 = 50;  // Establece la longitud
				gchar nombre_limitado2[max_length2 + 1];  // +1 para el carácter nulo
				g_strlcpy(nombre_limitado2, nombre2, max_length2 + 1);

				nombre_jugador2 = g_strdup(nombre_limitado2); // Copia el nombre limitado
			} else {
				// Proporciona un valor predeterminado
				nombre_jugador2 = "La Computadora";
			}
		}

		// Verifica que el nombre no esté vacío antes de asignarlo
		if (nombre != NULL && g_strcmp0(nombre, "") != 0) {
			// Limita la longitud del nombre para evitar desbordamientos
			const gsize max_length = 50;  // Establece la longitud
			gchar nombre_limitado[max_length + 1];  // +1 para el carácter nulo
			g_strlcpy(nombre_limitado, nombre, max_length + 1);

			nombre_jugador = g_strdup(nombre_limitado);  // Copia el nombre limitado
		} else {
			// Proporciona un valor predeterminado
			nombre_jugador = "Jugador Anónimo";
		}

		// Muestra la ventana del tablero
		gtk_widget_show(menu_tablero);
		gtk_widget_hide(menu_opciones);
	}
}

void EXPOSICION_NOMBRE(GtkWidget *widget, gpointer data) {
    // Verifica si hay un nombre de jugador para mostrar
    // Agregar aquí los errores, si no hay error, mostrar el nombre, si no, mostrar el error
    if (modo == 1 && nombre_jugador2 != NULL) {
        // Establece el texto en el widget de visualización de nombre2
        gtk_label_set_text(GTK_LABEL(tablero_nombre_display2), nombre_jugador2);
	gtk_label_set_text(GTK_LABEL(tablero_nombre_display), nombre_jugador);
    } else if (nombre_jugador != NULL) {
        // Establece el texto en el widget de visualización de nombre
        gtk_label_set_text(GTK_LABEL(tablero_nombre_display), nombre_jugador);
    } else {
        // Maneja el caso donde no hay nombre de jugador
        g_print("Nombre no especificado\n");
    }
}

void MOSTRAR_OPCIONES(GtkWidget *widget, gpointer data) {
	gtk_widget_show(menu_opciones);
}

//Mostrar y ocultar el menu de como jugar
void MOSTRAR_INSTRUCCIONES(GtkWidget *widget, gpointer data) {
	gtk_widget_show(menu_como_jugar);
}
void OCULTAR_INSTRUCCIONES(GtkWidget *widget, gpointer data) {
	gtk_widget_hide(menu_como_jugar);
}

//Mostrar y ocultar el menu de creditos
void MOSTRAR_CREDITOS(GtkWidget *widget, gpointer data) {
	gtk_widget_show(menu_creadores);
}
void OCULTAR_CREDITOS(GtkWidget *widget, gpointer data) {
	gtk_widget_hide(menu_creadores);
}
void verificarjugada(int jugada) {


	if (lamatriz[jugada][0][0] == '\0') {
		ponerDadojugador(jugada);
		posiocupada[1] = jugadaGTK;
		computadora(1);
	}
}
void actualizar_GTK() { //como dice la funcion, el GTK "mira" la matriz y se actualiza en torno a ella
	for (int i = 1; i < 26; ++i) {
		int valor = lamatriz[i][0][0];
		char buffer[20];
		if (valor != '\0' && lamatriz[i][0][0] != '\0') {
			if (lamatriz[i][valor][0] == 2) {
				snprintf(buffer, sizeof(buffer), "[%d]", valor);
			} else {
				snprintf(buffer, sizeof(buffer), "(%d)", valor);
			}
			switch (i) {
			case 1:
				gtk_button_set_label(GTK_BUTTON(BOTON1), (const gchar*) buffer);
				break;
			case 2:
				gtk_button_set_label(GTK_BUTTON(BOTON2), (const gchar*) buffer);
				break;
			case 3:
				gtk_button_set_label(GTK_BUTTON(BOTON3), (const gchar*) buffer);
				break;
			case 4:
				gtk_button_set_label(GTK_BUTTON(BOTON4), (const gchar*) buffer);
				break;
			case 5:
				gtk_button_set_label(GTK_BUTTON(BOTON5), (const gchar*) buffer);
				break;
			case 6:
				gtk_button_set_label(GTK_BUTTON(BOTON6), (const gchar*) buffer);
				break;
			case 7:
				gtk_button_set_label(GTK_BUTTON(BOTON7), (const gchar*) buffer);
				break;
			case 8:
				gtk_button_set_label(GTK_BUTTON(BOTON8), (const gchar*) buffer);
				break;
			case 9:
				gtk_button_set_label(GTK_BUTTON(BOTON9), (const gchar*) buffer);
				break;
			case 10:
				gtk_button_set_label(GTK_BUTTON(BOTON10),
						(const gchar*) buffer);
				break;
			case 11:
				gtk_button_set_label(GTK_BUTTON(BOTON11),
						(const gchar*) buffer);
				break;
			case 12:
				gtk_button_set_label(GTK_BUTTON(BOTON12),
						(const gchar*) buffer);
				break;
			case 13:
				gtk_button_set_label(GTK_BUTTON(BOTON13),
						(const gchar*) buffer);
				break;
			case 14:
				gtk_button_set_label(GTK_BUTTON(BOTON14),
						(const gchar*) buffer);
				break;
			case 15:
				gtk_button_set_label(GTK_BUTTON(BOTON15),
						(const gchar*) buffer);
				break;
			case 16:
				gtk_button_set_label(GTK_BUTTON(BOTON16),
						(const gchar*) buffer);
				break;
			case 17:
				gtk_button_set_label(GTK_BUTTON(BOTON17),
						(const gchar*) buffer);
				break;
			case 18:
				gtk_button_set_label(GTK_BUTTON(BOTON18),
						(const gchar*) buffer);
				break;
			case 19:
				gtk_button_set_label(GTK_BUTTON(BOTON19),
						(const gchar*) buffer);
				break;
			case 20:
				gtk_button_set_label(GTK_BUTTON(BOTON20),
						(const gchar*) buffer);
				break;
			case 21:
				gtk_button_set_label(GTK_BUTTON(BOTON21),
						(const gchar*) buffer);
				break;
			case 22:
				gtk_button_set_label(GTK_BUTTON(BOTON22),
						(const gchar*) buffer);
				break;
			case 23:
				gtk_button_set_label(GTK_BUTTON(BOTON23),
						(const gchar*) buffer);
				break;
			case 24:
				gtk_button_set_label(GTK_BUTTON(BOTON24),
						(const gchar*) buffer);
				break;
			case 25:
				gtk_button_set_label(GTK_BUTTON(BOTON25),
						(const gchar*) buffer);
				break;
			}
		} else {    //si es que es nulo el valor en esa posicion
			buffer[0]=' ';
			buffer[1]='\0';
			switch (i) {
			case 1:
				gtk_button_set_label(GTK_BUTTON(BOTON1), (const gchar*) buffer);
				break;
			case 2:
				gtk_button_set_label(GTK_BUTTON(BOTON2), (const gchar*) buffer);
				break;
			case 3:
				gtk_button_set_label(GTK_BUTTON(BOTON3), (const gchar*) buffer);
				break;
			case 4:
				gtk_button_set_label(GTK_BUTTON(BOTON4), (const gchar*) buffer);
				break;
			case 5:
				gtk_button_set_label(GTK_BUTTON(BOTON5), (const gchar*) buffer);
				break;
			case 6:
				gtk_button_set_label(GTK_BUTTON(BOTON6), (const gchar*) buffer);
				break;
			case 7:
				gtk_button_set_label(GTK_BUTTON(BOTON7), (const gchar*) buffer);
				break;
			case 8:
				gtk_button_set_label(GTK_BUTTON(BOTON8), (const gchar*) buffer);
				break;
			case 9:
				gtk_button_set_label(GTK_BUTTON(BOTON9), (const gchar*) buffer);
				break;
			case 10:
				gtk_button_set_label(GTK_BUTTON(BOTON10),
						(const gchar*) buffer);
				break;
			case 11:
				gtk_button_set_label(GTK_BUTTON(BOTON11),
						(const gchar*) buffer);
				break;
			case 12:
				gtk_button_set_label(GTK_BUTTON(BOTON12),
						(const gchar*) buffer);
				break;
			case 13:
				gtk_button_set_label(GTK_BUTTON(BOTON13),
						(const gchar*) buffer);
				break;
			case 14:
				gtk_button_set_label(GTK_BUTTON(BOTON14),
						(const gchar*) buffer);
				break;
			case 15:
				gtk_button_set_label(GTK_BUTTON(BOTON15),
						(const gchar*) buffer);
				break;
			case 16:
				gtk_button_set_label(GTK_BUTTON(BOTON16),
						(const gchar*) buffer);
				break;
			case 17:
				gtk_button_set_label(GTK_BUTTON(BOTON17),
						(const gchar*) buffer);
				break;
			case 18:
				gtk_button_set_label(GTK_BUTTON(BOTON18),
						(const gchar*) buffer);
				break;
			case 19:
				gtk_button_set_label(GTK_BUTTON(BOTON19),
						(const gchar*) buffer);
				break;
			case 20:
				gtk_button_set_label(GTK_BUTTON(BOTON20),
						(const gchar*) buffer);
				break;
			case 21:
				gtk_button_set_label(GTK_BUTTON(BOTON21),
						(const gchar*) buffer);
				break;
			case 22:
				gtk_button_set_label(GTK_BUTTON(BOTON22),
						(const gchar*) buffer);
				break;
			case 23:
				gtk_button_set_label(GTK_BUTTON(BOTON23),
						(const gchar*) buffer);
				break;
			case 24:
				gtk_button_set_label(GTK_BUTTON(BOTON24),
						(const gchar*) buffer);
				break;
			case 25:
				gtk_button_set_label(GTK_BUTTON(BOTON25),
						(const gchar*) buffer);
				break;
			}

		}
	}
}

void PRESIONADO(GtkWidget *widget, gpointer data) {//funcion que se llama al presionar cualquier boton

	jugadaGTK = GPOINTER_TO_INT(data);
	verificarjugada(jugadaGTK);
	g_print("\n");
	imprimir_matriz();
	actualizar_GTK();
}

void REINICIAR(GtkWidget *widget, gpointer data) {
    // Limpia la matriz
	vaciar_matriz();
    // Actualiza la interfaz gráfica
    actualizar_GTK();
}
void OCULTAR_SELECCIONAR(GtkWidget *widget, gpointer data) {
	if (suma < 7 && suma > 2) {
		sumarDado(suma, jugadaGTK);
		actualizar_GTK();
		gtk_widget_show(menu_tablero);
		gtk_widget_hide(menu_seleccionar);
		temp1=0;
		temp2=0;
		temp3=0;
		temp4=0;
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(izquierdaGTK),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(derechaGTK),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(arribaGTK),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(abajoGTK),FALSE);

	} else {
		gtk_label_set_text(GTK_LABEL(suma_display), "suma invalida");
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(izquierdaGTK),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(derechaGTK),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(arribaGTK),FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(abajoGTK),FALSE);
		temp1=0;
		temp2=0;
		temp3=0;
		temp4=0;
	}
}
/*Funcion de los botones que se toglean para la seleccion de que dados comer,
 * establece variables estaticas temporales de izquierda derecha arriba y abajo en ese orden
 * que van cambiando de acuerdo a la ubicacion de la jugada y de los botones, ademas de
 * ir cambiando visiblemente la suma actual, la suma es una variable global
*/
void BOTONES_TOGGLE(GtkToggleButton *toggle_button, gpointer data) {
	char buffer[20];
	int num = GPOINTER_TO_INT(data);
	if (gtk_toggle_button_get_active(toggle_button)) {
		switch (num) {
		case 0:
			temp1 = lamatriz[jugadaGTK - 1][0][0];
			lamatriz[jugadaGTK - 1][0][0] = '\0';
			break;
		case 1:
			temp2 = lamatriz[jugadaGTK + 1][0][0];
			lamatriz[jugadaGTK + 1][0][0] = '\0';
			break;
		case 2:
			temp3 = lamatriz[jugadaGTK - 5][0][0];
			lamatriz[jugadaGTK - 5][0][0] = '\0';
			break;
		case 3:
			temp4 = lamatriz[jugadaGTK + 5][0][0];
			lamatriz[jugadaGTK + 5][0][0] = '\0';
			break;

		}
		suma = suma + vector[num];
		snprintf(buffer, sizeof(buffer), "%d", suma);
		gtk_label_set_text(GTK_LABEL(suma_display), buffer);
	} else {
		switch (num) {
		case 0:
			lamatriz[jugadaGTK - 1][0][0] = temp1;
			break;
		case 1:
			lamatriz[jugadaGTK + 1][0][0] = temp2;
			break;
		case 2:
			lamatriz[jugadaGTK - 5][0][0] = temp3;
			break;
		case 3:
			lamatriz[jugadaGTK + 5][0][0] = temp4;
			break;

		}
		suma = suma - vector[num];
		snprintf(buffer, sizeof(buffer), "%d", suma);
		gtk_label_set_text(GTK_LABEL(suma_display), buffer);
	}
}

int main(int argc, char *argv[])

{
	gtk_init(&argc, &argv);
	constructor = gtk_builder_new_from_file(GLADE_FILE_PATH);
	declarar_widgets();
	//En el menu opciones, los primeros 3 botones toggleables
	g_signal_connect(opciones_jcj, "toggled", G_CALLBACK(TOGLEADO_JCJ), NULL);
	g_signal_connect(opciones_JCIA, "toggled", G_CALLBACK(TOGLEADO_JCIA), NULL);
	g_signal_connect(opciones_iacia, "toggled", G_CALLBACK(TOGLEADO_IACIA),NULL);
	//En el menu opciones, los segundos 3 botones toggleables
	g_signal_connect(opciones_corchetes, "toggled", G_CALLBACK(TOGLEADO_COR),NULL);
	g_signal_connect(opciones_parentesis, "toggled", G_CALLBACK(TOGLEADO_PAR),NULL);
	g_signal_connect(opciones_aleatorio, "toggled", G_CALLBACK(TOGLEADO_ALE),NULL);
	g_signal_connect(opciones_salir, "clicked", G_CALLBACK(gtk_main_quit),NULL);
	//En el menu de opciones, al apretar JUGAR
	g_signal_connect(opciones_jugar, "clicked", G_CALLBACK(ABRIR_TABLERO),NULL);
	//En el menu de opciones, el nombre del jugador
	g_signal_connect(opciones_jugar, "clicked", G_CALLBACK(EXPOSICION_NOMBRE),NULL);
	//En el menu tablero, botones que llevan a otras ventanas
	g_signal_connect(tablero_opciones, "clicked", G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(tablero_como_jugar, "clicked",G_CALLBACK(MOSTRAR_INSTRUCCIONES), NULL);
	g_signal_connect(tablero_creditos, "clicked", G_CALLBACK(MOSTRAR_CREDITOS),NULL);
	g_signal_connect(tablero_reiniciar, "clicked", G_CALLBACK(REINICIAR), NULL);
	//En el menu como jugar, el cerrar
	g_signal_connect(como_jugar_cerrar, "clicked",G_CALLBACK(OCULTAR_INSTRUCCIONES), NULL);
	//En el menu creditos, el cerrar
	g_signal_connect(creadores_salir, "clicked", G_CALLBACK(OCULTAR_CREDITOS),NULL);
	//El menu de seleccionar para hacer captura multiple
	g_signal_connect(seleccionar_confirmar, "clicked", G_CALLBACK(OCULTAR_SELECCIONAR),NULL);
	g_signal_connect(izquierdaGTK, "clicked", G_CALLBACK(BOTONES_TOGGLE), GINT_TO_POINTER(0));
	g_signal_connect(derechaGTK, "clicked", G_CALLBACK(BOTONES_TOGGLE), GINT_TO_POINTER(1));
	g_signal_connect(arribaGTK, "clicked", G_CALLBACK(BOTONES_TOGGLE), GINT_TO_POINTER(2));
	g_signal_connect(abajoGTK, "clicked", G_CALLBACK(BOTONES_TOGGLE), GINT_TO_POINTER(3));
	//Los siguientes son los botones presionados
	g_signal_connect(BOTON1, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(1));
	g_signal_connect(BOTON2, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(2));
	g_signal_connect(BOTON3, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(3));
	g_signal_connect(BOTON4, "clicked", G_CALLBACK(PRESIONADO),GINT_TO_POINTER(4));
	g_signal_connect(BOTON5, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(5));
	g_signal_connect(BOTON6, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(6));
	g_signal_connect(BOTON7, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(7));
	g_signal_connect(BOTON8, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(8));
	g_signal_connect(BOTON9, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(9));
	g_signal_connect(BOTON10, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(10));
	g_signal_connect(BOTON11, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(11));
	g_signal_connect(BOTON12, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(12));
	g_signal_connect(BOTON13, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(13));
	g_signal_connect(BOTON14, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(14));
	g_signal_connect(BOTON15, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(15));
	g_signal_connect(BOTON16, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(16));
	g_signal_connect(BOTON17, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(17));
	g_signal_connect(BOTON18, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(18));
	g_signal_connect(BOTON19, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(19));
	g_signal_connect(BOTON20, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(20));
	g_signal_connect(BOTON21, "clicked", G_CALLBACK(PRESIONADO),GINT_TO_POINTER(21));
	g_signal_connect(BOTON22, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(22));
	g_signal_connect(BOTON23, "clicked", G_CALLBACK(PRESIONADO),GINT_TO_POINTER(23));
	g_signal_connect(BOTON24, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(24));
	g_signal_connect(BOTON25, "clicked", G_CALLBACK(PRESIONADO), GINT_TO_POINTER(25));


	gtk_widget_show(menu_opciones);
	g_signal_connect(menu_opciones, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();

	return 0;
}
