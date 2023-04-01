#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_

typedef struct{
	char dni[9];
	char* nombre;
	char* apellido;
	char* mail;
	char* telefono;
}Cliente;
void imprimirCliente(Cliente cliente);

#endif
