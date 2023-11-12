"""
Codi per exemplificar pseudocodi de Lotka-Volterra amb el mètode d'Euler


Les funcions seran:
# x' = x - x*y
# y' = x*y - k2*y
"""

# Condicions inicials i paràmetres
x0 = 1
y0 = 0.2
k2 = 1

# Pas de temps i temps final
dt = 0.01
tmax = 10

N = int(tmax/dt + 1) # Numero de passos de temps. Noteu que (N-1)*dt = tmax
# Solucionem temps a temps
t = [0]
x = [x0]
y = [y0]

for i in range(1, N): # (1) Iterem sobre el temps. El primer valor es la condicio inicial

    # (2) Calculem primer els K1 de totes les variables   
    x_new = x[i-1] + dt*x[i-1]*(1-y[i-1])
    y_new = y[i-1] + dt*y[i-1]*(x[i-1] - k2)

    #Afegim els valors a les llistes
    x.append(x_new)
    y.append(y_new)
    t.append(t[i-1] + dt)

# Cal extreure les dades, guardar-les en un fitxer i fer els grafic adients
