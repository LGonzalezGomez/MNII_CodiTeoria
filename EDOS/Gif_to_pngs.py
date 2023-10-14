# %%
"""
Convert gifs to PNGs to create GIFs in PDF (LaTeX)
"""
from PIL import Image
import os

# Specify the path to the input GIF and the output directory for frames
input_gif_path = 'Euler.gif'
output_directory = 'Euler_frames/'

# Create the output directory if it doesn't exist
os.makedirs(output_directory, exist_ok=True)

# Open the input GIF
input_gif = Image.open(input_gif_path)

# Iterate through each frame in the GIF
for frame_number in range(input_gif.n_frames):
    # Select the current frame
    input_gif.seek(frame_number)
    
    # Save the current frame as an individual image file
    output_frame_path = os.path.join(output_directory, f'frame_{frame_number}.png')
    input_gif.save(output_frame_path)

# Close the input GIF
input_gif.close()

# %%
