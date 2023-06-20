import difflib  # using Python's built-in difflib module

# List of all valid Pokémon types
valid_types = ['Poison']

# Open input file
with open('pokemon_stats.csv', 'r') as f:
    header = f.readline().strip()  # read header row

    poison_count = 0  # counter for Poison type

    # Process each line
    for line in f:
        row = line.strip().split(',')
        type_1 = row[3]
        type_2 = row[4]

        if type_1 not in valid_types:
            closest_match = difflib.get_close_matches(type_1, valid_types, n=1)
            if closest_match:
                row[3] = closest_match[0]
                type_1 = closest_match[0]

            # Check if type_2 is valid, if not find the closest match
        if type_2 not in valid_types:
            closest_match = difflib.get_close_matches(type_2, valid_types, n=1)
            if closest_match:
                row[4] = closest_match[0]
                type_2 = closest_match[0]

        # Check if either type_1 or type_2 is Poison
        if type_1 == 'Poison' or type_2 == 'Poison':
            poison_count += 1

    print(f"There are {poison_count} Pokemon of the Poison type.")
