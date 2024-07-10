from database import DB
from temperature_sensor import TemperatureSensor
from temperature_entries import TemperatureEntries

def main():
    # Create thermometers
    thermometer1 = TemperatureSensor(None, "Emerson", "Garage")
    thermometer1.create()
    print(f"Thermometer 1 created with ID: {thermometer1.id}")

    thermometer2 = TemperatureSensor(None, "Spluss", "Bathroom")
    thermometer2.create()
    print(f"Thermometer 2 created with ID: {thermometer2.id}")

    # Create temperature entries
    temp_entry1 = TemperatureEntries(None, thermometer1.id, None)
    temp_entry1.create()
    print(f"Temperature reading 1 created with ID: {temp_entry1.id}")

    temp_entry2 = TemperatureEntries(None, thermometer2.id, None)
    temp_entry2.create()
    print(f"Temperature reading 2 created with ID: {temp_entry2.id}")

    # Read and verify data
    with DB() as db:
        cursor = db.execute('''
            SELECT * FROM temperature_sensor WHERE manufacturer = ?
        ''', ("Emerson",))
        emerson_thermometers = cursor.fetchall()
        print(f"Emerson thermometers: {emerson_thermometers}")

        cursor = db.execute('''
            SELECT * FROM temperature_entries WHERE temperature_sensor_id = ?
        ''', (thermometer1.id,))
        emerson_temp_entries = cursor.fetchall()
        print(f"Temperature entries for Emerson thermometers: {emerson_temp_entries}")

    # Update a thermometer
    thermometer1.manufacturer = "Emerson Plus"
    thermometer1.update()
    print("Thermometer 1 updated to Emerson Plus")

    # Delete a temperature entry
    temp_entry1.delete()
    print("Temperature reading 1 deleted")

if __name__ == "__main__":
    main()
