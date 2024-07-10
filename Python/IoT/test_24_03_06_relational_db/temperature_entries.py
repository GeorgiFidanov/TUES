from database import DB


class TemperatureEntries:
    def __init__(self, id, temperature_sensor_id, timestamp):
        self.id = id
        self.temperature_sensor_id = temperature_sensor_id
        self.timestamp = timestamp

    def create(self):
        with DB() as db:
            row = db.execute('''
                INSERT INTO temperature_entries (temperature_sensor_id) VALUES (?) RETURNING id, timestamp
            ''', (self.temperature_sensor_id, )).fetchone()

            if row:
                self.id, self.timestamp = row

    def delete(self):
        if not self.id:
            return
        with DB() as db:
            db.execute('''
                DELETE FROM temperature_entries WHERE id = ?
            ''', (self.id, ))
