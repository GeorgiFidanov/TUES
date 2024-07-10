import json
import threading
import time


class Bulb:
    def __init__(self, thing_id, bulb_number):
        self.thing_id = self.policy_id = thing_id
        self.file_name = thing_id + ".json"
        self.event = threading.Event()
        self.attributes = {
            "model": "Standard",
            "diameter": "15cm",
            "warranty": "2y",
            "number": bulb_number
        }
        self.features = {
            "indicators": {
                "properties": {
                    "brightness": 90,
                    "colour": "red"
                },
            },

            "state": {
                "properties": {
                    "working": True
                }
            },
        }

    def save_to_json(self):
        serializable = {
            "thingId": self.thing_id,
            "policyId": self.policy_id,
            "attributes": self.attributes,
            "features": self.features
        }

        with open("./digital-twins/" + self.file_name, 'w') as output:
            json.dump(serializable, output, indent=4, ensure_ascii=False)

    def break_bulb(self):
        print("Bulb number " + str(self.attributes["number"]) + " is broken")
        self.features["state"]["properties"]["working"] = False
        self.features["indicators"]["properties"]["brightness"] = 0
        self.save_to_json()

    def fix_bulb(self, tech_id):
        print("Technician " + str(tech_id) + " is fixing bulb number " + str(self.attributes["number"]))
        time.sleep(3)
        print("Bulb number " + str(self.attributes["number"]) + " is fixed")
        self.features["state"]["properties"]["working"] = True
        self.save_to_json()

    def update_indicators(self, brightness, colour):
        self.features["indicators"]["properties"]["brightness"] = brightness
        self.features["indicators"]["properties"]["colour"] = colour
        print("Update from bulb " + str(self.attributes["number"]) +
              ": brightness: " + str(brightness) + ", colour: " + colour)
        self.save_to_json()
