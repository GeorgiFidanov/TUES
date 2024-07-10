import threading
import requests
import json
import time
import random
import datetime

# Define the number of sensors to simulate (minimum: 3)
num_sensors = 3

# URL of the Flask app in Container No1
flask_app_url = "http://container1:5000"

# Function to simulate data sending for a sensor
def send_data(sensor_id):
    while True:
        try:
            data = {
                "value": random.randint(10, 200),
                "timestamp": str(datetime.datetime.now()),
                "sensor_id": f"aqi_sensor_{sensor_id}"
            }
            send_data_to_flask_app(data)
            time.sleep(20) 
        except Exception as e:
            print(f"An error occurred while sending data: {str(e)}")
            time.sleep(20)  

# Function to send data to the Flask app
def send_data_to_flask_app(data):
    try:
        response = requests.post(f"{flask_app_url}/data", json=data)
        response.raise_for_status()  # Raise an exception for unsuccessful responses
        print(f"Data sent to Flask app successfully: {json.dumps(data)}")
    except requests.exceptions.RequestException as e:
        print(f"Failed to send data to Flask app: {str(e)}")

# Create and start threads for each sensor
threads = []
for i in range(num_sensors):
    thread = threading.Thread(target=send_data, args=(i + 1,))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish (in this example, they run indefinitely)
for thread in threads:
    thread.join()
