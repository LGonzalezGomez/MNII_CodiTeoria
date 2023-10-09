/*
Esto que hemos hecho abajo consiste en declarar 
una funcion llamada "main" que devuelve un entero 
(int) al acabar de ejecutarse (con return 0)

Muy util para saber si el programa se ha ejecutado 
correctamente, ya que si al acabar nos devuelve un
0 por la consola, querra  decir que ha llegado 
hasta el final, otra cosa es que lo que hayais 
escrito haga lo que esperais que haga...

Es importante que en C, siempre declareis de que 
tipo es una variable/funcion. Si no ponemos el "int",
no va a funcionar en absoluto! Además, la función tiene que llamarse main
*/

//Para poder usar la función "printf" (entre otras), tenemos que 
//cargar dicha funcion. Para ello se utilizan los includes.
// Usad la lista de abajo, normalmente no necesitareis ningún otro!
#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main(){ 

	/*
	Ya hemos visto que la funcion "main" es de tipo entero. 
	Sin embargo hay otros tipos: int (entero), float (decimal),
	double (decimal doble precision), etc.
	*/

	int numero; //De esta forma se declara una VARIABLE que sera un entero
	
	/*Es importante que al acabar un comando de C, pongamos ";"
	para indicar que hemos acabado un comando y comenzamos 
	el siguiente. 
	Un cambio de linea, no significa que es otro comando,
	como si ocurre en Python.
	*/
	
	int suma; //Declararemos otra variable que sera la suma 
	//de dos enteros:
	
	numero = 1; //Asignamos un valor a la variable "numero"
	suma = numero + 2;

	//Ahora hemos hecho suma = 1 + 2 = 3, pero como podemos
	// saber si esto es cierto? Podemos pedirle que nos diga
	// el resultado por pantalla

printf("El resultado de hacer suma = %d + 2 es %d   ", numero, suma );

	/*
	La funcion printf de C, nos permite imprimir texto por 
	pantalla. La sintaxis es la siguiente: 
	
	printf( "Texto que se va  a imprimir", variables);
	
	Fijaos que ademas de texto, en nuestro caso hemos puesto
	 una cosa rara... "%d"
	Esto le dice al compilador que en esa posicion del texto
	 tenemos que sustituir lo que haya ahÃ­ por el valor de la 
	 primera variable que se encuentre 		despuÃ©s de la coma.
	  En este caso al usar "%d", le estamos diciendo que en esa
	   posicion ira un entero, por lo que si le pasamos otra cosa,
	    nos dara un 	error y el compilador nos lo va a decir.
	*/

//%f es si queremos decirle que es un float (numero decimal) y %lf para un double



	return 0;

}
