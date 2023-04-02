#include "empleado.h"
#include <stdio.h>

void gestionarEmpleados()
{
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
		main();
	}
}

void visualizarEmpleados(void)
{
    int nEmpleados = 5;
    int i, a;
    printf("Lista de empleados\n");

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

	char dni[9], nombre[20], apellido[20], contra[20], correo[20], telefono[9], status[20];
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
    printf("Introduzca la contraseña\n");
    fflush(stdout);
    scanf(" %s", contra);
    printf("Introduzca el numero de telefono\n");
    fflush(stdout);
    scanf(" %s", telefono);
    printf("Introduzca el  estatus (JEFE/EMPLEADO)\n");
    fflush(stdout);
    scanf(" %s", status);


    InsertWorker(dni, nombre, apellido, telefono, correo, contra, status);
    printf("El empleado ha sido añadido");
    gestionarEmpleados();
}

void eliminarEmpleado()
{
	char dni[9];
    char confirmacion;
    printf("Eliminar empleado\n");
    printf("¿Que empleado desea eliminar?(Introducir el DNI del empleado)\n");
    fflush(stdout);
    scanf(" %s", dni);
    printf("Confirmar la eliminacion del empleado con codigo x (s/n)\n");
    fflush(stdout);
    scanf(" %c", &confirmacion);
    if (confirmacion == 's')
    {
    	printf("El empleado ha sido eliminado con exito");
    	gestionarEmpleados();
     } else
     {
    	printf("El empleado no ha sido eliminado");
    	eliminarEmpleado();
      }
}
