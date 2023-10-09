#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define N 30000 //ser� el numero total de "timesteps"

/*Hay dos tipos de variables: globales (fuera del main) y locales 
(dentro de las funciones)
Las variables locales solo existen dentro de las funciones en las 
que son declaradas, mientras que las globales se comparten en todo 
el c�digo. Por eso tened cuidado, si en alg�n momento cambiais el 
valor de una variable global,cambiar� para todo el c�digo y pod�is
tener problemas.
*/

//As� se define un vector de N componentes. Una matrix NxN se 
//definiria asi X[N][N]
double Preses[N]; 
double Depredadors[N];


int main(){ 

	//declaramos dos doubles para el dt i k2
	//Fijaos que el tiempo total de la simulaci�n ser� por tanto 
	//dt * (N-1), ya que el primer elemento se usa para la 
	//condici�n inicial
	double dt = 0.001; 
	double k2 = 3.0;
	
	Preses[0] = 0.5; Depredadors[0] = 0.9; 
	//as� damos valor a la primera componente de los vectores, 
	//es decir la condici�n inicial a t = 0. 
	//Para acceder los �ndices van de 0 a (N-1)
	
	int i; //declaramos un entero para utilizar en el loop for
	
	//El loop lo usaremos para ver la din�mica de tiempo a cada 
	//instante de tiempo. Estamos integrando numericamente la EDO. 
	//Para ello previamente se ha discretizado usando diferencias finitas!
	for (i = 1; i < N; i = i+1){
		Preses[i] = Preses[i-1] + dt*Preses[i-1]* (1.0 - Depredadors[i-1]); 
		//Recomiendo que cuando opereis con decimales, 
		//cuando useis un numero como en este caso "(1.0 - Y[i-1])", us�is 
		//el 1.0, para que sepa que es un decimal. 
		//En ocasiones puede dar problemas (sobretodo si es en un cociente!)
Depredadors[i] = Depredadors[i-1] + dt*Depredadors[i-1]* (Preses[i-1] - k2);
	}
	
	/*Ahora que hemos calculada la evoluci�n de las poblaciones, 
	tenemos que extraer los datos para poder plotarlo. Aqu� lo m�s
	sencillo es sacar los datos en un txt y utilizar un programa externo
	para visualizarlos. Recomendamos el Gnuplot, pero podeis usar lo 
	que querais siempre y cuando los gr�ficos
	sigan los guidelines que os daremos */
	
	//con esta linea declaramos que hay un fichero al que nos referiremos 
	//como "output"
	FILE* output; 
	//Un fichero puede ser escrito o le�do y adem�s ha de tener un nombre.
	//Para abrir el fichero, usamos la siguiente linea
	//output ser� el fichero que abre fopen con el nombre "poblacions.dat"
	output = fopen("poblacions.txt", "w"); 
	//la siguiente instrucci�n le dice al ordenador que ha de hacer con el
	//fichero: "w"= write; "r" = read"
	
	fprintf(output, "t Preses Depredadors\n"); 
	/*esta funci�n imprimer en el fichero output lo que ponemos entre " " 
	despu�s de la coma 
	Es importante dar formato al texto, en este caso queremos tres columnas:
	tiempo, Preses, Depredadors.
	Por ello separamos con un espacio y hacemos una nueva lines \n. 
	En caso de que os guste m�s usar el tabulador en lugar de el
	espacio, podeis poner \t */
	
	//Ahora que hemos puesto un "header" o nombre a cada variable 
	//(lo recomendamos para saber que es cada columna)
	//imprimimos el t, Preses, Depredadors de cada iteraci�n en el fichero
	// para tener los datos
	for (i = 0; i < N; i++){ 
		fprintf(output, "%lf %lf %lf\n", i*dt, Preses[i], Depredadors[i]); 
	}
	
	/*
	Arriba podeis apreciar como en donde antes ten�amos texto ahora hemos
	pues %lf. El % le dice al ordenador que all� ir� el valor de una variable 
	sea del tipo que sea y lo que ponemos despu�s le dice que variable es:
	%d = int
	%c = char (letra)
	%s = cadena de caracteres o "string"
	%f = float (decimal)
	%lf = long float o double (doble precisi�n = m�s n�meros decimales)
	
	Una vez le decimos que ir�n variables, tenemos que decirles que 
	variable va en cada sitio. La forma de hacerlo 	es por orden de 
	izqda a derecha, separadas por comas tal y como pod�is apreciar arriba
	*/
	
	fclose(output); //finalmente cerramos el fichero

	
	
		
	return 0; 
}

