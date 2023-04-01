#include "reserva.h"
#include <stdio.h>
#include "..\BD\funcionesBD.h"

void menuEmpleado();

void visualizarReserva(Reserva reserva){
	Cliente c= findClient(reserva.codCliente);
	Actividad a= findActivity(reserva.codActividad);
	printf("DNI: %s Nombre:%s Apellido: %s Telefono: %i Correo: %s Actividad: %s Numeros de personas: %i Fecha: %s:",c.dni,c.nombre,c.apellido,c.telefono, c.mail, a.nombre_act, reserva.cantPersonas, reserva.fecha);
}

void hacerReserva()
{
	 char dni[9], nombre[20], apellido[20], correo[20], telefono[9],confirmar;
	 int numPersonas;
	 char* fecha;
	 int codActividad;
	 char* comunidad;
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


	   	// falta por hacer
	   	printf("Introduzca la comunidad donde desea realizar la actividad:\n");
		fflush(stdout);
		scanf(" %s", comunidad);
	 	printf("Actividades que peudes realizar\n");
		   	ShowActivitiesInCommunity(comunidad);
		printf("Inserte el codigo de la actividad que deseas realizar:\n ");
		fflush(stdout);
		   	scanf(" %d", &codActividad);


	   	printf("Introduza el numero de personas que van a realizar la activiad:\n");
	   	fflush(stdout);
	   	scanf(" %i", &numPersonas);
	   	printf("Introduza la fecha en la que quires realizar la actividad(DD MM AAAA):\n");
	   	fflush(stdout);
	   	scanf("%s",&fecha);

		printf("Confirmar reservas(S/N):\n");
		fflush(stdout);
		scanf("%c", &confirmar);
		//LAMAR FUNCION QUE METE LA RESERVA

		if(confirmar=='S'){
			int c= findClienDNI(dni);
			Actividad a= findActivity(codActividad);

			newReserve(c, codActividad, fecha, numPersonas);

			}else{
				printf("Fue cancelada la reserva\n");
			}
		menuEmpleado();

}

void cancelarReserva()
{
	char confirmar;
	int idcliente;
	int idactividad;
	printf("Cancelar Reserva\n\n");
	void ShowReserves();
	printf("1.¿Id del cliente que quiere cancelar la reserva?\n");
	fflush(stdout);
	scanf("%d",&idcliente);
	printf("2.¿Id del actividad que quiere cancelar la reserva?\n");
	fflush(stdout);
	scanf("%d",&idactividad);
	printf("Confirmar cancelacion de reserva(S/N):\n");
	fflush(stdout);
	scanf("%c", &confirmar);
	if(confirmar=='S'){

		//llamar a funcion eliminar reserva por codigo
		DeleteReserve(idcliente, idactividad);
		}else{
			printf("La reserva no ha sido eliminada\n");
		}

	menuEmpleado();
}
