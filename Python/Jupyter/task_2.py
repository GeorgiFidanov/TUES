import difflib #using Python's built-in difflib module

# List of all valid Pokemon types
valid_types = ['Bug', 'Dark', 'Dragon', 'Electric', 'Fairy', 'Fighting', 'Fire', 'Flying', 
               'Ghost', 'Grass', 'Ground', 'Ice', 'Normal', 'Poison', 'Psychic', 'Rock', 'Steel', 'Water']

# Open input file
with open('pokemon_stats.csv', 'r') as f:
    header = f.readline().strip()  # read header row
 

    # Process each line
    for line in f:
        row = line.strip().split(',')
        type_1 = row[3]
        type_2 = row[4]

        # Check if type_1 is valid, if not find the closest match
        if type_1 not in valid_types:
            closest_match = difflib.get_close_matches(type_1, valid_types, n=1)
            if closest_match:
                row[3] = closest_match[0]

        # Check if type_2 is valid, if not find the closest match
        if type_2 not in valid_types:
            closest_match = difflib.get_close_matches(type_2, valid_types, n=1)
            if closest_match:
                row[4] = closest_match[0]