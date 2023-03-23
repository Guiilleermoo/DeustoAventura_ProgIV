/*
 * actividad.c
 *
 *  Created on: 23 mar 2023
 *      Author: borja
 */
#include "actividad.h"
#include <stdio.h>
void imprimirActividad(Actividad a){
	printf("Codigo: %i Nombre: %s Dificultad: %d Minimo de personas: %d Maximo de personas: %d\n",a.code,a.nombre,a.dificultad,a.personasMin,a.personasMax);
}
