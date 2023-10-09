/*
Para poder usar la función "printf" (entre otras),
tenemos que cargar dicha funcion. Para ello se utilizan
los includes. Usad la lista de abajo,
normalmente no necesitareis ningún otro!
*/

#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

int main(){ 

	
	int numero = 2; 
	
	int sumatorio; //Declararemos otra variable que sera la suma
	// acumulada de diversos numeros
	
	//al comenzar el sumatorio no tiene ningun valor
	sumatorio = 0;

	//Supongamos que queremos tener 100 terminos en el sumatorio.
	
	//Para este tipo de casos es muy util utilizar un bucle o "loop"
	int i; //declaramos el indice del sumatorio
	for ( i = 0; i < 100; i = i+1){

	/*
	El loop funciona de la siguiente forma:
		- Coge el indice i y lo iguala a 0 (i = 0).
		- Hace todo lo que haya dentro del bucle.
		- Al acabar, hace el comando i = i+1
		- Comprueba si la condicion i < 100 se cumple
		- Si es cierta, vuelve a hacer el bucle, repitiendo los pasos
		 2-4, hasta que la condicion no sea cierta
		- Acaba el bucle
	*/

	
	//Para hacer el sumatorio, basta con sumar a la variable "sumatorio"
	// el "numero" y guardarlo en la suma acumulada "sumatorio"
	
	sumatorio = sumatorio + numero;

	//Fijaros que en general esto no es una ecuacion. Si fuese una 
	//ecuacion tendriamos un problema!
	//El igual lo que quiere decir es que estamos asignando a esa variable 
	//un valor, en este caso la suma de dos numeros enteros.



	} //todo lo que hay entre corchetes, pertenece al bucle

	//Imprimamos de nuevo el resultado

	printf("El resultado de hacer el sumatorio es %d", sumatorio );

	//Podriais decirme que vale el indice i, usado en el loop. Pensadlo y os ayudara a 
	//entender como funciona el bucle! Imprimid el valor por pantalla, a ver si teniais razon!



	return 0;

}
