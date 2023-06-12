import sqlite3
import hashlib
import socket
import threading
from tkinter import *
from tkinter import filedialog
from pygame import mixer
import unittest


def is_valid_music_file(filename):
    if filename.endswith(".mp3"):
        return filename.endswith(".mp3")
    elif filename.endswith(".wav"):
        return filename.endswith(".wav")


class Tests(unittest.TestCase):
    def test_is_valid_music_file(self):
        self.assertEqual(is_valid_music_file("music.mp3"), True)
        self.assertEqual(is_valid_music_file("pic.jpeg"), False)


class MyException(Exception):
    pass


class MusicPlayer:
    def __init__(self, window):
        window.geometry('280x100')
        window.title('JOJOFY')
        window.resizable(0, 0)
        load = Button(window, text='Load', width=10, font=('Times', 10), command=self.load)
        play = Button(window, text='Play', width=10, font=('Times', 10), command=self.play)
        pause = Button(window, text='Pause', width=10, font=('Times', 10), command=self.pause)
        prev_song = Button(window, text='Prev', width=10, font=('Times', 10), command=self.prev_song)
        next_song = Button(window, text='Next', width=10, font=('Times', 10), command=self.next_song)
        load.place(x=50, y=20)
        play.place(x=150, y=20)
        pause.place(x=100, y=60)
        next_song.place(x=190, y=60)
        prev_song.place(x=10, y=60)
        self.music_file = False
        self.playing_state = False
        self.queue_list = []
        self.current_song = 0

    def load(self):
        self.music_file = filedialog.askopenfilename()
        self.queue_list.append(self.music_file)
        print(self.queue_list)
        if not is_valid_music_file(self.music_file):
            raise MyException("This isn't a compatible format")

    def next_song(self):
        self.current_song += 1

        if self.current_song >= len(self.queue_list):
           self.current_song -= 1
           raise MyException("No songs there")

        self.music_file = self.queue_list[self.current_song]
        print("Now playing:", self.music_file)
        mixer.music.load(self.music_file)
        mixer.music.play()

    def prev_song(self):
        self.current_song -= 1

        if self.current_song < 0:
            self.current_song += 1
            raise MyException("No songs there")

        self.music_file = self.queue_list[self.current_song]
        print("Now playing:", self.music_file)
        mixer.music.load(self.music_file)
        mixer.music.play()

    def on_song_end(self):
        if self.music_file.bit_length() > 0:
            MusicPlayer.next_song(self)

    def play(self):
        if self.music_file:
            mixer.init()
            mixer.music.load(self.music_file)
            mixer.music.play()
            self.playing_state = True
            # self.on_song_end()
            if mixer.stop():
                self.playing_state = False
            #    self.on_song_end()

        elif self.queue_list:
            self.music_file = self.queue_list[self.current_song]

            if not mixer.init():
                mixer.init()

            mixer.music.load(self.music_file)
            mixer.music.play()
            self.playing_state = True
            self.current_song += 1
            print("curr song num:", self.current_song)
            # self.on_song_end()

    def pause(self):
        if not self.playing_state:
            mixer.music.pause()
            self.playing_state = True
        elif self.playing_state:
            mixer.music.unpause()
            self.playing_state = False


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("localhost", 9999))

server.listen()


def handle_connection(c):
    c.send("Username: ".encode())
    username = c.recv(1024).decode()
    c.send("Password: ".encode())
    password = c.recv(1024)
    password = hashlib.sha256(password).hexdigest()

    conn = sqlite3.connect("userdata.db")
    cur = conn.cursor()

    cur.execute("SELECT * FROM userdata WHERE username = ? AND password = ?", (username, password))

    if cur.fetchall():
        c.send("Login successful!".encode())
        root = Tk()
        MusicPlayer(root)
        root.mainloop()

    else:
        c.send("Login failed!".encode())


while True:
    client, addr = server.accept()
    threading.Thread(target=handle_connection, args=(client,)).start()
