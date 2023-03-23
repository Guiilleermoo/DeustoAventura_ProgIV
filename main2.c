/*
 * main2.c
 *
 *  Created on: 23 mar 2023
 *      Author: borja
 */
#include <stdio.h>
#include "Reserva/reserva.h"
void menuEmpleado(){
	 printf("Gestion de actividades DeustoAventura\n");
	    printf("1. Hacer una reserva\n");
	    printf("2. Cancelar una reserva\n");
	    printf("3. Visualizar una reserva\n");
	    printf("0. Salir\n");
	    fflush(stdout);
	    int a;
	    scanf("%d", &a);
	    printf("Se leyó el caracter: %d\n", a);
	    fflush(stdout);
	    if (a == 1) {
			hacerReserva();
		} else if (a == 2) {
			cancelarReserva();

		}  else if (a == 3) {
			visualizarReservas();

		}else if (a == 0) {

		}



	//    	char a, b;
	//    	    printf("Ingrese el primer caracter:\n");
	//    	    fflush(stdout);
	//    	    scanf(" %c", &a);
	//    	    printf("Se leyó el caracter: %c\n", a);
	//    	    printf("Ingrese el segundo caracter:\n");
	//    	    fflush(stdout);
	//    	    scanf(" %c", &b);
	//    	    printf("Se leyó el caracter: %c\n", b);

}

