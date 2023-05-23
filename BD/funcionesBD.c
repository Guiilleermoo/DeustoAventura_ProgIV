#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#include "../Empleado/empleado.h"
#include "../Actividad/actividad.h"
#include "../Cliente/cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Reserva/reserva.h"

void menuJefe();
void menuEmpleado();
void main();

sqlite3 *db;
sqlite3_stmt *stmt;
int result;

char* load_config(char* filename, char* buscar)
{
    FILE* archivo;
    char linea[100];
    char* igual;
    char buscar2[20];

    archivo = fopen(filename, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return NULL;
    }

    char* resultado = NULL;
    while (fgets(linea, 100, archivo)) {
        int i = 0;
        while (linea[i] != '=') {
            buscar2[i] = linea[i];
            i++;
        }
        buscar2[i] = '\0';

        if (strcmp(buscar, buscar2) == 0) {
            igual = strchr(linea, '=');
            if (igual != NULL) {
                int longitud = strlen(igual + 1);
                resultado = (char*) realloc(resultado, longitud * sizeof(char));
                if (resultado == NULL) {
                    printf("Error al asignar memoria.\n");
                    return NULL;
                }
                strncpy(resultado, igual + 1, longitud);
                resultado[longitud - 1] = '\0';
            }
        }
    }

    fclose(archivo);
    return resultado;
}
void iniciarBD()
{
	char*ruta=load_config("conf.txt","ruta");
	printf("%s",ruta);
	printf("\n");
	sqlite3_open(ruta, &db);
	free(ruta);

}
void cerrarBD()
{
	sqlite3_close(db);
}

void mensajeLog(char* msg,char* error)
{
	FILE* f;
	f=fopen("log.txt","a");

	if(error==NULL){
		fprintf(f,"%s\n",msg);
	}else{
		fprintf(f,"%s: %s\n",msg,error);
	}

	fclose(f);
}

//** ACTIVITIES **//
void ShowActivities()
{
	char sql[] = "select * from ACTIVIDAD";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando actividades:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Codigo: %i - Nombre: %s - Dificultad: %s - Per_Min: %i - Per_Max: %i - Edad_Min: %i\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_int(stmt, 3), (int) sqlite3_column_int(stmt, 4), (int) sqlite3_column_int(stmt, 5));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

}
Reserva findReserva(int cod_cliente, int cod_act, char* fecha)
{
	Reserva reserva;

	char sql[] = "select * from RESERVA where COD_CLTE = ? and COD_ACT = ? and FECHA_RES = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 0, cod_cliente);
	sqlite3_bind_int(stmt, 1, cod_act);
	sqlite3_bind_text(stmt, 2, fecha, strlen(fecha), SQLITE_STATIC);

	result = sqlite3_step(stmt) ;

	reserva.codCliente = (int) sqlite3_column_int(stmt, 0);
	reserva.codActividad = (int) sqlite3_column_int(stmt, 1);
	reserva.fecha = (char *) sqlite3_column_text(stmt, 2);
	reserva.cantPersonas = (int) sqlite3_column_int(stmt, 3);

	sqlite3_finalize(stmt);

	return reserva;
}

void ShowActivitiesInProvince(char provincia[])
{
	char sql[] = "select A.COD_ACT, A.NOMBRE_ACT, A.DIFICULTAD, A.LIMITE_PER_MIN, A.LIMITE_PER_MAX, A.EDAD_MIN from ACTIVIDAD A, PARQUE P, LUGAR L, OFERTA O, PROVINCIA PR where A.COD_ACT = O.COD_ACT and O.COD_PARK = P.COD_PARK and P.COD_CIU = L.COD_CIU and L.COD_PROV = PR.COD_PROV and NOMBRE_PROV = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, provincia, strlen(provincia), SQLITE_STATIC);

	printf("\n");
	printf("Mostrando actividades de %s:\n", provincia);

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Cod Act: %d Nombre: %s - Dificultad: %s - Per_Min: %i - Per_Max: %i - Edad_Min: %i\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_text(stmt, 3), (int) sqlite3_column_text(stmt, 4), (int) sqlite3_column_text(stmt, 5));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);
}

void showActivitiesByDifficulty(char dificultad[])
{
	char sql[] = "select * from ACTIVIDAD where DIFICULTAD = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, dificultad, strlen(dificultad), SQLITE_STATIC);

	printf("\n");
	printf("Mostrando actividades con dificultad %s:\n", dificultad);

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Cod Act: %d Nombre: %s - Dificultad: %s - Per_Min: %i - Per_Max: %i - Edad_Min: %i\n", (int) sqlite3_column_int(stmt, 0), (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_text(stmt, 3), (int) sqlite3_column_text(stmt, 4), (int) sqlite3_column_text(stmt, 5));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);


}

void InsertActivity(char nombre[], char dificultad[], int per_min, int per_max, int edad_min)
{

	char sql[] = "INSERT INTO ACTIVIDAD (NOMBRE_ACT, DIFICULTAD, LIMITE_PER_MIN, LIMITE_PER_MAX,  EDAD_MIN) VALUES (?, ?, ?, ?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_text(stmt,1, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt,2, dificultad, strlen(dificultad), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, per_min);
	sqlite3_bind_int(stmt, 4, per_max);
	sqlite3_bind_int(stmt, 5, edad_min);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error insertando el actividad\n");
	}else{
		printf("Actividad insertada ");
	}

	sqlite3_finalize(stmt);
}

void DeleteActivity(int cod_act)
{
	char sql[] = "delete from ACTIVIDAD where COD_ACT = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, cod_act);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando la actividad\n");
	}else
	{
		printf("Actividad con codigo = %i borrado\n", cod_act);
	}
}

Actividad findActivity(int codActividad)
{
    Actividad actividad;

    char sql[] = "select * from ACTIVIDAD where COD_ACT = ?";

    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
    sqlite3_bind_int(stmt, 0, codActividad);


    result = sqlite3_step(stmt) ;

    actividad.nombre_act = (char *) sqlite3_column_text(stmt,1);
    actividad.dificultad= (char *) sqlite3_column_text(stmt, 2);
    actividad.limite_per_min = (int) sqlite3_column_int(stmt, 3);
    actividad.limite_per_max = (int) sqlite3_column_int(stmt, 4);
    actividad.edad_min = (int) sqlite3_column_int(stmt, 5);

    sqlite3_finalize(stmt);

    return actividad;
}

//** WORKERS**//
void ShowWorkers()
{

	char sql[] = "select * from EMPLEADO";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando empleados:\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("DNI: %s - Nombre Y Apellido: %s %s - Tfno: %i - Correo: %s - Estatus: %s\n", (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (char*) sqlite3_column_text(stmt, 3), (int) sqlite3_column_int(stmt, 4), (char*) sqlite3_column_text(stmt, 5), (char*) sqlite3_column_text(stmt, 7));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);


}

void InsertWorker(char* dni, char *nombre, char *apellido, int telefono, char* correo, char *contrasena,char* estatus, int cod_park) {


	    char sql[] = "INSERT INTO EMPLEADO ( DNI, NOMBRE_EMP, APELLIDO_EMP, TFNO, CORREO,  CONTRASENA, ESTATUS, COD_PARK) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
		sqlite3_bind_text(stmt,2, nombre, strlen(nombre), SQLITE_STATIC);
		sqlite3_bind_text(stmt,3, apellido, strlen(apellido), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 4, telefono);
		sqlite3_bind_text(stmt, 5, correo, strlen(correo), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 6, contrasena, strlen(contrasena), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 7, estatus, strlen(estatus), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 8, cod_park);

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error insertando el trabajador\n");
		}else{
			printf("Trabajador insertado ");
		}

		sqlite3_finalize(stmt);

}

void isWorker(char nombre[], char contrasena[]){
    Empleado emp;



    char sql[] = "select * from EMPLEADO where NOMBRE_EMP = ? and CONTRASENA = ?";

    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
    sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, contrasena, strlen(contrasena), SQLITE_STATIC);

    result = sqlite3_step(stmt);

    int existe;

    if (result == 100){
    	existe = 1;
		emp.DNI = (char*) sqlite3_column_text(stmt, 1);
		emp.nombre = (char*) sqlite3_column_text(stmt, 2);
		emp.apellido = (char*) sqlite3_column_text(stmt, 3);
		emp.tfno = (int) sqlite3_column_int(stmt, 4);
		emp.correo = (char*) sqlite3_column_text(stmt, 5);
		emp.contrasena = (char*) sqlite3_column_text(stmt, 6);
		emp.estatus = (char*) sqlite3_column_text(stmt, 7);
		emp.cod_park = (int) sqlite3_column_text(stmt, 8);
    } else if (result == 101){
    	existe = 0;
    }
    if (existe == 1){
    	if(emp.estatus[0] == 'J')
		{
			printf("Se ha iniciado sesion como JEFE con el nombre:  ");
			puts(nombre);

			printf("\n");

			sqlite3_finalize(stmt);


			menuJefe();
		} else if(emp.estatus[0] == 'E'){
			printf("Se ha iniciado sesion como EMPLEADO con el alias ");
			puts(nombre);

			printf("\n");

			sqlite3_finalize(stmt);



			menuEmpleado();
		}
    }else if (existe == 0){
    	sqlite3_finalize(stmt);
		printf("Empleado no encontrado\n");
		main();
    }

    cerrarBD();
}


void DeleteWorker(char* dni)
{

	char sql[] = "delete from EMPLEADO where DNI = ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		printf("Error borrando empleado\n");
	}else
	{
		printf("Empleado con DNI = %s borrado\n", dni);
	}

}

//** CLIENTS **//
void newClient(char dni[],char nombre[],char apellido[], int tfno,char correo[],char contrasena[],int cod_ciu){


	char sql[] = "insert into CLIENTE (DNI, NOMBRE_EMP, APELLIDO_EMP, TFNO, CORREO, CONTRASENA, COD_CIU) values (?, ?, ?, ?, ?, ?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
		sqlite3_bind_text(stmt,2, nombre, strlen(nombre), SQLITE_STATIC);
		sqlite3_bind_text(stmt,3, apellido, strlen(apellido), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 4, tfno);
		sqlite3_bind_text(stmt, 5, correo, strlen(correo), SQLITE_STATIC);
		sqlite3_bind_text(stmt, 6, contrasena, strlen(contrasena), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 7, cod_ciu);

		result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				printf("Error insertando el cliente\n");
			}else{
				printf("Cliente insertado - >  DNI: %s - Nombre Y Apellido: %s %s - TFNO: %i - Correo: %s - Cod-Ciudad: %d\n", dni, nombre, apellido, tfno, correo, cod_ciu);
			}

		sqlite3_finalize(stmt);

		cerrarBD();
}

Cliente findClient(int codCliente)
{
    Cliente cliente;


    char sql[] = "select * from CLIENTE where COD_CLTE = ?";

    sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
    sqlite3_bind_int(stmt, 1, codCliente);


    result = sqlite3_step(stmt) ;

    cliente.dni = (char *) sqlite3_column_text(stmt,1);
    cliente.nombre = (char *) sqlite3_column_text(stmt, 2);
    cliente.apellido = (char *) sqlite3_column_text(stmt, 3);
    cliente.telefono = (int) sqlite3_column_int(stmt, 4);
    cliente.mail = (char *) sqlite3_column_text(stmt, 5);

    sqlite3_finalize(stmt);



    return cliente;
}
int findClientDNI(char* dni)
{
	int codigo_cliente;

	char sql[] = "select * from CLIENTE where DNI = ?";

	 sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	 sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);

	 result = sqlite3_step(stmt) ;

	 codigo_cliente = (int) sqlite3_column_int(stmt, 0);

	 sqlite3_finalize(stmt);

	 return codigo_cliente;
}

int isClient(char* dni)
{
	int existe = 0;
	char sql[] = "select * from CLIENTE where DNI = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);

	while(sqlite3_step(stmt) == SQLITE_ROW)
	{
		existe = 1;
		break;
	}

	sqlite3_finalize(stmt);

	cerrarBD();

	return existe;


}


//** ASSISTS **//
void newAssist(int cod_cliente,int cod_park,char fecha_asis[])
{

	char sql[] = "insert into ASISTIR (COD_CLTE, COD_PARK, FECHA_ASIS) values (?, ?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, cod_cliente);
	sqlite3_bind_int(stmt,2, cod_park);
	sqlite3_bind_text(stmt, 3, fecha_asis,strlen(fecha_asis), SQLITE_STATIC);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
	{
		printf("Error insertando Asistir\n");
	} else {
		printf("Asistir insertado - >  CodCliente: %d - CodPark: %d - Fecha Asistencia: %s\n", cod_cliente,cod_park,fecha_asis);
	}



}

//** PLACES **//

void newPlace(int cod_ciu,char nombre_ciu[],int cod_prov)
{

	char sql[] = "insert into LUGAR (COD_CIU, NOMBRE_CIU, COD_PROV) values (?, ?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, cod_ciu);
	sqlite3_bind_text(stmt,2, nombre_ciu,strlen(nombre_ciu), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, cod_prov);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
	{
		printf("Error insertando Lugar\n");
	} else {
		printf("Lugar insertado - >  CodCiud: %d - Nombre de la Ciudad: %s - CodProv: %d\n", cod_ciu,nombre_ciu,cod_prov);
	}


}

//** PLACES **//
void insertOffer(int cod_park,int cod_act,int duracion)
{

	char sql[] = "insert into OFERTA (COD_PARK, COD_ACT, DURACION) values (?, ?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, cod_park);
	sqlite3_bind_int(stmt,2, cod_act);
	sqlite3_bind_int(stmt, 3, duracion);


	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
	{
		printf("Error insertando Oferta\n");
	} else {
		printf("Oferta insertada - >  CodPark: %d - CodAct: %d - Duracion: %d\n", cod_park,cod_act,duracion);
	}



}

//** RESERVES **//

void newReserve(int cod_cliente,int cod_act,char fecha_res[],int cant_per)
{
		char sql[] = "insert into RESERVA (COD_CLTE, COD_ACT, FECHA_RES,CANT_PER) values (?, ?, ?, ?)";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

		sqlite3_bind_int(stmt, 1, cod_cliente);
		sqlite3_bind_int(stmt,2, cod_act);
		sqlite3_bind_text(stmt,3, fecha_res,strlen(fecha_res), SQLITE_STATIC);
		sqlite3_bind_int(stmt, 4, cant_per);

		result = sqlite3_step(stmt);

		if (result != SQLITE_DONE)
		{
			printf("Error insertando Reserva\n");
		} else
		{
			printf("Reserva insertada - >  CodCliente: %d - CodAct: %d - Fecha de la Reserva: %s - Numero de personas: %d\n", cod_cliente,cod_act,fecha_res,cant_per);
		}
}

void ShowReserves()
{
	char sql[] = "select * from RESERVA";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando reservas:\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Codigo del Cliente: %d - Codigo Actividad: %d - Fecha de la reserva: %s - Numero de personas: %i\n", (int) sqlite3_column_int(stmt, 0), (int) sqlite3_column_int(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_int(stmt, 3));
		}
	} while (result == SQLITE_ROW);

	printf("\n");

	sqlite3_finalize(stmt);


}

void ShowReservesClient(int cod_cl)
{
	char sql[] = "select * from RESERVA where COD_CLTE = ?";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_int(stmt, 1, cod_cl);

	printf("\n");
	printf("Mostrando reservas:\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Codigo del Cliente: %d - Codigo Actividad: %d - Fecha de la reserva: %s - Numero de personas: %i\n", (int) sqlite3_column_int(stmt, 0), (int) sqlite3_column_int(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_int(stmt, 3));
		}
	} while (result == SQLITE_ROW);

	printf("\n");

	sqlite3_finalize(stmt);
}

void DeleteReserve(int codcliente, int codActividad)
{

	char sql[] = "delete from RESERVA where  COD_CLTE= ? and COD_ACT= ?";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, codcliente);
	sqlite3_bind_int(stmt,2, codActividad);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
	{
		printf("Error eliminando la reserva\n");
	} else
	{
		printf("La reserva ha sido eliminada\n");
	}
}

//** PARKS **//
void insertPark(int cod_park,char nombre[],int horaIni,int horaFin,int capacidad,int codCiu,int codEncargado)
{

	char sql[] = "insert into PARQUE (COD_PARK, NOMBRE_PARK, HORA_INI, HORA_FIN, CAPACIDAD, COD_CIU, ENCARGADO) values (?, ?, ?, ?, ?, ?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, cod_park);
	sqlite3_bind_text(stmt,2, nombre,strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_int(stmt,3, horaIni);
	sqlite3_bind_int(stmt,4, horaFin);
	sqlite3_bind_int(stmt, 5, capacidad);
	sqlite3_bind_int(stmt, 6, codCiu);
	sqlite3_bind_int(stmt, 7, codEncargado);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
	{
		printf("Error insertando Parque\n");
	} else
	{
		printf("Parque insertado - >  CodPark: %d - Nombre: %s - Hora Inicio: %d - Hora fin: %d - Capacidad: %d - CodCiudad: %d - CodEncargado: %d\n", cod_park,nombre,horaIni,horaFin,capacidad,codCiu,codEncargado);
	}

}

//** PROVINCIES **//

void insertProvince(int cod_prov,char nombreProv[])
{

	char sql[] = "insert into PROVINCIA (COD_PROV, NOMBRE_PROV) values (?, ?)";
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_int(stmt, 1, cod_prov);
	sqlite3_bind_text(stmt,2, nombreProv,strlen(nombreProv), SQLITE_STATIC);

	result = sqlite3_step(stmt);

	if (result != SQLITE_DONE)
	{
		printf("Error insertando Provincia\n");
	} else
	{
		printf("Provincia insertada - >  CodProv: %d - Nombre: %s\n", cod_prov,nombreProv);
	}


}


