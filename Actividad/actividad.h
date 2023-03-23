/*
 * actividad.h
 *
 *  Created on: 23 mar 2023
 *      Author: borja
 */

#ifndef ACTIVIDAD_ACTIVIDAD_H_
#define ACTIVIDAD_ACTIVIDAD_H_
typedef struct{
	int code;
	char* nombre;
	int dificultad;
	int personasMin;
	int personasMax;

}Actividad;
void imprimirActividad(Actividad actividad);

#endif /* ACTIVIDAD_ACTIVIDAD_H_ */
