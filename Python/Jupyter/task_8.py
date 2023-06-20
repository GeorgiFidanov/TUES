import difflib  # using Python's built-in difflib module

# List of all valid Pokémon types
valid_types = [
    'Bug', 'Dark', 'Dragon', 'Electric', 'Fairy', 'Fighting', 'Fire', 'Flying',
    'Ghost', 'Grass', 'Ground', 'Ice', 'Normal', 'Poison', 'Psychic', 'Rock', 'Steel', 'Water'
]

# Initialize dictionary to store count of each type
type_counts = {t: 0 for t in valid_types}

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
                type_1 = closest_match[0]

        # Check if type_2 is valid, if not find the closest match
        if type_2 not in valid_types:
            closest_match = difflib.get_close_matches(type_2, valid_types, n=1)
            if closest_match:
                row[4] = closest_match[0]
                type_2 = closest_match[0]

        # Increment count of each type
        if type_1 in valid_types:
            type_counts[type_1] += 1
        if type_2 in valid_types:
            type_counts[type_2] += 1

# Find the total number of starter Pokémon that can be Fire, Grass, or Water
total_starters = type_counts['Fire'] + type_counts['Grass'] + type_counts['Water']

# Count the number of Water Pokémon that are also Poison
water_poison_count = 0

# Open input file again
with open('pokemon_stats.csv', 'r') as f:
    header = f.readline().strip()  # read header row

    # Process each line
    for line in f:
        row = line.strip().split(',')
        type_1 = row[3].capitalize()
        type_2 = row[4].capitalize()

        # Check if this is a Water starter Pokémon
        if type_1 == 'Water':

            # Check if this Water Pokémon is also Poison
            if type_2 == 'Poison':
                water_poison_count += 1

# We count only when a Pokémon is water -> poison, not both ways
# Calculate the probability
probability = water_poison_count / total_starters
print(total_starters)
print(water_poison_count)
print(f"The probability that a Water starter Pokemon is also Poison is {probability:.2%}")
