#include "CSV/readCSV.h"

#include <stdio.h>
#include <stdlib.h>

    int main(void)
    {
//    char *filename="";
//    ReadCsvData(filename);           // Leer datos csv
//    ShowCsvData();                   // Muestra los datos csv leídos a través de la consola
//    FreeCsvData();				   // Libera la memoria dinámica

    printf("Gestion de actividades DeustoAventura\n");
    printf("1. Iniciar sesion\n");
    printf("2. Registro de usuario\n");
    printf("0. Salir\n");
    fflush(stdout);
    int a;


    scanf(" %d", &a);
    printf("Se leyó el caracter: %d\n", a);
    fflush(stdout);
    if (a == 1) {
		inicioSesion();
	} else if (a == 2) {
		registroUsuario();
	} else if (a == 0) {

	}

//    	char a, b;
//    	    printf("Ingrese el primer caracter:\n");
//    	    fflush(stdout);
//    	    scanf(" %c", &a);
//    	    printf("Se leyó el caracter: %c\n", a);
//    	    printf("Ingrese el segundo caracter:\n");
//    	    fflush(stdout);
//    	    scanf(" %c", &b);
//    	    printf("Se leyó el caracter: %c\n", b);

    return 0;

    }

    void inicioSesion(void){
    	char nombre[20], contra[20];
    	printf("Inicio de sesion\n");
    	printf("Introduzca el usuario\n");
		fflush(stdout);
		scanf(" %s", nombre);
		printf("Introduzca la contraseña\n");
		fflush(stdout);
		scanf(" %s", contra);
		printf("Se ha iniciado sesion con el alias ");
		puts(nombre);
    }

    void registroUsuario(void){

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
    }

