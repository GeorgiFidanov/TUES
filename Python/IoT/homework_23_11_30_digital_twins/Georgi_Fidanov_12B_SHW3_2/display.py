import os
import json
import time
import pandas as pd
from factory import create_directory

aliases = {"thingId": "Bulb ID", "features.indicators.properties.colour": "Colour",
           "features.indicators.properties.brightness": "Brightness", "features.state.properties.working": "State"}

directory_path = './digital-twins'

while True:

    create_directory(directory_path)

    table = pd.DataFrame()
    for filename in os.listdir(directory_path):
        file_path = os.path.join(directory_path, filename)

        with open(file_path, 'r') as file:
            json_data = json.load(file)

        df = pd.json_normalize(json_data)
        table = pd.concat([table, df], ignore_index=True)

    result = table[list(aliases.keys())]
    result = result.rename(columns=aliases)

    print(result)

    time.sleep(5)
