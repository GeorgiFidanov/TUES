import os
import pandas as pd
from flask import Flask, jsonify

app = Flask(__name__)

# Check if the CSV file exists
current_dir = os.path.dirname(__file__)
csv_file_path = os.path.join(current_dir, 'marks.csv')
if not os.path.exists(csv_file_path):
    raise FileNotFoundError("CSV file '{}' not found.".format(csv_file_path))

# Get the data from the CSV file
data = pd.read_csv(csv_file_path, index_col=0)

@app.route("/")
def home():
    return "<h1>2 pages are availble: /tests and /failed</h1>"

@app.route('/tests', methods=['GET'])
def calculate_test_averages():
    # Calculate the mean of each test and sort them in descending order
    test_averages = data.mean().sort_values(ascending=False)
    
    # Convert the result to a dictionary and return it as JSON
    return jsonify(test_averages.to_dict())

@app.route('/failed', methods=['GET'])
def get_failed_students():
    # Calculate the mean of each student and select those with a mean score below 50
    student_averages = data.mean(axis=1)
    failed_students = student_averages[student_averages < 50]
    
    # Convert the result to a dictionary and return it as JSON
    return jsonify(failed_students.to_dict())

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000)
