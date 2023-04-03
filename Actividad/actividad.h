#ifndef ACTIVIDA_ACTIVIDAD_H_
#define ACTIVIDA_ACTIVIDAD_H_

typedef struct{
	int codigo;
	char* nombre_act;
	char* dificultad;
	int limite_per_min;
	int limite_per_max;
	int edad_min;

}Actividad;

void gestionarActividades();
void visualizarMenuActividades();
void visualizarTodas();
void visualizarProvincia();
void visualizarDificultad();
void anyadirActividad();
void eliminarActividad();

#endif
