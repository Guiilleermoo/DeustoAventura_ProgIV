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

	printf("GESTION DE DEUSTOAVENTURA\n\n");
	printf("1. Iniciar sesion\n");
	printf("0. Salir\n");
	printf("Elija su opcion:  ");
	fflush(stdout);
	printf("\n");
	int a;


	scanf(" %d", &a);
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
    printf("INICIO DE SESION\n\n");

    printf("Introduzca el usuario: \t");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("Introduzca la contraseña:  ");
	fflush(stdout);
	printf("\n");
	scanf(" %s", contra);


	isWorker(nombre, contra);
}

void menuEmpleado()
{
	printf("Gestion de actividades DeustoAventura\n");
    printf("1. Hacer una reserva\n");
    printf("2. Cancelar una reserva\n");
    printf("3. Visualizar todas las reservas\n");
    printf("4. Visualizar una reserva\n");
    printf("5. Visualizar actividades\n");
    printf("0. Salir\n");
    printf("Elija su opcion:  ");
    fflush(stdout);
    printf("\n");
    int a;
    scanf("%d", &a);
    fflush(stdout);
    if (a == 1)
    {
    	hacerReserva();
    } else if (a == 2)
    {
    	cancelarReserva();
     } else if (a == 3)
     {
    	visualizarReservas();
     } else if (a == 4)
     {
    	visualizarUnaReserva();
     } else if (a == 5)
     {
    	 visualizarMenuActividades();
     } else if (a == 0)
     {
    	 main();
     }
}

void menuJefe(void)
{
    printf("MENU PRINCIPAL JEFE\n\n");
	printf("1. Gestionar empleados\n");
	printf("2. Gestionar actividades\n");
	printf("0. Volver\n");
	printf("Elija su opcion:  ");
	fflush(stdout);
	printf("\n");
	int a;


	scanf(" %d", &a);
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
