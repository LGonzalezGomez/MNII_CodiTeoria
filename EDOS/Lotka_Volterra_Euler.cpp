/*
Codi per exemplificar pseudocodi de Lotka-Volterra en Euler


Les funcions seran:
# x' = x - x*y
# y' = x*y - k2*y
*/

//Incluim les llibreries necessaries. Nomes imprimim en fitxer
#include <stdio.h>

// Pas de temps i temps final (normalitzat)
#define dt 0.01
#define tmax 10.
#define N int(tmax/dt + 1) //Vigileu, hem de dividir nombres decimals i despres

// Definim les constants i els parametres
double x0 = 1.0;
double y0 = 0.5;
double k2 = 1.0;


// Vectors on guardarem les dades
double x[N];
double y[N];
double t[N];

int main(){
    printf("N = %d\n", N);

    // Condicions inicials
    t[0] = 0.;
    x[0] = x0;
    y[0] = y0;

    //Iterem en el temps
    int i;

    for (i = 1; i <= N; i = i+1){ //(1) Iterem en el temps

        // (2) Actualitzem emprant Euler
        x[i] = x[i-1] + dt*x[i-1] *(1.0 - y[i-1]);
        y[i] = y[i-1] + dt*y[i-1]*(x[i-1] - k2);
        t[i] = t[i-1] + dt;

        //Imprimim les dades
        printf("%f %f %f\n", t[i], x[i], y[i]);

    }

    //Cal extreure les dades i representar-les amb algun programa extern


    return 0;
}
