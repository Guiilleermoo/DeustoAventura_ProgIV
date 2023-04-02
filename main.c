#include "CSV/readCSV.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Reserva/reserva.h"
#include "Actividad/actividad.h"
#include "Empleado/empleado.h"
#include "BD/funcionesBD.h"

void inicioSesion();
void menuEmpleado();
void menuJefe();

int main(void)
{
//    char *filename="";
//    ReadCsvData(filename);           // Leer datos csv
//    ShowCsvData();                   // Muestra los datos csv leídos a través de la consola
//    FreeCsvData();				   // Libera la memoria dinámica

	printf("Gestion de actividades DeustoAventura\n");
	printf("1. Iniciar sesion\n");
	printf("0. Salir\n");
	fflush(stdout);
	int a;


	scanf(" %d", &a);
	//printf("Se leyó el caracter: %d\n", a);
    fflush(stdout);
    if (a == 1) {
		inicioSesion();
	} else if (a == 0) {
		printf("FIN");
		exit (-1);
	}

    return 0;
}

void inicioSesion(void)
{
    char nombre[20], contra[20];
    printf("Inicio de sesion\n");

    printf("Introduzca el usuario\n");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Introduzca la contraseña\n");
	fflush(stdout);
	scanf(" %s", contra);


	Empleado emp = isWorker(nombre, contra);
	puts(emp.estatus);
	if(strcmp(emp.estatus, "JEFE") == 1)
	{
		printf("Se ha iniciado sesion como JEFE con el alias ");
		puts(nombre);

		printf("\n");

		menuJefe();
	} else if(strcmp(emp.estatus, "EMPLEADO") == 0){
		printf("Se ha iniciado sesion como EMPLEADO con el alias ");
		puts(nombre);

		printf("\n");

		menuEmpleado();
	} else{
		printf("Empleado no encontrado");
		main();
	}
}

/*void registroUsuario(void)
{
    char dni[9], nombre[20], apellido[20], usuario[20], contra[20], correo[20], telefono[9];
    printf("Registro de usuario\n");
    printf("Introduzca el DNI\n");
    fflush(stdout);
    scanf(" %s", dni);
    printf("Introduzca el nombre\n");
    fflush(stdout);
    scanf(" %s", nombre);
    printf("Introduzca el apellido\n");
    fflush(stdout);
    scanf(" %s", apellido);
    printf("Introduzca el nombre de usuario\n");
    fflush(stdout);
    scanf(" %s", usuario);
    printf("Introduzca la contraseña\n");
    fflush(stdout);
    scanf(" %s", contra);
    printf("Introduzca el correo\n");
    fflush(stdout);
    scanf(" %s", correo);
    printf("Introduzca el numero de telefono\n");
    fflush(stdout);
    scanf(" %s", telefono);
}*/

void menuEmpleado()
{
	printf("Gestion de actividades DeustoAventura\n");
    printf("1. Hacer una reserva\n");
    printf("2. Cancelar una reserva\n");
    printf("3. Visualizar una reserva\n");
    printf("4. Visualizar actividades\n");
    printf("0. Salir\n");
    fflush(stdout);
    int a;
    scanf("%d", &a);
    printf("Se leyó el caracter: %d\n", a);
    fflush(stdout);
    if (a == 1)
    {
    	hacerReserva();
    } else if (a == 2)
    {
    	cancelarReserva();
     } else if (a == 3)
     {
    		 //visualizarReservas();
     } else if (a == 4)
     {
    	 visualizarMenuActividades();
     } else if (a == 0)
     {

     }
}

void menuJefe(void)
{
    printf("Menu principal jefe\n");
	printf("1. Gestionar empleados\n");
	printf("2. Gestionar actividades\n");
	printf("0. Volver\n");
	fflush(stdout);
	int a;


	scanf(" %d", &a);
	printf("Se leyó el caracter: %d\n", a);
	fflush(stdout);
	if (a == 1)
	{
		gestionarEmpleados();
	} else if (a == 2)
	{
		gestionarActividades();
	} else if (a == 0)
	{
		main();
	}
}
