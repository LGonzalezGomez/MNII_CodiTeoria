# %%
"""
In this file we will implement the animation of the Euler method.
"""
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


#Definitions that can be changed by user
#---------------------------------------
# Set initial values for the animation.
interval = (0, 2*np.pi)
x0 = 0.0
y0 = 0.0
h = 0.2

def y(x):
    """
    Analytic solution of the ODE
    """
    return np.sin(x)

def f(x,y):
    """
    Right hand side of the ODE
    y' = f(x,y)
    Make sure that this is consistent with y(x)
    """
    return np.cos(x)

#---------------------------------------


def Euler( x0, y0, h, f, interval, max_iterations=100, tolerance=1e-6):
    """
    This function implements the Euler method to solve the differential equation y'=f(x,y) with y(x0)=y0.

    Parameters
    ----------
    x0 : float
        Initial value of x.
    y0 : float
        Initial value of y.
    h : float
        Step size.
    f : function
        Function to be integrated.
    interval : tuple
        Interval of integration.
    max_iterations : int, optional  
        Maximum number of iterations. The default is 100.
    tolerance : float, optional
        Stop at this precision level before max_iterations. The default is 1e-6.  
    """
    x = x0
    y = y0
    x_values = [x]
    y_values = [y]
    slopes = []
    for _ in range(max_iterations):
        try: #check if it overflows (diverges)
            slope = f(x,y)
            x = x + h
            y = y + h*slope
        except:
            break
        
        if x >= interval[1]:
            break
        x_values.append(x)
        y_values.append(y)
        slopes.append(slope)
        
    return x_values, y_values, slopes


# Integrate via Euler the function f(x) with initial value x0.
x_values, y_values, slopes = Euler(x0, y0, h, f, interval)

# Create a figure and axis for the animation.
fig, ax = plt.subplots()

x_points = np.linspace(interval[0], interval[-1], 100)
y_points = [y(x) for x in x_points]

# Figure range:
largest_elem = max( max(y_points), max(y_values))
smallest_elem = min( min(y_points), min(y_values))

# Define the initialization function for the animation.
def init():
    ax.set_xlim(interval[0], interval[-1])
    ax.set_ylim(smallest_elem, largest_elem)
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_title('Mètode d\'Euler')
    ax.grid(True)  # Add a grid
    ax.plot(np.linspace(interval[0], interval[-1], 100), [y(x) for x in np.linspace(interval[0], interval[-1], 100)], linestyle='-', color='g', label='f(x)')
    return ax,

# Define the update function for the animation.

def update(frame):
    global smallest_elem, largest_elem, interval
    ax.clear()
    ax.set_xlim(interval[0], interval[-1])
    ax.set_ylim(smallest_elem, largest_elem)
    ax.plot(np.linspace(interval[0], interval[-1], 100), [y(x) for x in np.linspace(interval[0], interval[-1], 100)], linestyle='-', color='g', label='f(x)')
    if frame//2 > 0:
        ax.plot(x_values[:frame//2], y_values[:frame//2], marker='o', linestyle = "None", color='r', alpha = 0.5)
        ax.plot([(x_values[i] , x_values[i] + h) for i in range(frame//2)], [(y_values[i] , y_values[i]+ slopes[i]*h) for i in range(frame//2)], linestyle='--', color='blue', alpha = 0.5)

    ax.plot(x_values[frame//2], y_values[frame//2], marker='o', linestyle = "None", color='r')
    if frame%2 == 1:
        ax.plot([x_values[frame//2] , x_values[frame//2] + h], [y_values[frame//2] , y_values[frame//2]+ slopes[frame//2]*h], linestyle='--', color='blue')
    
    ax.set_title(f'Mètode d\'Euler')
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.legend(loc="upper right")
    ax.text(0.05, 0.05, 'Iteració {}'.format(frame//2), transform=ax.transAxes,color="black")

    return ax,

# %%
total_frames = (len(x_values))*2 - 1 #substract one as the last iteration does not have a slope
ani = animation.FuncAnimation(fig, update, frames=list( range(total_frames)), init_func=init, interval = 300)
ani.save('./Euler.gif', writer='ffmpeg', fps=3, dpi = 150)  # Change 'writer' to 'ffmpeg' for different formats (gif or mp4). 

# %%
# %%
