total_attack = 0
num_pokemon = 0

with open('pokemon_stats.csv', 'r') as f:
    header = f.readline().strip()  # read header row

    for line in f:
        row = line.strip().split(',')
        if '' in row:
            # Skip this row if any columns are blank
            continue

        attack = int(row[6])

        total_attack += attack
        num_pokemon += 1

mean_attack = total_attack / num_pokemon

print("Mean attack:", mean_attack)
# average -> 76.10044642857143
