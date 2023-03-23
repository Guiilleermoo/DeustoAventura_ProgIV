/*
 * empleado.c
 *
 *  Created on: 23 mar 2023
 *      Author: usuario
 */

#include "empleado.h"
#include <stdio.h>

	void gestionarEmpleados(void){
		printf("Gestionar empleado\n");
		printf("1. Visualizar empleados\n");
		printf("2. Añadir empleado\n");
		printf("3. Borrar empleado\n");
		printf("0. Volver\n");
		fflush(stdout);
		int a;


		scanf(" %d", &a);
		printf("Se leyó el caracter: %d\n", a);
		fflush(stdout);
		if (a == 1) {
			visualizarEmpleados();
		} else if (a == 2) {
			anyadirEmpleado();
		} else if (a == 3) {
			eliminarEmpleado();
		} else if (a == 0) {
			main();
		}
	}

    void visualizarEmpleados(void){
    	int nEmpleados = 5;
    	int i, a;
    	printf("Lista de empleados\n");
    	for (i = 0; i < nEmpleados; ++i) {
    		printf("	%i. Empleado\n", i);
    		printf("		a. DNI\n");
    		printf("		a. Nombre\n");
    		printf("		a. Email\n");
    		printf("		a. Estatus\n");
    		printf("		a. Telefonos\n");
		}

    	printf("0. Volver\n");
    	fflush(stdout);
    	scanf(" %d", &a);

    	if (a == 0) {
    	    gestionarEmpleados();
    	}
    }

    void anyadirEmpleado(void){
       	char dni[9], nombre[20], apellido[20], usuario[20], contra[20], correo[20], telefono[9], status[20];
       	printf("Añadir empleado\n");
       	printf("DNI\n");
       	fflush(stdout);
       	scanf(" %s", dni);
       	printf("Nombre\n");
       	fflush(stdout);
       	scanf(" %s", nombre);
       	printf("Apellido\n");
       	fflush(stdout);
       	scanf(" %s", apellido);
       	printf("Email\n");
       	fflush(stdout);
       	scanf(" %s", correo);
       	printf("Nombre de usuario\n");
       	fflush(stdout);
       	scanf(" %s", usuario);
       	printf("Introduzca la contraseña\n");
       	fflush(stdout);
       	scanf(" %s", contra);
       	printf("Introduzca el numero de telefono\n");
       	fflush(stdout);
       	scanf(" %s", telefono);
    	printf("Introduzca el numero de estatus\n");
        fflush(stdout);
        scanf(" %s", status);

        printf("El empleado ha sido añadido");
        gestionarEmpleados();
    }

    void eliminarEmpleado(void){
       char dni[9];
       char confirmacion;
       printf("Eliminar empleado\n");
       printf("¿Que empleado desea eliminar?(Introducir el DNI del empleado)\n");
       fflush(stdout);
       scanf(" %s", dni);
       printf("Confirmar la eliminacion del empleado con codigo x (s/n)\n");
       fflush(stdout);
       scanf(" %c", confirmacion);
       if (confirmacion == 's') {
    	   printf("El empleado ha sido eliminado con exito");
    	   gestionarEmpleados();
       } else {
    	   printf("El empleado no ha sido eliminado");
    	   eliminarEmpleado();
       }
    }
