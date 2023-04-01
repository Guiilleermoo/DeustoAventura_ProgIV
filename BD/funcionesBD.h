#ifndef BD_FUNCIONESBD_H_
#define BD_FUNCIONESBD_H_

void ShowActivities();
void ShowActivitiesInCommunity(char comunidad[]);
void InsertActivity(char nombre[], char dificultad[], int per_min, int per_max, int edad_min);
//void DeleteActivity();
void ShowWorkers();
void InsertWorker(char dni[], char nombre[], char apellido[], int telefono, char correo[], char contrasena[],char estatus[]);
//void DeleteWorker();

#endif
