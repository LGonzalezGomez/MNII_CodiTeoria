# %%
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


# Set initial values for the animation.
interval = (0, 2*np.pi)
x0 = 1.0

# Define the function for which you want to find a fixed point.
def f(x):
    return np.sin(x) + x

# Define the function representing the iterative process.
def banach(x0, max_iterations=50, tolerance=1e-6):
    x = x0
    iterations = 0
    x_values = [x]
    for _ in range(max_iterations):
        try: #check if it overflows (diverges)
            x_next = f(x)
        except:
            break

        x_values.append(x_next)
        if abs(x_next - x) < tolerance:
            break
        x = x_next
    return x_values


x_values = banach(x0)
iterations = len(x_values)
# Create a figure and axis for the animation.
fig, ax = plt.subplots()

# Define the initialization function for the animation.
def init():
    ax.set_xlim(interval[0], interval[-1])
    ax.set_ylim( f(interval[0]), f(interval[-1]))
    ax.set_xlabel('x')
    ax.set_ylabel('g(x)')
    ax.set_title('Mètode del Punt Fix')
    ax.grid(True)  # Add a grid
    ax.plot(np.linspace(interval[0], interval[-1], 100), [f(x) for x in np.linspace(interval[0], interval[-1], 100)], linestyle='-', color='g', label='g(x)')
    ax.plot(np.linspace(interval[0], interval[-1], 100), [x for x in np.linspace(interval[0], interval[-1], 100)], linestyle='--', color='gray', label='x')
    return ax,

# Define the update function for the animation.
amount_vertical = -1
amount_points = -1
amount_horizontal = -1
def update(frame):
    global amount_vertical, amount_points, amount_horizontal
    ax.clear()
    pre_valy_v = 0 #vertical lines

    if frame%3 == 0:
        amount_vertical += 1
    if frame%3 == 1: #add point
        amount_points += 1
    if frame%3 == 2: #add point
        amount_horizontal += 1

    if frame//3 > 0: #past things, if not in first iteration
            
        if amount_points >= 1:
            for x_val in x_values[:amount_points]:
                y_val = f(x_val)
                ax.plot(x_val, y_val , marker='o', linestyle='-', color='r', alpha= 0.5)
        

        if amount_vertical >= 1: 
            for value in x_values[:amount_vertical]: #do not consider first point
                ax.plot([value, value], [pre_valy_v, f(value)], linestyle='--', color='blue', alpha = 0.5) #vertical line
                pre_valy_v = f(value)
        
        if amount_horizontal >= 1:
            for value in x_values[:amount_horizontal]: #do not consider first point
                yval= f(value)
                ax.plot([value, yval], [yval, yval], linestyle='--', color='blue', alpha = 0.5) #vertical line
    
    if amount_vertical >= 0:
        xval = x_values[amount_vertical]
        yval = f(xval)
        ax.plot([xval, xval], [pre_valy_v, yval], linestyle='--', color='blue') #vertical line
    if amount_points >= 0:
        xval = x_values[amount_points]
        yval = f(xval)
        ax.plot(xval, yval, marker='o', linestyle='-', color='r', label='Iteracions')
    if amount_horizontal >= 0:
        xval = x_values[amount_horizontal]
        yval = f(xval)
        ax.plot([xval, yval], [yval, yval], linestyle='--', color='blue') #vertical line

    ax.plot(np.linspace(interval[0], interval[-1], 100), [f(x) for x in np.linspace(interval[0], interval[-1], 100)], linestyle='-', color='g', label='g(x)')
    ax.plot(np.linspace(interval[0], interval[-1], 100), [x for x in np.linspace(interval[0], interval[-1], 100)], linestyle='-', color='gray', label='x')
    ax.set_xlabel('x')
    ax.set_ylabel('g(x)')
    ax.set_title('Mètode del Punt Fix')
    ax.text(0.1, 0.85, 'Iteració {}'.format(frame//3), transform=ax.transAxes,color="black")
    ax.legend(loc="lower right")
    ax.grid(True)  # Add a grid
    return ax,

#%% Create the animation.
ani = animation.FuncAnimation(fig, update, frames=list( range(iterations*3)), init_func=init, interval = 300)

# Display the animation (this may not work in all Python environments).
ani.save('./banach.gif', writer='ffmpeg', fps=1, dpi = 150)  # Change 'writer' to 'ffmpeg' for different formats (gif or mp4). 
                                                            #It must be installed on PC, if not it resort to pillow (only GIF)
# plt.show()

# %%
