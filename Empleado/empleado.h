/*
 * empleado.h
 *
 *  Created on: 23 mar 2023
 *      Author: usuario
 */

#ifndef EMPLEADO_EMPLEADO_H_
#define EMPLEADO_EMPLEADO_H_

typedef struct{
	int codigo;
	char* DNI;
	char* nombre;
	char* apellido;
	int tfno;
	char* correo;
	char* contrasena;
	char* estatus;
	int cod_park;
}Empleado;


void gestionarEmpleados();
void visualizarEmpleados();
void anyadirEmpleado();
void eliminarEmpleado();


#endif /* EMPLEADO_H_ */
