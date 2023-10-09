#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

//En este codigo volveremos a hacer el sumatorio, pero ahora guardandonos
// la progresion completa. Para ello utilizaremos un vector o array

int main(){ 
	
	int numero = 2; 
	int sumatorio[100]; //Declararemos otra variable que sera la suma acumulada de diversos numeros. En este caso es un vector con 100 componentes!
	
	//al comenzar el sumatorio no tiene ningun valor
	sumatorio[0] = 0 + numero; //El primer elemento del vector es numero

	
	int i; //declaramos el indice del sumatorio
	for ( i = 1; i < 100; i = i+1){ //empezamos en i = 1, 
	//ya que sumatorio[0] lo hemos hecho antes!
	
	//Para hacer el sumatorio, basta con sumar a la variable "sumatorio"
	// el "numero" y guardarlo en la suma acumulada "sumatorio". 
	//Sin embargo, ahora utilizaremos el valor anterior obtenido de la siguiente forma
	
	sumatorio[i] = sumatorio[i-1] + numero;

	//En este caso estamos sustituyendo la componente "i" del 
	//vector por la suma de la componente anterior 
	//(suma acumulada hasta ese punto) mas el "numero".

	} //todo lo que hay entre corchetes, pertenece al bucle

	//Imprimamos de nuevo el resultado, sin embargo ahora podemos
	// imprimir toda la progresion completa!
	printf("Indice \t Sumatorio \n"); 
	//Podemos hacer un "encabezado" para ayudarnos a leer. Aqui hemos usado un par de cosas nuevas!
	// "\t" es hacer un 	tabulado (equivale a unos cuantos espacios), mientras que "\n"
	// indica que haga una nueva linea (que pulse enter, vamos).

	//Con estos nuevos comandos, ahora podemos imprimir linea a linea los resultados
	// de la progresion! De nuevo, necesitaremos un bucle

	for ( i = 0; i < 100; i = i+1){

	printf("%d \t %d \n", i , sumatorio[i] ); //que pasa si no ponemos "[i]"? Pensadlo y probad!

	}



	return 0;

}
