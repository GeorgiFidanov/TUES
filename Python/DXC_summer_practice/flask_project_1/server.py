from flask import Flask, render_template, request

app = Flask(__name__, template_folder='C:/Users/georg/Documents/flask_project_1/template')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate():
    weight = round(float(request.form['weight']), 2)
    height = round(float(request.form['height']), 2)
    bmi = round(calculate_bmi(weight, height), 1)
    category = get_category(bmi)
    return render_template('result.html', bmi=bmi, category=category)

def calculate_bmi(weight, height):
    return weight / (height ** 2)

def get_category(bmi):
    if bmi < 18.5:
        return 'Underweight'
    elif bmi < 25:
        return 'Normal weight'
    elif bmi < 30:
        return 'Overweight'
    else:
        return 'Obese'

if __name__ == '__main__':
    app.run(debug=True)
