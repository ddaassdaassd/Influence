#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

using namespace std;

int main (int argc, char *argv[]) {
	
	int sock_conn, sock_listen, ret;
	struct sockaddr_in serv_adr;
	char peticion[512];
	char respuesta[512];
	// INICIALITZACIONS
	// Obrim el socket
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	// Fem el bind al port
	
	
	memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
	serv_adr.sin_family = AF_INET;
	
	// asocia el socket a cualquiera de las IP de la m?quina. 
	//htonl formatea el numero que recibe al formato necesario
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	// escucharemos en el port 9070
	serv_adr.sin_port = htons(9000);
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	//La cola de peticiones pendientes
	if (listen(sock_listen, 3) < 0)
		printf("Error en el Listen");
	
	int finConexion = 0;
	
	while (finConexion==0)
	{
		printf ("Escuchando\n");
		
		sock_conn = accept(sock_listen, NULL, NULL);
		printf ("He recibido conexi?n\n");
		//sock_conn es el socket que usaremos para este cliente
		
		// Ahora recibimos el mensaje, que dejamos en buff
		ret=read(sock_conn,peticion, sizeof(peticion));
		printf ("Recibido\n");
		
		// Tenemos que a?adirle la marca de fin de string 
		// para que no escriba lo que hay despues en el buffer
		peticion[ret]='\0';
		
		printf ("Peticion: %s\n",peticion);
		

		char *p = strtok(peticion, "/");
		int codigo = atoi (p);
			
		if (p == 0)
			finConexion = 1;
				
		else
		{
			p = strtok (NULL, "/");
			char usuario[20];
			strcpy (usuario, p);
				
			p = strtok (NULL, "/");
			char contrasenya[20];
			strcpy (contrasenya, p);
				
			if (codigo == 1)
			{
				//int inicioSesion = iniciarSesion(usuario,contrasenya); // funcion que devuelve 1 se todo va bien 0 si hay error 2 si el usuario y la contraseña no coinciden
				int inicioSesion = 1;
				if (inicioSesion == 1) // El usuario y la contraaeña coinciden
					sprintf (respuesta, "BIEN");
					
				else if (inicioSesion == 0) // El usuario y la contraseña no coinciden
					sprintf(respuesta, "INCORRECTO");
				else if (inicioSesion == 2) // El usuario ya existe
					sprintf(respuesta, "EXISTE");
			}
			else if (codigo == 2)
			{
				//int registro = registrarse(usuario,contrasenya); // funcion que devuelve 1 se todo va bien 0 si hay error 2 si el usuario ya existe
				int registro = 1;
				if (registro == 1) // Se ha registrado
					sprintf (respuesta, "BIEN");
				
				else if (registro == 0) // ERROR
					sprintf(respuesta, "ERROR");
				else if (registro == 2) // El usuario ya existe
					sprintf(respuesta, "EXISTE");
			}
		}
			
			printf("%s",respuesta);
			write (sock_conn,respuesta, strlen(respuesta));
			
			// Se acabo el servicio para este cliente
			close(sock_conn); 
	}		
}
























