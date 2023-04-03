#include "actividad.h"
#include <stdio.h>
#include "../Empleado/empleado.h"
#include "../BD/funcionesBD.h"

void menuJefe();

void gestionarActividades()
{
    printf("MENU ACTIVIDADES\n");
    printf("1. Visualizar actividades\n");
    printf("2. Añadir actividad\n");
    printf("3. Eliminar actividad\n");
    printf("0. Volver\n");
    printf("Elija su opcion:  ");
    fflush(stdout);
    printf("\n");
    int a;

    scanf(" %d", &a);
    fflush(stdout);
    if (a == 1)
    {
    	visualizarMenuActividades();
    } else if (a == 2)
    {
    	anyadirActividad();
    } else if (a == 3)
    {
    	eliminarActividad();
    } else if (a == 0)
    {
    	menuJefe();
    }
}

void visualizarMenuActividades()
{
   printf("VER ACTIVIDADES\n");
   printf("1. Visualizar todas actividades\n");
   printf("2. Buscar actividades por provincia\n");
   printf("3. Buscar actividades por nivel de dificultad\n");
   printf("0. Volver\n");
   printf("Elija su opcion:  ");
   fflush(stdout);
   printf("\n");
   int a;

   scanf(" %d", &a);
   fflush(stdout);
   if (a == 1)
   {
	   ShowActivities();

	   int b;

		printf("0. Pulsa enter para volver\n");
		fflush(stdout);
		scanf(" %d", &b);

		if (b == 0)
		{
			visualizarMenuActividades();
		}
    } else if (a == 2)
    {
    	visualizarProvincia();
    } else if (a == 3)
    {
    	visualizarDificultad();
    } else if (a == 0)
    {
    	gestionarActividades();
    }
}

void visualizarProvincia()
{
    char provincia[20];
    printf("Que provincia desea consultar:  ");
    fflush(stdout);
    scanf(" %s", provincia);

    ShowActivitiesInProvince(provincia);

    int a;

    printf("0. Pulsa enter para volver\n");
    fflush(stdout);
    scanf(" %d", &a);

    if (a == 0)
    {
    	visualizarMenuActividades();
    }
}

void visualizarDificultad()
{
	char dificultad[6];
    printf("Que nivel de dificultad desea consultar(Baja/Media/Alta):   ");
    fflush(stdout);
    scanf(" %s", dificultad);

    showActivitiesByDifficulty(dificultad);

    int a;

    printf("0. Pulsa enter para volver\n");
    fflush(stdout);
    scanf(" %d", &a);

    if (a == 0)
    {
    	visualizarMenuActividades();
     }
}

void anyadirActividad()
{
	char nombre[20];
	char dificultad[6];
	int limite_per_min, limite_per_max, edad_min;

	printf("AÑADIR ACTIVIDAD\n");
	printf("1. Nombre:  ");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("2. Dificultad:  ");
	fflush(stdout);
	scanf(" %s", dificultad);
	printf("3. Limite de personas (MIN):  ");
	fflush(stdout);
	scanf(" %i", &limite_per_min);
	printf("4. Limite de personas (Max):  ");
	fflush(stdout);
	scanf(" %i", &limite_per_max);
	printf("4. Edad minima:  ");
	fflush(stdout);
	scanf(" %i", &edad_min);

	InsertActivity(nombre, dificultad, limite_per_min, limite_per_max, edad_min);

	visualizarMenuActividades();
 }

void eliminarActividad()
{
	int codigo;
	char confirmacion;

	ShowActivities();

	printf("¿Que actividad desea eliminar?(Introducir el codigo de la actividad):  ");
	fflush(stdout);
	scanf(" %i", &codigo);
	printf("Confirmar la eliminacion de la actividad con codigo %i (s/n):  ", codigo);
	fflush(stdout);
	printf("\n");
	scanf(" %c", &confirmacion);
	if (confirmacion == 's')
	{
		DeleteActivity(codigo);
	    gestionarActividades();
	} else
	{
	   printf("La actividad no ha sido eliminada\n");
	   gestionarActividades();
	}
}
