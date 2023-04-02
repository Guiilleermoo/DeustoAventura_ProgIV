#include "actividad.h"
#include <stdio.h>
#include "../Empleado/empleado.h"
#include "../BD/funcionesBD.h"

void menuJefe();

void gestionarActividades(void)
{
    printf("Menu actividades\n");
    printf("1. Visualizar actividades\n");
    printf("2. Añadir actividad\n");
    printf("3. Eliminar actividad\n");
    printf("0. Volver\n");
    fflush(stdout);
    int a;

    scanf(" %d", &a);
    printf("Se leyó el caracter: %d\n", a);
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

void visualizarMenuActividades(void)
{
   printf("Ver actividades\n");
   printf("1. Visualizar todas actividades\n");
   printf("2. Buscar actividades por ciudad\n");
   printf("3. Buscra actividades por nivel de dificultad\n");
   printf("0. Volver\n");
   fflush(stdout);
   int a;

   scanf(" %d", &a);
   printf("Se leyó el caracter: %d\n", a);
   fflush(stdout);
   if (a == 1)
   {
	   visualizarTodas();
    } else if (a == 2)
    {
    	visualizarCiudad();
    } else if (a == 3)
    {
    	visualizarDificultad();
    } else if (a == 0)
    {
    	gestionarActividades();
    }
}

void visualizarTodas(void)
{
	int nActividades = 5;
	int i, a;
	printf("Lista de todas las actividades\n");

	ShowActivities();

	printf("0. Pulsa enter para volver\n");
	fflush(stdout);
	scanf(" %d", &a);

	if (a == 0)
	{
		visualizarMenuActividades();
	}
}

void visualizarCiudad(void)
{
    char ciudad[20];
    printf("Que ciudad desea consultar\n");
    fflush(stdout);
    scanf(" %s", ciudad);

    int nActividades = 5;
    int i, a;
    printf("Lista de todas las actividades de x\n");
    for (i = 0; i < nActividades; ++i)
    {
      printf("	%i. Actividad\n", i);
    }

    printf("0. Pulsa enter para volver\n");
    fflush(stdout);
    scanf(" %d", &a);

    if (a == 0)
    {
    	visualizarMenuActividades();
    }
}

void visualizarDificultad(void)
{
	int b;
    printf("Que nivel de dificultad desea consultar(1-10)\n");
    fflush(stdout);
    scanf(" %d", &b);

    int nActividades = 5;
    int i, a;
    printf("Lista de todas las actividades con dificultad %i\n", b);
    for (i = 0; i < nActividades; ++i)
    {
    	printf("	%i. Actividad\n", i);
    }

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
	char dificultad;
	int limite_per;
	printf("Añadir actividad\n");
	printf("1. Nombre: \n");
	fflush(stdout);
	scanf(" %s", nombre);
	printf("2. Dificultad: \n");
	fflush(stdout);
	scanf(" %c", &dificultad);
	printf("3. Limite de personas: \n");
	fflush(stdout);
	scanf(" %i", &limite_per);

	printf("La actividad ha sido añadida");
	visualizarMenuActividades();
 }

void eliminarActividad()
{
	char codigo[9];
	char confirmacion;
	printf("Eliminar actividad\n");
	printf("¿Que actividad desea eliminar?(Introducir el codigo de la actividad)\n");
	fflush(stdout);
	scanf(" %s", codigo);
	printf("Confirmar la eliminacion de la actividad con codigo x (s/n)\n");
	fflush(stdout);
	scanf(" %c", &confirmacion);
	if (confirmacion == 's')
	{
		printf("La actividad ha sido eliminada con exito");
	    gestionarEmpleados();
	} else
	{
	   printf("La actividad no ha sido eliminada");
	   eliminarEmpleado();
	}
}
