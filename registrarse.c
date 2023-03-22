#include <stdio.h>
#include <mysql.h>

int main(int argc, char *argv[])
{	
	int registrarse(char* usuario, char* contrasena)
		{
			MYSQL* conexion = mysql_init(NULL); // inicializar objeto de conexi�n a MySQL
			int resultado = 0; // variable para almacenar el resultado de la operaci�n
			
			if (conexion == NULL) // comprobar si la inicializaci�n de la conexi�n fue exitosa
			{
				printf("Error al inicializar la conexi�n a MySQL: %s\n", mysql_error(conexion));
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			// conectar a la base de datos
			if (mysql_real_connect(conexion, "localhost", "root", "mysql", "juego", 0, NULL, 0) == NULL)
			{
				printf("Error al conectar a la base de datos: %s\n", mysql_error(conexion));
				mysql_close(conexion);
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			// crear consulta SQL para comprobar si el usuario ya existe en la base de datos
			char consulta1[200];
			sprintf(consulta1, "SELECT COUNT(*) FROM JUGADOR WHERE USERNAME='%s'", usuario);
			
			// ejecutar la consulta1: Luego se ejecuta la consulta utilizando la función mysql_query, y si ocurre algún error en la ejecución, se muestra un mensaje de error, se libera la memoria utilizada y se devuelve el valor predeterminado de la variable resultado, que es 0.
			if (mysql_query(conexion, consulta1))
			{
				printf("Error al ejecutar la consulta1: %s\n", mysql_error(conexion));
				mysql_close(conexion);
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			// obtener los resultados de la consulta1: Si la consulta se ejecuta correctamente, se obtienen los resultados utilizando la función mysql_use_result, que devuelve un puntero a una estructura MYSQL_RES que contiene los resultados de la consulta. Si ocurre algún error al obtener los resultados, se muestra un mensaje de error, se libera la memoria utilizada y se devuelve el valor predeterminado de la variable resultado.
			MYSQL_RES* resultados1 = mysql_use_result(conexion);
			if (resultados1 == NULL)
			{
				printf("Error al obtener los resultados de la consulta1: %s\n", mysql_error(conexion));
				mysql_close(conexion);
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			// leer el valor de la columna COUNT(*) del primer registro de la tabla de resultados
			MYSQL_ROW fila1 = mysql_fetch_row(resultados1); //La línea MYSQL_ROW fila1 = mysql_fetch_row(resultados1); es la que lee la primera fila de resultados de la consulta que se ejecutó previamente. Esta fila contiene un conjunto de valores de la tabla que se corresponden con la consulta realizada.La función mysql_fetch_row devuelve un puntero a un array de cadenas que representan los valores de la fila actual. Cada elemento del array representa un campo de la tabla y el orden de los elementos corresponde al orden de los campos en la tabla.
			if (fila1 == NULL)
			{
				printf("Error al leer los resultados de la consulta1: %s\n", mysql_error(conexion));
				mysql_free_result(resultados1);
				mysql_close(conexion);
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			int num_filas1 = mysql_num_rows(resultados1);
			int num_campos1 = mysql_num_fields(resultados1);
			int valor1 = atoi(fila1[0]); // A continuación, se convierte el valor obtenido de la columna COUNT(*) a un entero utilizando la función atoi. Si el valor obtenido es mayor que cero, entonces el usuario ya existe en la base de datos, se muestra un mensaje indicando que el usuario ya existe, se libera la memoria utilizada y se devuelve el valor predeterminado de la variable resultado.
			
			// comprobar si el usuario ya existe en la base de datos
			if (valor1 > 0) 
			{
				printf("El usuario ya existe en la base de datos\n");
				mysql_free_result(resultados1);
				mysql_close(conexion);
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			// crear consulta SQL para insertar el nuevo usuario y la contrase�a en la base de datos
			char consulta2[200];
			sprintf(consulta2, "INSERT INTO usuarios (nombre, contrasena) VALUES ('%s', '%s')", usuario, contrasena);
			
			// ejecutar la consulta2
			if (mysql_query(conexion, consulta2))
			{
				printf("Error al ejecutar la consulta2: %s\n", mysql_error(conexion));
				mysql_free_result(resultados1);
				mysql_close(conexion);
				return resultado; // devolver valor predeterminado de resultado (0)
			}
			
			// En el c�digo que mostraste, no hay un else despu�s del if porque no es necesario en este caso. Si la funci�n mysql_query() devuelve un valor diferente de 0, se asume que hubo un error al ejecutar la consulta, por lo que el c�digo dentro del if se ejecuta y devuelve el valor predeterminado de resultado (0).
			// Si la funci�n mysql_query() devuelve un valor igual a 0, se asume que la consulta se ejecut� correctamente, por lo que el c�digo dentro del if no se ejecuta y se contin�a con el resto del c�digo. En este caso, no es necesario un else porque no hay ninguna acci�n adicional que realizar si la consulta se ejecuta correctamente.
			
			resultado = 1; // asignar 1 a la variable resultado para indicar que el registro se realiz� correctamente
			
			mysql_free_result(resultados1); // liberar la memoria de los resultados de la consulta1
			mysql_close(conexion); // cerrar la conexi�n a la base de datos
			
			return resultado; // devolver el valor de la variable resultado (1 si el registro se realiz� correctamente, 0 si hubo alg�n error)
		}
}
