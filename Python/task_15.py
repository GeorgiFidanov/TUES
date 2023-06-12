import matplotlib.pyplot as plt

# Initialize empty lists to store weight and special defense values
weights = []
special_defenses = []

# Open input file
with open('pokemon_stats.csv', 'r') as f:
    header = f.readline().strip()  # read header row

    # Process each line
    for line in f:
        row = line.strip().split(',')
        if '' in row:
            # Skip this row if any columns are blank
            continue
        weight = row[2]
        special_defense = row[9]

        # Append weight and special defense values to their respective lists

        weights.append(weight)
        special_defenses.append(special_defense)
        weights.sort()
        special_defenses.sort()

# Create scatter plot
plt.scatter(weights, special_defenses)
plt.xlabel('Weight')
plt.ylabel('Special Defense')
plt.title('Weight vs Special Defense')
plt.show()
# more weight == more special defence
