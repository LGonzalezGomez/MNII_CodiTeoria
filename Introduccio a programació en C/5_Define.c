#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
Un define sirve para que cuando el compilador "traduzca" vuestro código
a lenguaje del ordenador, cada vez que aparezca la la "N" se sustituirá
por el numero que pongáis despues.
La idea de usar un define es que podeis usarlo para crear vectores como
los declaramos abajo
*/
#define N 100 


int main(){ 
	int numero = 2; 
	
	int sumatorio[N]; // <---- 
	
	//al comenzar el sumatorio no tiene ningun valor
	sumatorio[0] = 0 + numero; //El primer elemento del vector es numero

	
	int i; //declaramos el indice del sumatorio
	for ( i = 1; i < N; i = i+1){ //<---- 
	
	
	sumatorio[i] = sumatorio[i-1] + numero;

	//En este caso estamos sustituyendo la componente "i" del vector por la suma de la componente anterior (suma acumulada hasta ese punto) mas el "numero".

	} //todo lo que hay entre corchetes, pertenece al bucle

	//Imprimamos de nuevo el resultado, sin embargo ahora podemos imprimir toda la progresion completa!
	printf("Indice \t Sumatorio \n"); //Podemos hacer un "encabezado" para ayudarnos a leer. Aqui hemos usado un par de cosas nuevas! "\t" es hacer un 	tabulado (equivale a unos cuantos espacios), mientras que "\n" indica que haga una nueva linea (que pulse enter, vamos).

	//Con estos nuevos comandos, ahora podemos imprimir linea a linea los resultados de la progresion! De nuevo, necesitaremos un bucle

	for ( i = 0; i < N; i = i+1){//<---- 

	printf("%d \t %d \n", i , sumatorio[i] );

	}

	//Esto tambien lo podemos guardar en un fichero, para poder ir a ver nuestro resultado cuando nos apetezca!

	FILE* fichero; //Definimos de esta forma que la variable "fichero" sera el documento que querramos guardar.
	fichero = fopen("Progresion_Aritmetica.txt", "w" ); //Abrimos un fichero llamado "Progresion_Aritmetica.txt" en el lugar donde se ejecuta este codigo. No useis espacios ni acentos ni cosas raras en los nombres, solo os dara problemas! Ademas de abrir el fichero, le tenemos que decir para que lo queremos abrir: escribir informacion ("w" de write), leerla ("r" de read), etc. No creo que necesiteis mas que esas dos en la mayoria de casos!

	//Ahora ya podemos imprimir en el fichero los datos que queriamos. Es muy parecido a imprimir por pantalla, solo que ahora ademas le especificamos en que fichero lo tiene que hacer!
	fprintf(fichero, "Indice \t Sumatorio \n");
	
	for ( i = 0; i < N; i = i+1){//<---- 

	fprintf(fichero, "%d \t %d \n", i , sumatorio[i] );

	}
	
	fclose(fichero); //Cerramos el fichero
	
	
	return 0;

}
