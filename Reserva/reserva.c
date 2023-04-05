 #include "reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\BD\funcionesBD.h"

#define MAX_NAME_SZ 256

void menuEmpleado();

void visualizarReservasCliente(){
	int cod_cliente, b;
	printf("Introduce el codigo del cliente:");
	fflush(stdout);
	scanf(" %d", &cod_cliente);

	ShowReservesClient(cod_cliente);

	printf("0. Pulsa enter para volver\n");
	fflush(stdout);
	scanf(" %d", &b);

	if (b == 0)
	{
		menuEmpleado();
	}
}

void visualizarReservas(){
	ShowReserves();
	int b;

	printf("0. Pulsa enter para volver\n");
	fflush(stdout);
	scanf(" %d", &b);

	if (b == 0)
	{
		menuEmpleado();
	}
}

void hacerReserva()
{
	char dni[9];
	 char fecha[20];
	 int numPersonas, codActividad;
	 char provincia[20];

	printf("Hacer Reserva\n");
	printf("Introduzca el DNI:  ");
	fflush(stdout);
	scanf(" %s", dni);

	if(isClient(dni) == 0)
	{
		char nombre[20], apellido[20], correo[20], contra[20];
		int cod_ciu, telefono;
		printf("Introduzca el nombre:  ");
		fflush(stdout);
		scanf(" %s", nombre);
		printf("Introduzca el apellido:   ");
		fflush(stdout);
		scanf(" %s", apellido);
		printf("Introduzca el numero de telefono:  ");
		fflush(stdout);
		scanf(" %i", &telefono);
		printf("Introduzca el correo:   ");
		fflush(stdout);
		scanf(" %s", correo);
		printf("Introduzca la contraseña:   ");
		fflush(stdout);
		scanf(" %s", contra);
		printf("Introduzca el codigo de la ciudad:   ");
		fflush(stdout);
		scanf(" %d", &cod_ciu);

		newClient(dni, nombre, apellido, telefono, correo, contra, cod_ciu);
	}

	printf("Introduzca la comunidad donde desea realizar la actividad:  ");
	fflush(stdout);
	scanf(" %s", provincia);
	ShowActivitiesInProvince(provincia);
	printf("Inserte el codigo de la actividad que deseas realizar:   ");
	fflush(stdout);
	scanf(" %d", &codActividad);
	printf("Introduza el numero de personas que van a realizar la activiad:  ");
	fflush(stdout);
	scanf(" %d", &numPersonas);
	printf("Introduza la fecha en la que quires realizar la actividad(DD/MM/AAAA):  ");
	fflush(stdout);
	scanf(" %s", fecha);

	int c = findClientDNI(dni);

	newReserve(c, codActividad, fecha, numPersonas);

	printf("\n\n");
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
	printf("Confirmar cancelacion de reserva(s/n):\n");
	fflush(stdout);
	scanf(" %c", &confirmar);
	if(confirmar == 's'){

		//llamar a funcion eliminar reserva por codigo
		DeleteReserve(idcliente, idactividad);
		}else{
			printf("La reserva no ha sido eliminada\n");
		}

	menuEmpleado();
}
