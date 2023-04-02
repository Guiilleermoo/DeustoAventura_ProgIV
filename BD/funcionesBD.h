#ifndef BD_FUNCIONESBD_H_
#define BD_FUNCIONESBD_H_

#include "../Cliente/cliente.h"
#include "../Empleado/empleado.h"

void ShowActivities();
void ShowActivitiesInCommunity(char comunidad[]);
void InsertActivity(char nombre[], char dificultad[], int per_min, int per_max, int edad_min);
//void DeleteActivity();
Actividad findActivity(int codActividad);
void ShowWorkers();
void InsertWorker(char* dni, char *nombre, char *apellido, int telefono, char* correo, char *contrasena,char* estatus, int cod_park);
void isWorker(char nombre[], char contrasena[]);
//void DeleteWorker();
void newClient(char dni[],char nombre[],char apellido[],int tfno,char correo[],char contrasena[],int cod_ciu);
Cliente findClient(int codCliente);
int findClienDNI(char* dni);
void newAssist(int cod_cliente,int cod_park,char fecha_asis[]);
void newPlace(int cod_ciu,char nombre_ciu[],int cod_prov);
void insertOfer(int cod_park,int cod_act,int duracion);
void newReserve(int cod_cliente,int cod_act,char fecha_res[],int cant_per);
void ShowReserves();
void insertPark(int cod_park,char nombre[],int horaIni,int horaFin,int capacidad,int codCiu,int codEncargado);
void insertProvince(int cod_prov,char nombreProv[]);

void DeleteReserve(int codReserva, int codActividad);



#endif
