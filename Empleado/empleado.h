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
	char* tfno;
	char* correo;
	char* contrasena;
	char* estatus;
	char* cod_park;

}Empleado;


void gestionarEmpleados(void);
void visualizarEmpleados(void);
void anyadirEmpleados(void);
void eliminarEmpleado(void);


#endif /* EMPLEADO_H_ */
