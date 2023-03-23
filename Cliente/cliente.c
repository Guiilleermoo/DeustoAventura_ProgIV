/*
 * cliente.c
 *
 *  Created on: 23 mar 2023
 *      Author: borja
 */
#include <stdio.h>
#include "cliente.h"
void imprimirCliente(Cliente c){
	printf("DNI: %s Nombre: %s Apellido: %s Mail: %s, Telefono %s",c.dni,c.nombre,c.apellido,c.mail,c.telefono);
}


