import sqlite3
import hashlib
import socket
import threading
from tkinter import *  # добавяме всичко от този модул
from tkinter import filedialog  # използваме го, за да не трябва сами да инициялизираме диалога между файлове
from pygame import mixer  # използваме този модул, за да зареждаме и пускане на файлове
import unittest


def is_valid_music_file(filename):
    return filename.endswith(".mp3")  # проверяваме формата на файла


class Tests(unittest.TestCase):
    def test_is_valid_music_file(self):
        self.assertEqual(is_valid_music_file("music.mp3"), True)
        self.assertEqual(is_valid_music_file("pic.jpeg"), False)


class MyException(Exception):
    pass


class MusicPlayer:
    def __init__(self, window):
        window.geometry('320x100')
        window.title('JOJOFY')
        window.resizable(0, 0)  # визулиазираме плейъра
        load = Button(window, text='Load', width=10, font=('Times', 10), command=self.load)  # визулиазираме бутоните
        play = Button(window, text='Play', width=10, font=('Times', 10), command=self.play)
        pause = Button(window, text='Pause', width=10, font=('Times', 10), command=self.pause)
        stop = Button(window, text='Stop', width=10, font=('Times', 10), command=self.stop)
        load.place(x=0, y=20)  # позиционираме бутоните
        play.place(x=110, y=20)
        pause.place(x=220, y=20)
        stop.place(x=110, y=60)
        self.music_file = False  # задаваме при стартиране на програмата мястото ни песен да е 0,
        # за да можем после при вече подаден файл да изциклим през функцията си
        self.playing_state = False  # задаваме да е 0

    def load(self):
        self.music_file = filedialog.askopenfilename()  # създаваме метод, с който можем директно да подадем файл
        if not is_valid_music_file(self.music_file):
            raise MyException("This isn't a compatible format")

    def play(self):

        if self.music_file:  # влизаме в цикъла само ако е различно от 0
            mixer.init()   # извикваме си миксера
            mixer.music.load(self.music_file)   # зареждаме подаденият по-горе файл
            mixer.music.play()   # пускаме файлът

    def pause(self):
        if not self.playing_state:  # само когато енумерацията е 0-лева ще имаме опцията да паузираме файлът
            mixer.music.pause()  # паузираме файлът
            self.playing_state = True
        else:  # само когато енумерацията е различна от 0-лева ще имаме опцията да пуснем файлът, откъдето е спрян
            mixer.music.unpause()  # отпаузираме файлa
            self.playing_state = False

    def stop(self):
        mixer.music.stop()   # спираме файлa


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
        root = Tk()  # създава се екран, на когото се визулиазира нашата програма
        app = MusicPlayer(root)  # програмата ни е MusicPlayer, която ще се осъществи на горе създаденият екран
        root.mainloop()  # екрана на програмата се задържа отворен

    else:
        c.send("Login failed!".encode())


while True:
    client, addr = server.accept()
    threading.Thread(target=handle_connection, args=(client,)).start()
