#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>


int main(){ 
	int numero = 2; 
	int sumatorio[100]; 
	
	//al comenzar el sumatorio no tiene ningun valor
	sumatorio[0] = 0 + numero; //El primer elemento del vector es numero

	
	int i; //declaramos el indice del sumatorio
	for ( i = 1; i < 100; i = i+1){ //empezamos en i = 1, ya que sumatorio[0] lo hemos hecho antes!
	
	sumatorio[i] = sumatorio[i-1] + numero;

	} 
	
	//Imprimamos de nuevo el resultado, sin embargo ahora podemos imprimir toda la progresion completa!
	printf("Indice \t Sumatorio \n"); 
	
	for ( i = 0; i < 100; i = i+1){

	printf("%d \t %d \n", i , sumatorio[i] ); 

	}

	//Esto tambien lo podemos guardar en un fichero, para poder
	// ir a ver nuestro resultado cuando nos apetezca!

	FILE* fichero; 
	//Definimos de esta forma que la variable "fichero" sera el 
	//documento que querramos guardar.
	fichero = fopen("Progresion_Aritmetica.txt", "w" ); 
	//Abrimos un fichero llamado "Progresion_Aritmetica.txt" en el
	// lugar donde se ejecuta este codigo. No useis espacios ni acentos
	// ni cosas raras en los nombres, solo os dara problemas! Ademas de abrir
	// el fichero, le tenemos que decir para que lo queremos abrir: escribir 
	//informacion ("w" de write), leerla ("r" de read), etc. No creo que 
	//necesiteis mas que esas dos en la mayoria de casos!

	//Ahora ya podemos imprimir en el fichero los datos que queriamos. 
	//Es muy parecido a imprimir por pantalla, solo que ahora ademas le
	// especificamos en que fichero lo tiene que hacer!
	fprintf(fichero, "Indice \t Sumatorio \n");
	
	for ( i = 0; i < 100; i = i+1){

	fprintf(fichero, "%d \t %d \n", i , sumatorio[i] );

	}
	
	fclose(fichero); //Cerramos el fichero
	
	
	return 0;

}
