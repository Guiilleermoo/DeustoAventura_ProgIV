#include "CSV/readCSV.h"

#include <stdio.h>
#include <stdlib.h>
#include "Reserva/reserva.h"
#include "Actividad/actividad.h"
#include "Empleado/empleado.h"


    int main(void)
    {
//    char *filename="";
//    ReadCsvData(filename);           // Leer datos csv
//    ShowCsvData();                   // Muestra los datos csv leídos a través de la consola
//    FreeCsvData();				   // Libera la memoria dinámica

    printf("Gestion de actividades DeustoAventura\n");
    printf("1. Iniciar sesion\n");
    printf("2. Registro de usuario\n");
    printf("3. JEFE\n");
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
	} else if (a == 3) {
		menuJefe();
	} else if (a == 0) {
		printf("FIN");
		exit (-1);
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

    void menuEmpleado(){
    	 printf("Gestion de actividades DeustoAventura\n");
    	 printf("1. Hacer una reserva\n");
    	 printf("2. Cancelar una reserva\n");
    	 printf("3. Visualizar una reserva\n");
    	 printf("0. Salir\n");
    	 fflush(stdout);
    	 int a;
    	 scanf("%d", &a);
    	 printf("Se leyó el caracter: %d\n", a);
    	 fflush(stdout);
    	 if (a == 1) {
    		 hacerReserva();
    	 } else if (a == 2) {
    		 cancelarReserva();

    	 }  else if (a == 3) {
    		 //visualizarReservas();

    	 }else if (a == 0) {

    	 }
    }

    void menuJefe(void){
    	printf("Menu principal jefe\n");
		printf("1. Gestionar empleados\n");
		printf("2. Gestionar actividades\n");
		printf("0. Volver\n");
		fflush(stdout);
		int a;


		scanf(" %d", &a);
		printf("Se leyó el caracter: %d\n", a);
		fflush(stdout);
		if (a == 1) {
			gestionarEmpleados();
		} else if (a == 2) {
			gestionarActividades();
		} else if (a == 0) {
			main();
		}
	}

//    void gestionarEmpleados(void){
//        printf("Gestionar empleado\n");
//    	printf("1. Visualizar empleados\n");
//    	printf("2. Añadir empleado\n");
//    	printf("3. Borrar empleado\n");
//    	printf("0. Volver\n");
//    	fflush(stdout);
//    	int a;
//
//
//    	scanf(" %d", &a);
//    	printf("Se leyó el caracter: %d\n", a);
//    	fflush(stdout);
//    	if (a == 1) {
//    		visualizarEmpleados();
//    	} else if (a == 2) {
//    		anyadirEmpleado();
//    	} else if (a == 3) {
//    	    eliminarEmpleado();
//    	} else if (a == 0) {
//    		main();
//    		}
//    	}

//    void visualizarEmpleados(void){
//    	int nEmpleados = 5;
//    	int i, a;
//    	printf("Lista de empleados\n");
//    	for (i = 0; i < nEmpleados; ++i) {
//    		printf("	%i. Empleado\n", i);
//    		printf("		a. DNI\n");
//    		printf("		a. Nombre\n");
//    		printf("		a. Email\n");
//    		printf("		a. Estatus\n");
//    		printf("		a. Telefonos\n");
//		}
//
//    	printf("0. Volver\n");
//    	fflush(stdout);
//    	scanf(" %d", &a);
//
//    	if (a == 0) {
//    	    gestionarEmpleados();
//    	}
//    }

//    void anyadirEmpleado(void){
//       	char dni[9], nombre[20], apellido[20], usuario[20], contra[20], correo[20], telefono[9], status[20];
//       	printf("Añadir empleado\n");
//       	printf("DNI\n");
//       	fflush(stdout);
//       	scanf(" %s", dni);
//       	printf("Nombre\n");
//       	fflush(stdout);
//       	scanf(" %s", nombre);
//       	printf("Apellido\n");
//       	fflush(stdout);
//       	scanf(" %s", apellido);
//       	printf("Email\n");
//       	fflush(stdout);
//       	scanf(" %s", correo);
//       	printf("Nombre de usuario\n");
//       	fflush(stdout);
//       	scanf(" %s", usuario);
//       	printf("Introduzca la contraseña\n");
//       	fflush(stdout);
//       	scanf(" %s", contra);
//       	printf("Introduzca el numero de telefono\n");
//       	fflush(stdout);
//       	scanf(" %s", telefono);
//    	printf("Introduzca el numero de estatus\n");
//        fflush(stdout);
//        scanf(" %s", status);
//
//        printf("El empleado ha sido añadido");
//        gestionarEmpleados();
//       }

//    void eliminarEmpleado(void){
//       char dni[9];
//       char confirmacion;
//       printf("Eliminar empleado\n");
//       printf("¿Que empleado desea eliminar?(Introducir el DNI del empleado)\n");
//       fflush(stdout);
//       scanf(" %s", dni);
//       printf("Confirmar la eliminacion del empleado con codigo x (s/n)\n");
//       fflush(stdout);
//       scanf(" %c", confirmacion);
//       if (confirmacion == 's') {
//    	   printf("El empleado ha sido eliminado con exito");
//    	   gestionarEmpleados();
//       } else {
//    	   printf("El empleado no ha sido eliminado");
//    	   eliminarEmpleado();
//       }
//    }

//    void gestionarActividades(void){
//        printf("Menu actividades\n");
//        printf("1. Visualizar actividades\n");
//        printf("2. Añadir actividad\n");
//        printf("3. Eliminar actividad\n");
//        printf("0. Volver\n");
//    	fflush(stdout);
//    	int a;
//
//
//    	scanf(" %d", &a);
//    	printf("Se leyó el caracter: %d\n", a);
//    	fflush(stdout);
//    	if (a == 1) {
//    		gestionarEmpleados();
//    	} else if (a == 2) {
//    		registroUsuario();
//    	} else if (a == 3) {
//    	    registroUsuario();
//    	} else if (a == 0) {
//    		main();
//    	}
//    }

//    void visualizarActividades(void){
//    	printf("Ver actividades\n");
//    	printf("1. Visualizar todas actividades\n");
//    	printf("2. Buscar actividades por ciudad\n");
//    	printf("3. Buscra actividades por nivel de dificultad\n");
//    	printf("0. Volver\n");
//    	fflush(stdout);
//    	int a;
//
//
//    	scanf(" %d", &a);
//    	printf("Se leyó el caracter: %d\n", a);
//    	fflush(stdout);
//    	if (a == 1) {
//    	    visualizarTodas();
//    	} else if (a == 2) {
//    	    visualizarCiudad();
//    	} else if (a == 3) {
//    	    visualizarDificultad();
//    	} else if (a == 0) {
//    	   gestionarActividades();
//    	}
//    }

//    void visualizarTodas(void){
//       	int nActividades = 5;
//       	int i, a;
//       	printf("Lista de todas las actividades\n");
//       	for (i = 0; i < nActividades; ++i) {
//       		printf("	%i. Actividad\n", i);
//   		}
//
//       	printf("0. Pulsa enter para volver\n");
//       	fflush(stdout);
//       	scanf(" %d", &a);
//
//       	if (a == 0) {
//       	    visualizarActividades();
//       	}
//    }

//    void visualizarCiudad(void){
//    	char ciudad[20];
//    	printf("Que ciudad desea consultar\n");
//    	fflush(stdout);
//    	scanf(" %s", ciudad);
//
//        int nActividades = 5;
//        int i, a;
//        printf("Lista de todas las actividades de x\n");
//        for (i = 0; i < nActividades; ++i) {
//            printf("	%i. Actividad\n", i);
//        }
//
//        printf("0. Pulsa enter para volver\n");
//        fflush(stdout);
//        scanf(" %d", &a);
//
//        if (a == 0) {
//           	visualizarActividades();
//        }
//    }

//    void visualizarDificultad(void){
//        int b;
//    	printf("Que nivel de dificultad desea consultar(1-10)\n");
//        fflush(stdout);
//        scanf(" %d", &b);
//
//
//        int nActividades = 5;
//        int i, a;
//        printf("Lista de todas las actividades con dificultad %i\n", b);
//        for (i = 0; i < nActividades; ++i) {
//            printf("	%i. Actividad\n", i);
//        }
//
//        printf("0. Pulsa enter para volver\n");
//        fflush(stdout);
//        scanf(" %d", &a);
//
//        if (a == 0) {
//           visualizarActividades();
//        }
//    }
