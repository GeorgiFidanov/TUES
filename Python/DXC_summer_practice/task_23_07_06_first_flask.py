#%%writefile hello.py
from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "Hello World!"

app.run(host='0.0.0.0', port= 6050)

# Now, run the program --> python hello.py