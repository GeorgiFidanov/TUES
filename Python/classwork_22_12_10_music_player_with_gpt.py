
import tkinter as tk
from tkinter import filedialog
import pygame
from mutagen.mp3 import MP3

# Initialize tkinter, pygame, and the mixer
root = tk.Tk()
pygame.init()
pygame.mixer.init()


# Function for selecting a song
def select_song():
    # Use the filedialog to let the user select a song
    file = filedialog.askopenfilename(filetypes=[("MP3 files", "*.mp3")])

    # Load the audio file
    pygame.mixer.music.load(file)

    # Get the metadata for the song
    audio = MP3(file)

    # Update the song label
    song_label.config(text=audio.tags["artist"] + " - " + audio.tags["title"])


# Function for playing/pausing the song
def play_song():
    if pygame.mixer.music.get_busy():
        # If the song is already playing, pause it
        pygame.mixer.music.pause()
        play_button.config(text="Play")
    else:
        # If the song is not playing, start it
        pygame.mixer.music.play()
        play_button.config(text="Pause")


# Function for stopping the song
def stop_song():
    pygame.mixer.music.stop()
    play_button.config(text="Play")


# Create a button for selecting a song
select_button = tk.Button(root, text="Select Song", command=select_song)
select_button.pack()

# Create a label for displaying the currently playing song
song_label = tk.Label(root, text="No song selected")
song_label.pack()

# Create a play/pause button
play_button = tk.Button(root, text="Play", command=play_song)
play_button.pack()

# Create a stop button
stop_button = tk.Button(root, text="Stop", command=stop_song)
stop_button.pack()

# Start the GUI event loop
root.mainloop()
