import json
import random
from time import time

from pymongo import MongoClient
from bson import json_util, ObjectId
from flask import Flask, request, jsonify

app = Flask(__name__)

DATABASE_NAME = "mongo_exam_database"
# Insert your MongoDB connection string here
CONNECTION_STRING = "mongodb+srv://Mlqko:kiselo@jojospace.vbz8hkx.mongodb.net/"


# Create a new air quality sensor
# Same as the exam
@app.route("/sensors", methods=["POST"])
def create_air_quality_sensor():
    data = request.get_json()
    air_quality_sensor_collection.insert_one(data)
    return jsonify(json.loads(json_util.dumps(data))), 201


# Create a new air quality sensor data entry
# Same as the exam
@app.route("/sensors/<sensor_id>/data", methods=["POST"])
def create_air_quality_sensor_data_entry(sensor_id):
    data = {
        "value": random.randint(0, 100),
        "timestamp": time(),
        "air_quality_sensor_id": ObjectId(sensor_id)
    }
    air_quality_sensor_data_collection.insert_one(data)
    return jsonify(json.loads(json_util.dumps(data))), 201


if __name__ == "__main__":
    mongo_client = MongoClient(CONNECTION_STRING)
    database = mongo_client.get_database(DATABASE_NAME)
    air_quality_sensor_collection = database.get_collection("air_quality_sensors")
    air_quality_sensor_data_collection = database.get_collection("air_quality_sensor_data")
    app.run(debug=True, port=8000)