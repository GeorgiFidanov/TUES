import sqlite3

DB_NAME = "temp.db"

class DB:
    def __enter__(self):
        self.conn = sqlite3.connect(DB_NAME)
        self.conn.execute("PRAGMA foreign_keys = \"ON\"")
        return self.conn.cursor()

    def __exit__(self, type, value, traceback):
        self.conn.commit()
