import os
from flask import Flask, request, jsonify
import json
import matplotlib.pyplot as plt

app = Flask(__name__)

# Directory to store sensor data files
data_directory = 'sensor_data'

# Create the data directory if it doesn't exist
os.makedirs(data_directory, exist_ok=True)

# Define color codes for the air quality index
color_codes = {
    range(1, 50): 'green',
    range(51, 100): 'yellow',
    range(101, 150): 'orange',
    range(151, 200): 'red'
}

# Function to create a stem plot
def create_stem_plot(data, sensor_id):
    timestamps = [entry['timestamp'] for entry in data]
    aqi_values = [entry['value'] for entry in data]  # Assuming AQI values are in 'value' field
    colors = [color_codes[min(filter(lambda x: x >= entry['value'], color_codes))] for entry in data]

    plt.figure(figsize=(10, 6))
    plt.stem(timestamps, aqi_values, linefmt='-b', markerfmt='ob', basefmt=' ')
    plt.title(f'Air Quality Index for Sensor {sensor_id}')
    plt.xlabel('Timestamp')
    plt.ylabel('AQI')
    plt.xticks(rotation=45)
    plt.grid()
    plot_filename = f'aqi_plot_sensor_{sensor_id}.png'
    plt.savefig(os.path.join(data_directory, plot_filename))
    plt.close()

# Function to save data to the data file for the specified sensor
def save_data(data, sensor_id):
    data_file = os.path.join(data_directory, f'sensor_{sensor_id}_data.json')
    with open(data_file, 'r') as f:
        existing_data = json.load(f)
    existing_data.append(data)
    with open(data_file, 'w') as f:
        json.dump(existing_data, f)

@app.route('/')
def list_endpoints():
    # Return a list of available endpoints
    endpoints = {
        'GET /': 'List of all links that can be accessed within the application',
        'POST /data': 'Add data to the database',
        'GET /graph/<int:sensor_id>': 'Visualize air quality data in a graph for the specified sensor'
    }
    return jsonify(endpoints)

@app.route('/data', methods=['POST'])
def add_data():
    data = request.get_json()
    sensor_id = data['sensor_id']
    save_data(data, sensor_id)
    return jsonify({'message': 'Data added to the database'})

@app.route('/graph/<int:sensor_id>', methods=['GET'])
def visualize_graph(sensor_id):
    data_file = os.path.join(data_directory, f'sensor_{sensor_id}_data.json')
    if not os.path.exists(data_file):
        return jsonify({'message': f'No data for Sensor {sensor_id}'})
    with open(data_file, 'r') as f:
        data = json.load(f)
    create_stem_plot(data, sensor_id)
    return jsonify({'message': f'Air quality graph generated for Sensor {sensor_id}'})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
