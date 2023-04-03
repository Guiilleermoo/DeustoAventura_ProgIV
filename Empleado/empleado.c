#include "empleado.h"
#include <stdio.h>
#include "../BD/funcionesBD.h"

void gestionarEmpleados()
{
	printf("GESTIONAR EMPLEADO\n\n");
	printf("1. Visualizar empleados\n");
	printf("2. Añadir empleado\n");
	printf("3. Borrar empleado\n");
	printf("0. Volver\n");
	fflush(stdout);
	int a;


	scanf(" %d", &a);
	fflush(stdout);
	if (a == 1)
	{
		visualizarEmpleados();
	} else if (a == 2)
	{
		anyadirEmpleado();
	} else if (a == 3)
	{
		eliminarEmpleado();
	} else if (a == 0)
	{
		menuJefe();
	}
}

void visualizarEmpleados(void)
{
    int nEmpleados = 5;
    int i, a;
    printf("LISTA DE EMPLEADOS\n");

    ShowWorkers();

    printf("0. Volver\n");
    fflush(stdout);
    scanf(" %d", &a);

    if (a == 0)
    {
    	gestionarEmpleados();
    }
}

void anyadirEmpleado()
{
	char dni[11];
	char nombre[10];
	char apellido[10];
	int tfno;
	char correo[10];
	char contra[10];
	char estatus[10];
	int cod_park;

	printf("AÑADIR EMPLEADO\n");
	printf("DNI:  ");
	fflush(stdout);
	scanf(" %s", dni);
	printf("Nombre:  ");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Apellido:  ");
	fflush(stdout);
	scanf(" %s", apellido);
	printf("Email:  ");
	fflush(stdout);
	scanf(" %s", correo);
	printf("Introduzca la contraseña:  ");
	fflush(stdout);
	scanf(" %s", contra);
	printf("Introduzca el numero de telefono:  ");
	fflush(stdout);
	scanf(" %i", &tfno);
	printf("Introduzca el estatus (JEFE/EMPLEADO):  ");
	fflush(stdout);
	scanf(" %s", estatus);
	printf("Introduzca el codigo de parque:  ");
	fflush(stdout);
	scanf(" %i", &cod_park);

	InsertWorker(dni, nombre, apellido, tfno, correo, contra, estatus, cod_park);

    gestionarEmpleados();
}

void eliminarEmpleado()
{
	char dni[10];
    char confirmacion;

    ShowWorkers();
    printf("¿Que empleado desea eliminar?(Introducir el DNI del empleado)\n");
    fflush(stdout);
    scanf(" %s", dni);
    printf("Confirmar la eliminacion del empleado con codigo %s (s/n)\n", dni);
    fflush(stdout);
    scanf(" %c", &confirmacion);
    if (confirmacion == 's')
    {
    	DeleteWorker(dni);
    	printf("El empleado ha sido eliminado con exito\n");
    	gestionarEmpleados();
     } else
     {
    	printf("El empleado no ha sido eliminado");
    	eliminarEmpleado();
      }
}






















