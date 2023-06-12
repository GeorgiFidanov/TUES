import difflib
import matplotlib.pyplot as plt

# List of all valid Pokémon types
valid_types = ['Bug', 'Dark', 'Dragon', 'Electric', 'Fairy', 'Fighting', 'Fire', 'Flying',
               'Ghost', 'Grass', 'Ground', 'Ice', 'Normal', 'Poison', 'Psychic', 'Rock', 'Steel', 'Water']

# Initialize dictionary to store count of each type
type_counts = {t: 0 for t in valid_types}

# Open input file
with open('pokemon_stats.csv', 'r') as f:
    header = f.readline().strip()  # read header row

    # Process each line
    for line in f:
        row = line.strip().split(',')
        type_2 = row[4]

        # Check if type_2 is valid, if not find the closest match
        if type_2 not in valid_types:
            closest_match = difflib.get_close_matches(type_2, valid_types, n=1)
            if closest_match:
                row[4] = closest_match[0]
                type_2 = closest_match[0]

        # Increment count of each type
        if type_2 in valid_types:
            type_counts[type_2] += 1

# Create a histogram of secondary types
plt.bar(range(len(type_counts)), list(type_counts.values()), align='center')
plt.xticks(range(len(type_counts)), list(type_counts.keys()), rotation='vertical')
plt.xlabel('Secondary Type')
plt.ylabel('Count')
plt.title('Histogram of Secondary Types')

plt.show()
# The most common secondary type is Flying withover 94 Pokémon
