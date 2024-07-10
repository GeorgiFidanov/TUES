from database import DB


class TemperatureSensor():
    
    def __init__(self, id, manufacturer, room):
        self.id = id
        self.manufacturer = manufacturer
        self.room = room

    def create(self):
        with DB() as db:
            row = db.execute('''
                INSERT INTO temperature_sensor (manufacturer, room) VALUES (?, ?) RETURNING id
            ''', (self.manufacturer, self.room)).fetchone()
            if row:
                (self.id, ) = row
            
    def update(self):
        if not self.id:
            return
        with DB() as db:
            db.execute('''
                UPDATE temperature_sensor SET manufacturer = ?, room = ? WHERE id = ?
            ''', (self.manufacturer, self.room, self.id))

    def delete(self):
        if not self.id:
            return
        with DB() as db:
            db.execute('''
                DELETE FROM temperature_sensor WHERE id = ?
            ''', (self.id, ))

    # Method to return the average temperature reading for a given room
    def average_temperature_in_room(self, room):
        with DB() as db:
            row = db.execute('''
                SELECT AVG(temperature) FROM temperature_sensor WHERE room = ?
            ''', (room, )).fetchone()
            if row:
                return row[0]
            else:
                return None

    # Method to return the minimum temperature reading for a given thermometer ID
    def min_temperature_for_temperature_sensor(self, temperature_sensor_id):
        with DB() as db:
            row = db.execute('''
                SELECT MIN(temperature) FROM temperature_sensor WHERE id = ?
            ''', (temperature_sensor_id, )).fetchone()
            if row:
                return row[0]
            else:
                return None

    # Method to return the number of temperature sensors from a given manufacturer
    def count_thermometers_by_manufacturer(self, manufacturer):
        with DB() as db:
            row = db.execute('''
                SELECT COUNT(*) FROM temperature_sensor WHERE manufacturer = ?
            ''', (manufacturer, )).fetchone()
            if row:
                return row[0]
            else:
                return None
            
