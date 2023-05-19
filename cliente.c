/*
 * cliente.c
 *
 *  Created on: 19 may 2023
 *      Author: borja
 */

void inicioSesion(void);
int main(){
	int numero;
	cout<<"DEUTOAVENTURA"<<endl;
	cout<<"1. Iniciar Sesion"<<endl;
	cout<<"2, Resgistrase"<<endl;
	cout<<"0. Salir"<<endl;
	fflush(stdout);
	cin>>numero;
	return 1;
}

void inicioSesion(void)
{
    char nombre[20], contra[20];
    cout<<"INICIO DE SESION"<<endl;

    cout<<"Introduzca el usuario: "<<endl;
	fflush(stdout);
	cin>>nombre;
	cout<<"Introduzca la contraseña:  "<<endl;
	fflush(stdout);

	cin>>contra;

}
void registrarse(){
	char dni[20], nombre[20],apellido[20],usuario[20],contra[20],correo[20],tlf[20];
cot<<"Registrarse"<<endl;
cout<<"Introdur DNI: "<<endl;
fflush(stdout);
cin>>dni;
cout<<"Introdur Nombre: "<<endl;
fflush(stdout);
cin>>nombre;
cout<<"Introdur Apellido: "<<endl;
fflush(stdout);
cin>>apellido;
cout<<"Introdur Usuario: "<<endl;
fflush(stdout);
cin>>usuario;
cout<<"Introdur Contra: "<<endl;
fflush(stdout);
cin>>contra;
cout<<"Introdur Tlf: "<<endl;
fflush(stdout);
cin>>tlf;

cout<<"Usuario creado correctamente!";

}
void principal(){
	int numero;
	cout<<"1. Ver Acitivdades"<<endl;
	cout<<"2. Gestioanr Reservar"<<endl;
	cout<<"0. Volver"<<endl;
	fflush(stdout);
	cin>>numero;
}
void actividades(){
	int numero;
	cout<<"1. Visualizar todas"<<endl;
	cout<<"2. Buscar por Ciudad"<<endl;
	cout<<"3. Buscar por Nivel de dificultad"<<endl;
	cout<<"0. Volver"<<endl;
	fflush(stdout);
	cin>>numero;
}
