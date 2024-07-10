import json
from flask import Flask, request, jsonify

from time import time
from bson import json_util
from bson.objectid import ObjectId
from pymongo import MongoClient

app = Flask(__name__)

DATABASE_NAME = "mongo_exam_database"

# ------------------------------------------------------------------------------------------------
# Заменете с вашия connection string
CONNECTION_STRING = ''


# Да се създаде нов сензор в колекцията за сензори на вашата база от данни.
# Заявката приема JSON тяло с информация за сензора.
# Заявката връща новосъздадения сензор.
@app.route("/sensors", methods=["POST"])
def create_air_quality_sensor():
    sensor_data = request.get_json()
    result = air_quality_sensor_collection.insert_one(sensor_data)
    return jsonify({"sensor_id": str(result.inserted_id)}), 201


# Да се промени информацията за даден сензор.
# Заявката приема JSON тяло с нова информация за сензора.
# Заявката връща променения сензор.
@app.route("/sensors/<sensor_id>", methods=["PUT"])
def update_air_quality_sensor(sensor_id):
    sensor_data = request.get_json()
    result = air_quality_sensor_collection.update_one({"_id": ObjectId(sensor_id)}, {"$set": sensor_data})
    if result.modified_count == 1:
        return jsonify({"success": True}), 200
    else:
        return jsonify({"success": False}), 404


# Да се изтрие информацията за даден сензор.
# Заявката не приема тяло.
# Заявката връща информация дали изтриването е било успешно.
@app.route("/sensors/<sensor_id>", methods=["DELETE"])
def delete_sensor(sensor_id):
    result = air_quality_sensor_collection.delete_one({"_id": ObjectId(sensor_id)})
    if result.deleted_count == 1:
        return jsonify({"success": True}), 200
    else:
        return jsonify({"success": False}), 404


# Да се добави информация за получени данни от съответен сензор.
# Заявката приема JSON тяло.
# Заявката връща новосъздадения запис.
@app.route("/sensors/<sensor_id>/data", methods=["POST"])
def create_air_quality_sensor_data_entry(sensor_id):
    sensor_data = request.get_json()
    sensor_data["sensor_id"] = ObjectId(sensor_id)
    result = air_quality_sensor_data_collection.insert_one(sensor_data)
    return jsonify({"data_id": str(result.inserted_id)}), 201


# Да се изтрие записана информация за получени данни.
# Заявката не приема тяло.
# Заявката връща информация дали изтриването е било успешно
@app.route("/sensors/<sensor_id>/data/<data_id>", methods=["DELETE"])
def delete_air_quality_sensor_data_entry(sensor_id, data_id):
    result = air_quality_sensor_data_collection.delete_one({"_id": ObjectId(data_id), "sensor_id": ObjectId(sensor_id)})
    if result.deleted_count == 1:
        return jsonify({"success": True}), 200
    else:
        return jsonify({"success": False}), 404


# Да се изтрие записана информация за получени данни.
# Заявката не приема тяло.
# Заявката връща информация дали изтриването е било успешно
@app.route("/sensors/<sensor_id>", methods=["GET"])
def get_air_quality_sensor_by_id(sensor_id):
    sensor = air_quality_sensor_collection.find_one({"_id": ObjectId(sensor_id)})
    if sensor:
        return jsonify(sensor), 200
    else:
        return jsonify({"error": "Sensor not found"}), 404


# Да се върнат всички сензори от даден тип сортирани по град в низходящ ред.
# Заявката не приема тяло.
# Заявката връща списък с правилно подредени сензори.
@app.route("/sensors/type/<type>", methods=["GET"])
def get_air_quality_sensor_by_type_sorted_by_city_descending(type):
    sensors = list(air_quality_sensor_collection.find({"type": type}).sort("city", -1))
    for sensor in sensors:
        sensor["_id"] = str(sensor["_id"])
    return jsonify(sensors), 200



# Да се върне средно аритметично на всички стойности, отчетени от даден сензор.
# Заявката не приема тяло.
# Заявката връща средноаритметичната стойност за дадения сензор.
@app.route("/sensors/<sensor_id>/average", methods=["GET"])
def get_average_air_quality_by_sensor(sensor_id):
    # Use the aggregation framework to calculate the average air quality for the given sensor ID
    pipeline = [
        {"$match": {"sensor_id": ObjectId(sensor_id)}},
        {"$group": {"_id": "$sensor_id", "average": {"$avg": "$air_quality"}}}
    ]
    result = list(air_quality_sensor_data_collection.aggregate(pipeline))
    if result:
        # Convert ObjectId to string for JSON serialization
        result[0]["_id"] = str(result[0]["_id"])
        return jsonify(result[0]), 200
    else:
        return jsonify({"error": "No data found for this sensor"}), 404


# Да се върнат всички отчетени стойности над посочената стойност <value> за даден сензор.
# Заявката не приема тяло.
# Заявката връща списък с всички отчетени стойности над определената стойност <value> за подадения сензор.
@app.route("/sensors/<sensor_id>/data/filter/<value>", methods=["GET"])
def get_air_quality_sensor_data_above_value(sensor_id, value):
    data = list(air_quality_sensor_data_collection.find({"sensor_id": ObjectId(sensor_id), "air_quality": {"$gt": float(value)}}))
    return jsonify(data), 200


# Да се върнат последните отчетени <n> на брой стойности за даден сензор.
# Заявката не приема тяло.
# Заявката връща списък с последните <n> на брой стойности за дадения сензор.
@app.route("/sensors/<sensor_id>/data/limit/<n>", methods=["GET"])
def get_air_quality_sensor_data_last_n_entries(sensor_id, n):
    data = list(air_quality_sensor_data_collection.find({"sensor_id": ObjectId(sensor_id)}).sort("timestamp", -1).limit(int(n)))
    return jsonify(data), 200


# -----------------------------------------------------------------------------------------------

def get_database():
    # create a connection using MongoClient
    mongo_client = MongoClient(CONNECTION_STRING)

    # return the database
    return mongo_client.get_database(DATABASE_NAME)


if __name__ == "__main__":
    database = get_database()
    air_quality_sensor_collection = database.air_quality_sensors
    air_quality_sensor_data_collection = database.air_quality_sensor_data
    app.run(debug=True, port=8000)
