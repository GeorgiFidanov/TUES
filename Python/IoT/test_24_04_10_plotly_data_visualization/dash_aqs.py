import pandas as pd
import plotly.express as px
from bson import ObjectId
from pymongo import MongoClient
from dash import Dash, html, callback, Output, Input, dash_table, dcc


DATABASE_NAME = "dash-exam"
CONNECTION_STRING = ""


app = Dash(__name__)


# Define the layout
app.layout = html.Div([
    dcc.Interval(id='interval-component', interval=100000, n_intervals=0),
    dash_table.DataTable(
    id='thermometer-table',
    columns=[
        {"name": "ID", "id": "_id"},
        {"name": "Label", "id": "label"},
        {"name": "Manufacturer", "id": "manufacturer"},
        {"name": "Room", "id": "room"}
    ],
    data=[]
    ),
    dcc.Graph(id='temperature-graph'),
    dcc.RadioItems(
        id='thermometer-filter',
        options=[{'label': 'All', 'value': 'all'}],
        value='all'
    )
])


@callback(
    Output('thermometer-table', 'data'),
    Input('interval-component', 'n_intervals')
)
def update_table(n):
    mongo_client = MongoClient(CONNECTION_STRING)
    database = mongo_client.get_database(DATABASE_NAME)
    thermometer_collection = database.get_collection("thermometers")

    thermometers = thermometer_collection.find()
    
    # Construct the data list with the desired fields
    data = [{"_id": str(thermometer["_id"]), "label": thermometer["label"], "manufacturer": thermometer["manufacturer"], "room": thermometer["room"]} for thermometer in thermometers]

    return data


@callback(
    Output('temperature-graph', 'figure'),
    [Input('interval-component', 'n_intervals'),
     Input('thermometer-filter', 'value')]
)
def update_graph(n, filter_value):
    data = pd.DataFrame(list(temperature_collection.find()))
    print(f"Filter value: {filter_value}") # Debugging: Print the filter value

    data['thermometer_id'] = data['thermometer_id'].astype(str)

    if filter_value == 'all':
        fig = px.line(data, x='timestamp', y='value', color='thermometer_id')
    else:
        filter_value = filter_value.strip()
        filtered_data = data[data['thermometer_id'] == filter_value]
        print(filtered_data.head()) # Debugging: Print the first few rows of the filtered data
        fig = px.line(filtered_data, x='timestamp', y='value')
    return fig


@callback(
    Output('thermometer-filter', 'options'),
    Input('interval-component', 'n_intervals')
)
def update_radio_options(n):
    thermometers = pd.DataFrame(list(thermometer_collection.find()))
    options = [{'label': 'All', 'value': 'all'}] + [{'label': str(id), 'value': str(id)} for id in thermometers['_id'].unique()]
    return options


# Please do not modify the below function
# Use the thermometer_collection and temperature_collection objects to query the database
if __name__ == "__main__":
    mongo_client = MongoClient(CONNECTION_STRING)
    database = mongo_client.get_database(DATABASE_NAME)
    thermometer_collection = database.get_collection("thermometers")
    temperature_collection = database.get_collection("temperatures")
    app.run(debug=True, port=8050)
