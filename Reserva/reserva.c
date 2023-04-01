#include "reserva.h"
#include <stdio.h>
#include "..\BD\funcionesBD.h"
void menuEmpleado();

void visualizarReserva(Reserva reserva){
	Cliente c= encontrarCliente(reserva.codCliente);
	Actividad a= encontrarActividad(reserva.codActividad);
	printf("DNI: %s Nombre:%s Apellido: %s Telefono: %i Correo: %s Actividad: %s Numeros de personas: Fecha: %s:",c.dni,c.nombre,c.apellido,c.telefono, c.mail, a.nombre_act, reserva.cantPersonas,reserva.fecha);
}

void hacerReserva()
{
	 char dni[9], nombre[20], apellido[20], correo[20], telefono[9],confirmar;
	 int numPersonas,dia,mes,ano,hora;
		printf("Hacer Reserva\n");
	   	printf("Introduzca el DNI\n");
	   	fflush(stdout);
	    scanf(" %s", dni);
	    printf("Introduzca el nombre\n");
	    fflush(stdout);
	   	scanf(" %s", nombre);
	   	printf("Introduzca el apellido\n");
	   	fflush(stdout);
	   	scanf(" %s", apellido);
	   	printf("Introduzca el numero de telefono\n");
		fflush(stdout);
		scanf(" %s", telefono);
	   	printf("Introduzca el correo\n");
	   	fflush(stdout);
	   	scanf(" %s", correo);
	   	printf("Intoduza la actividad que desea realizar\n");
	   	// falta por hacer
	   	printf("Introduzca la localidad donde desea realizar la actividad:\n");
	  	// falta por hacer
	   	printf("Introduza el numero de personas que van a realizar la activiad:\n");
	   	fflush(stdout);
	   	scanf(" %i", &numPersonas);
	   	printf("Introduza el dia que desea realizar la actividad(DD MM AAAA):\n");
	   	fflush(stdout);
	   	scanf("%d %d %d",&dia,&mes,&ano);
		printf("Introduza a al hora que desea realizar al actividada:\n");
		fflush(stdout);
		scanf("%i",&hora);
		printf("Confirmar reservas(S/N):\n");
		fflush(stdout);
		scanf("%c", &confirmar);
		//LAMAR FUNCION QUE METE LA RESERVA
		menuEmpleado();

}

void cancelarReserva()
{
	char confirmar;
	int num;
	printf("Cancelar Reserva\n\n");
	printf("1.¿Que reserva desea cancelar?(Intoducir el numero de la resrva)");
	fflush(stdout);
	scanf("%d",&num);
	printf("Confirmar cancelacion de reserva(S/N):\n");
	fflush(stdout);
	scanf("%c", &confirmar);
	//LLAMAR A LA FUNCION QUE CANCELE LA RESERVA
	menuEmpleado();
}
