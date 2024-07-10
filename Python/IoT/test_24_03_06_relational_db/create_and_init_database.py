import sqlite3


DB_NAME = 'temp.db'


conn = sqlite3.connect(DB_NAME)

# Enable foreign keys
conn.execute("PRAGMA foreign_keys=\"ON\"")


conn.cursor().execute('''
    CREATE TABLE IF NOT EXISTS temperature_sensor (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        manufacturer TEXT NOT NULL,
        room TEXT NOT NULL
    )
''')


conn.cursor().execute('''
    CREATE TABLE IF NOT EXISTS temperature_entries (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        temperature_sensor_id INTEGER NOT NULL,
        timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
        FOREIGN KEY(temperature_sensor_id) REFERENCES temperature_sensor(id) ON DELETE CASCADE
    )
''')


conn.commit()
