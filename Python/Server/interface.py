import sqlite3
import hashlib
from mutagen.mp3 import MP3

# User Data

conn_userdata = sqlite3.connect("userdata.db")
cur_userdata = conn_userdata.cursor()

cur_userdata.execute("""
CREATE TABLE IF NOT EXISTS userdata (
    id INTEGER PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL
)
""")

username1, password1 = "jojo", hashlib.sha256("1234".encode()).hexdigest()
cur_userdata.execute("INSERT INTO userdata (username, password) VALUES (?, ?)", (username1, password1))
conn_userdata.commit()

# MP3 File Data

conn_mp3 = sqlite3.connect('mp3_database.db')
c_mp3 = conn_mp3.cursor()

c_mp3.execute('''CREATE TABLE IF NOT EXISTS mp3_files (
                id INTEGER PRIMARY KEY,
                file_name TEXT,
                artist TEXT,
                title TEXT,
                album TEXT,
                genre TEXT,
                duration REAL,
                bitrate INTEGER,
                sample_rate INTEGER,
                file_size INTEGER,
                year INTEGER,
                track_number INTEGER,
                comment TEXT,
                lyrics TEXT,
                user_id INTEGER,
                FOREIGN KEY(user_id) REFERENCES userdata(id)
            )''')


def insert_mp3_data(file_name, artist, title, album, genre, duration, bitrate, sample_rate, file_size,
                    year, track_number, comment, lyrics, user_id):
    c_mp3.execute('''INSERT INTO mp3_files (file_name, artist, title, album, genre, duration, bitrate, sample_rate,
     file_size, year, track_number, comment, lyrics, user_id)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''', (file_name, artist, title, album, genre,
                                                                       duration, bitrate, sample_rate, file_size, year,
                                                                       track_number, comment, lyrics, user_id))
    conn_mp3.commit()


# Example usage: Importing data from an MP3 file and inserting into the database
file_path = 'path_to_your_mp3_file.mp3'

mp3 = MP3(file_path)
file_name = mp3.filename
artist = mp3['artist'][0] if 'artist' in mp3 else None
title = mp3['title'][0] if 'title' in mp3 else None
album = mp3['album'][0] if 'album' in mp3 else None
genre = mp3['genre'][0] if 'genre' in mp3 else None
duration = mp3.info.length
bitrate = mp3.info.bitrate / 1000 if mp3.info.bitrate else None
sample_rate = mp3.info.sample_rate if mp3.info.sample_rate else None
file_size = mp3.info.filesize
year = mp3['date'][0].year if 'date' in mp3 and mp3['date'][0].year else None
track_number = mp3['tracknumber'][0] if 'tracknumber' in mp3 else None
comment = mp3['comment'][0] if 'comment' in mp3 else None
lyrics = mp3['lyrics'][0] if 'lyrics' in mp3 else None
user_id = 1  # Assuming user ID 1 for demonstration purposes

insert_mp3_data(file_name, artist, title, album, genre, duration, bitrate, sample_rate, file_size,
                year, track_number, comment, lyrics, user_id)

conn_userdata.close()
conn_mp3.close()
