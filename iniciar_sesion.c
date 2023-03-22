#include <mysql/mysql.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int iniciar_sesion(char* nombre, char* contrasena) { //La función "iniciar_sesion" toma dos parámetros: "nombre" y "contrasena" que son los datos de inicio de sesión del usuario que se van a verificar en la base de datos. Devuelve un valor entero que indica si el usuario existe en la base de datos o no.
		MYSQL* conexion;
		MYSQL_RES* resultado;
		MYSQL_ROW fila;
		int existe_usuario = 0;
		
		conexion = mysql_init(NULL); //Se inicializa la conexión a la base de datos utilizando la función "mysql_init". En caso de que la conexión no se pueda establecer, se imprime un mensaje de error y se termina el programa.
		if (mysql_real_connect(conexion, "localhost", "root", "mysql", "juego", 0, NULL, 0) == NULL) {
			fprintf(stderr, "%s\n", mysql_error(conexion));
			exit(1);
		}
		
		char consulta[1000];
		sprintf(consulta, "SELECT COUNT(*) FROM usuarios WHERE nombre='%s' AND contrasena='%s'", nombre, contrasena); //Esta línea construye una consulta SQL que cuenta el número de filas en la tabla usuarios que coinciden con el nombre y la contraseña proporcionados. La consulta utiliza la función sprintf para construir la consulta utilizando los valores de los parámetros nombre y contrasena.
		
		if (mysql_query(conexion, consulta)) { //Se ejecuta la consulta utilizando la función "mysql_query" y se verifica si hubo algún error en la ejecución de la consulta. Si hay un error, se imprime un mensaje de error y se termina el programa.
			fprintf(stderr, "%s\n", mysql_error(conexion));
			exit(1);
		}
		
		resultado = mysql_store_result(conexion); //Esta línea almacena los resultados de la consulta SQL en el objeto resultado.
		fila = mysql_fetch_row(resultado); //A continuación, se llama a la función mysql_fetch_row() para obtener la siguiente fila de resultados. Esta función devuelve un puntero a una estructura MYSQL_ROW que contiene los datos de una fila de resultados. Como la consulta devuelve una sola fila con un único valor (el número de usuarios con el nombre y contraseña proporcionados), no es necesario iterar sobre las filas de resultados.
		existe_usuario = atoi(fila[0]); //Entonces, como esta consulta devuelve una única fila y una única columna con el número de usuarios que cumplen la condición, se obtiene el valor de esta columna usando fila[0] y se convierte a un valor entero usando atoi(). Si el valor de existe_usuario es 0, significa que no existe un usuario con el nombre y contraseña proporcionados. Si el valor de existe_usuario es 1, significa que sí existe un usuario con el nombre y contraseña proporcionados. Este valor se devuelve al final de la función iniciar_sesion().
		
		mysql_free_result(resultado);
		mysql_close(conexion);
		
		return existe_usuario;
	}
}

