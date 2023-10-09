#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//En este codigo veremos como se utilizan los condicionales

int main(){

	//También puede ser interesante el uso de condiciones 
	//para hacer un comando o no. Un ejemplo lo encontrareis
	// abajo:
	//jugaad con i y j. Mirad que pasa
	int i = 0;
	int j = 1;
	
	if (i == 0){ 
	//si se cumple lo que hay dentro de (), entonces
	// hace lo que esta entre {}
		printf("Se cumple primera condición. i = %d\n",i);
	}
	else if (j == 1){ 
	//si no se ha cumplido la expresión de arriba, 
	//mira esta condición. Si se ha cumplido, se la salta!
		printf("Se cumple segunda condición. i = %d \t j = %d\n",i, j);
	}
	else { //si no se cumplen ninguna de las anteriores condiciones
		printf("No se cumplen ninguna de las dos condiciones.\n");	
	}
	
	//También se pueden hacer diferencias, no igualdades
	// o concatenar más de una condición:
	int k = 2;
	
	/* 
	&& = AND, || = OR (en lógica). Esto se traduce en que
	 con && se han de cumplir las dos mientras que con 
	|| basta con una de ellas.
	También se pueden combinar ambas! Poned parentesis
	 si quereis una prioridad en concreto!
	Además, podemos hacer negaciones con ! (Not)
	*/
	if ( (i != 2) && (j != 2) && (k == 2) ){ 
		printf("Se cumple que los (i,j) sean distintos de 2 y k = 2\n");
	}
	
	
	return 0;
}
