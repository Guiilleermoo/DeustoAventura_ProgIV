#include <stdio.h>
#include "sqlite3.h"
#include <string.h>

sqlite3 *db;
sqlite3_stmt *stmt;
int result;

void ShowActivities()
{
	sqlite3_open("DeustoAventura.db", &db);

	char sql[] = "select * from ACTIVIDAD";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando actividades:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Nombre: %s - Dificultad: %s - Per_Min: %i - Per_Max: %i - Edad_Min: %i\n", (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (int) sqlite3_column_text(stmt, 3), (int) sqlite3_column_text(stmt, 4), (int) sqlite3_column_text(stmt, 5));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

	sqlite3_close(db);
}

void ShowActivitiesInCommunity(char comunidad[])
{
	sqlite3_open("DeustoAventura.db", &db);

	char sql[] = "select NOMBRE_ACT, DIFICULTAD, LIMITE_PER_MIN, LIMITE_PER_MAX, EDAD_MIN"
			"from ACTIVIDAD A, PARQUE P, LUGAR L, OFERTA O"
			"where A.COD_ACT = O.COD_ACT and O.COD_PARK = P.COD_PARK and P.COD_CIU = L.COD_CIU and NOMBRE_CIU = ?";


	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;
	sqlite3_bind_text(stmt, 1, comunidad, strlen(comunidad), SQLITE_STATIC);

	printf("\n");
	printf("Mostrando actividades de %s:\n", comunidad);
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("Nombre: %s - Dificultad: %s - Per_Min: %i - Per_Max: %i - Edad_Min: %i\n", (char*) sqlite3_column_text(stmt, 0), (char*) sqlite3_column_text(stmt, 1), (int) sqlite3_column_text(stmt, 2), (int) sqlite3_column_text(stmt, 3), (int) sqlite3_column_text(stmt, 4));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

	sqlite3_close(db);
}

void InsertActivity(char nombre[], char dificultad[], int per_min, int per_max, int edad_min)
{
	sqlite3_open("DeustoAventura.db", &db);

	char sql[] = "insert into ACTIVIDAD (NOMBRE_ACT, DIFICULTAD, LIMITE_PER_MIN, LIMITE_PER_MAX, EDAD_MIN) values (?, ?, ?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_text(stmt, 1, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, dificultad, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 3, per_min);
	sqlite3_bind_int(stmt, 4, per_max);
	sqlite3_bind_int(stmt, 5, edad_min);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error insertando la actividad\n");
	}else{
		printf("Actividad insertada - >  Nombre: %s - Dificultad: %s - Per_Min: %i - Per_Max: %i - Edad_Min: %i\n", nombre, dificultad, per_min, per_max, edad_min);
	}

	sqlite3_close(db);
}

/*void DeleteActivity()
{
	sqlite3_open("DeustoAventura.db", &db);


	sqlite3_close(db);
}*/

void ShowWorkers()
{
	sqlite3_open("DeustoAventura.db", &db);

	char sql[] = "select * from EMPLEADO";

	sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL) ;

	printf("\n");
	printf("Mostrando empleados:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			printf("DNI: %s - Nombre Y Apellido: %s %s - Tfno: %i - Correo: %s - Estatus: %s\n", (char*) sqlite3_column_text(stmt, 1), (char*) sqlite3_column_text(stmt, 2), (char*) sqlite3_column_text(stmt, 3), (int) sqlite3_column_text(stmt, 4), (char*) sqlite3_column_text(stmt, 5), (char*) sqlite3_column_text(stmt, 7));
		}
	} while (result == SQLITE_ROW);
	printf("\n");

	sqlite3_finalize(stmt);

	sqlite3_close(db);
}

void InsertWorker(char dni[], char nombre[], char apellido[], int telefono, char correo[], char contrasena[],char estatus[])
{
	sqlite3_open("DeustoAventura.db", &db);

	char sql[] = "insert into EMPLEADO (DNI, NOMBRE_EMP, APELLIDO_EMP, TFNO, CORREO, CONTRASENA, ESTATUS) values (?, ?, ?, ?, ?, ?, ?)";

	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

	sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, nombre, strlen(nombre), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 3, apellido, strlen(apellido), SQLITE_STATIC);
	sqlite3_bind_int(stmt, 4, telefono);
	sqlite3_bind_text(stmt, 5, correo, strlen(correo), SQLITE_STATIC);
	sqlite3_bind_text(stmt, 5, estatus, strlen(estatus), SQLITE_STATIC);

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error insertando el empleado\n");
	}else{
		printf("Empleado insertado - >  DNI: %s - Nombre Y Apellido: %s %s - TFNO: %i - Correo: %s - Estatus: %s\n", dni, nombre, apellido, telefono, correo, estatus);
	}

	sqlite3_close(db);
}

/*void DeleteWorker()
{

}*/
