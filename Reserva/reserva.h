#ifndef RESERVA_RESERVA_H_
#define RESERVA_RESERVA_H_

#include "../Actividad\actividad.h"

typedef struct{
	int codCliente;
	int codActividad;
	char* fecha;
	int cantPersonas;
}Reserva;

void visualizarReserva(Reserva reserva);
void hacerReserva();
void cancelarReserva();
#endif /* RESERVA_RESERVA_H_ */
