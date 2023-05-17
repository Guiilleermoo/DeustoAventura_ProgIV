#include "CSV/readCSV.h"

#include <iostream>
using namespace std;
#include <stdio.h>
#include "BD/funcionesBD.h"


void menuReservas()
{
	cout << "Gestion de reservas\n\n" << endl;
		 cout << "1. Visualizar mis reservas\n" << endl;
		 cout << "2. Hacer reserva\n" << endl;
		 cout << "3. Cancelar reserva\n" << endl;
		 cout << "0. Volver\n");
		 cout << "Elija su opcion:  " << endl;
		fflush(stdout);
		cout << "\n" << endl;

		int a;
		cin >> &a;
		if (a == 1)
		  {
			//Pedir DNI y mostrar las reservas de ese cliente
		  } else if (a == 2)
		   	{
			  //Realizar la reserva
		   	}else if (a == 3)
		   	{
		   		//Pedir DNI y mostrar als reservas + pedir opcion para borrar reserva
		   	} else if (a == 0)
		   	{
		   		int menuCliente();
		   	}
}

void menuCliente()
{
	 cout << "Menu Principal\n\n" << endl;
	 cout << "1. Ver actividades\n" << endl;
	 cout << "2. Gestionar reservas\n" << endl;
	 cout << "0. Volver\n");
	 cout << "Elija su opcion:  " << endl;
	fflush(stdout);
	cout << "\n" << endl;

	int a;
	cin >> &a;
   fflush(stdout);

   if (a == 1)
   	{
	   visualizarMenuActividades();
   	} else if (a == 2)
   	{
   		menuReservas();
   	} else if (a == 0)
   	{
   		int main();
   	}
}

void inicioSesion(void)
{
    char DNI[9], contra[20];
    cout << "INICIO DE SESION\n\n" << endl;

    cout << "Introduzca el DNI: \t" << endl;
	fflush(stdout);
	cin >> DNI;
	cout << "Introduzca la contrasena:  " << endl;
	fflush(stdout);
	cout << "\n" << endl;
	cin >> contra;

	if(isClient(DNI) == 1)
	{
		cout << "Login realizado correctamente" << endl;
		menuCliente();
	}

}

int main()
{
	 iniciarBD();
	 cout << "GESTION DE DEUSTOAVENTURA\n\n" << endl;
	 cout << "1. Iniciar sesion\n" << endl;
	 cout << "2. Registrar usuario\n" << endl;
	 cout << "0. Salir\n");
	 cout << "Elija su opcion:  " << endl;
	fflush(stdout);
	cout << "\n" << endl;
	int a;


	cin >> &a;
    fflush(stdout);
    if (a == 1) {
		inicioSesion();
	} else if (a == 0) {
		cout << "FIN" << endl;
		cerrarBD();
		break;
	}
    cerrarBD();

    return 0;
}


