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

void gestionarActividades(void);
void visualizarMenuActividades(void);
void visualizarTodas(void);
void visualizarCiudad(void);
void visualizarDificultad(void);
void anyadirActividad(void);
void eliminarActividad(void);

#endif
