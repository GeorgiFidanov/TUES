import requests
import re

# open the dataset file
with open('pokemon_stats.csv', 'r') as file:
    lines = file.readlines()

# create a list of all the Pokémon names from the dataset
pokemon_names = []
for line in lines[1:]:
    name = line.split(',')[0]
    pokemon_names.append(name)

# create a list of all the English Pokémon names from bulbapedia
response = requests.get('https://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_name')
html = response.text
pokemon_names_bulbapedia = re.findall(r'<td style="background:#.+;">(.+?)</td>', html)

# create a dictionary to store the translations
translation_dict = {}

# loop through all the Pokémon names from the dataset and check if they need to be translated
for name in pokemon_names:
    if name not in pokemon_names_bulbapedia:
        # make a request to the bulbapedia page for the Pokémon
        response = requests.get(f'https://bulbapedia.bulbagarden.net/wiki/{name}_(Pok%C3%A9mon)')
        html = response.text

        # extract the English name from the page
        english_name = re.search(r'<b>English</b></td>\n<td style="background:#.+;">(.+?)</td>', html)
        if english_name:
            english_name = english_name.group(1)
            translation_dict[name] = english_name

# print the translations
for pokemon, translation in translation_dict.items():
    print(f'{pokemon} -> {translation}')
