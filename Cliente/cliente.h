#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_

typedef struct{
	char* dni;
	char* nombre;
	char* apellido;
	char* mail;
	int telefono;
}Cliente;
void imprimirCliente(Cliente cliente);

#endif
