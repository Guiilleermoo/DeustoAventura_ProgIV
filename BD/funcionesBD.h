#ifndef BD_FUNCIONESBD_H_
#define BD_FUNCIONESBD_H_

void ShowActivities();
void ShowActivitiesInCommunity(char comunidad[]);
void InsertActivity(char nombre[], char dificultad[], int per_min, int per_max, int edad_min);
//void DeleteActivity();
void ShowWorkers();
void InsertWorker(char dni[], char nombre[], char apellido[], int telefono, char correo[], char contrasena[],char estatus[]);
//void DeleteWorker();
void registrarCliente(char dni[],char nombre[],char apellido[],int tfno,char correo[],char contrasena[],int cod_ciu);
void insertarAsistir(int cod_cliente,int cod_park,char fecha_asis[]);
void insertarLugar(int cod_ciu,char nombre_ciu[],int cod_prov);
void insertarOferta(int cod_park,int cod_act,int duracion);
void insertarReserva(int cod_cliente,int cod_act,char fecha_res[],int cant_per,int importe);
void insertarParque(int cod_park,char nombre[],int horaIni,int horaFin,int capacidad,int codCiu,int codEncargado);
void insertarProvincia(int cod_prov,char nombreProv[]);
void ShowReservas();
Empleado isWorker(char nombre[], char contrasena[]);
#endif
