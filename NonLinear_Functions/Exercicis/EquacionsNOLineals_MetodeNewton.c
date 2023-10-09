////////////////////////////////////////////////////////////////
//                                                            //
//      Solucio d'equacions no lineals                        //
//		Programa intdoductori                                 //
//		Metodes Numerics II                                   //
//                                                            //
//		START: 30-abr-2017                                    //
//		ACTUAL VERSION (v200): 09-oct-2023                    //
//                                                            //
//		CARLES NAVAU/ LEO GONZALEZ                            //
//                                                            //
////////////////////////////////////////////////////////////////


// Reviseu la introducció a C abans d'intentar entendre aquest fitxer. Us sera molt mes sencill!

#include <string.h> //Llibreria per tractament de text en pantalla
#include <stdlib.h> //Llibreria per tractament de text en pantalla
#include <stdio.h>  //Llibreria amb funcions d'entrada/sortida
#include <math.h>   //Llibreria amb funcions matematiques basiques
#include <conio.h>  //Llibreria amb funcions d'entrada/sortida
 
#define PI 4.0*atan(1.0)  //Definicio de PI amb el maxim de presicio permesa per la maquina.
 

float f(float,float); //declaracio d'una funcio real (float) "f" de dos variables reals (float)
float fp(float,float);  //Aquesta sera la funcio derivada de l'anterior
//Volem trobar la solucio de la funcio f(x)-A=0.
	
int main(void)  //Inici de la part principal del programa (main). 
//No te variables d'entrada (void) i te una sortida entera (int)

{

	
	//Declaracio de variables a utilitzar. S'aprofita per fer tambe algunes definicions.
	float xmin,xmax; //Valors limits de la variable "x" que s'utilitzara per trobar la solucio 
	float x,xnew; //variables que necessitarem per trobar la solucio
	float step;
	float sol; //valor per guardar la solucio
	float A; //Parametre de l'equacio
	int ok; //variable que ens servira per saber si ja estem dins la precisio buscada
	int num; //variable per contar el numero d'iteracions fetes.
	char c; //ens servira per esperar que es toqui una tecla
	
	FILE *output; //Variable per determinar el fitxer on es guardaran les solucions
	
	//--------------------------------------------------------------
	//Entrada de valors i declaracio de variables numeriques necessaries
	//xmin=-100.0;
	//xmax=100.0;
	
	//INITIALIZATION VALUES
	output=fopen("solucio.dat","w+"); //S'obre un fitxer solucio.dat, sobreescribint-lo, si ja existeix ("w+")
	
	//-------------------------------------------------------------------
	//SCREEN INFORMATION
	printf("\nInici del programa, buscant entre xmin=%f i xmax=%f\n",xmin,xmax); //Imprimir en pantalla

	//--------------------------------------------------------------------
	//START MAIN PROGRAM
	printf("Starting...\n");
	 
	for (A=-100.0;A<100.0;A+=0.1) { //Volem trobar ara la solucio de x*x=A; o sigui l'arrel quadrada de A. 
	//A variara desde 0.0 fins a 10.0    
		x=1.0; //Comencem sempre a 1.0
		ok=0; // de moment, no hem arribat a la solucio
		num=0; // iniciem el numero d'iteracions a zero
		do { //inici del blucle; es repetira mentre es satifaci la condicio del "while"
		  xnew=x-(f(x,A)/fp(x,A)); //troba el nou valor de la serie, xnew: FORMULA DEL METODE DE NEWTON
		  //printf("%f %f\n",f(x,A),fp(x,A)); //control: imprimir en pantalla els valors de f(x) i f'(x)
		  //Es criden les funcions f() i fp() amb l'argument x i A.
		  num++; //incrementa en 1 el valor de la variable num
		  //printf("%f %i\n",xnew,num); //control: imprimir en pantalla en numero d'iteracio que s'esta fent
		  if (fabs((xnew-x))<0.00001) ok=1; //Si tenim la precisio buscada, ja hem arribat a la solucio
		  x=xnew;
		} while ((ok==0)&&(num<1000)); //condicio: o be ok==1, o be num>10000
		fprintf(output,"%f %f %i\n",A,xnew,num); //imprimir al fitxer output els valors A, xnew, num
		printf("%f %f %i\n",A,xnew,num); //El mateix, pero en pantalla.
	} //End of 'for'
	
		
		
	//--------------------------------------------------------------------
	//CLOSING
	
	fclose(output); //tanca el fitxer i, si hi ha informacio per gravar, la grava abans de tancar
	printf("\n\nThat's all, folks!");
	c=getch(); //Espera a primer una tecla per tancar
	
	return 0; //Retorna el valor '0'. Si s'ha arribat fins aqui indicaria que s'ha acabat sense errors.

} //final de la part 'main'

///////////////////////////////////////////////////////
// PROCEDURES AND FUNCTIONS              //////////////
///////////////////////////////////////////////////////

float f(float x1,float x2) {
  return x1*x1*x1-x2; //f(x)=x^3-A
}

float fp(float x1,float x2) {
  return 3.0*x1*x1;  //f'(x)=3 x^2
}


