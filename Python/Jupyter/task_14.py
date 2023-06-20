# Load data from file
with open('pokemon_stats.csv', 'r') as f:
    data = []
    for line in f:
        row = line.strip().split(',')
        if row[1].isdigit() and row[6].isdigit():
            data.append((float(row[6]), float(row[1])))

# Calculate slope and intercept of line of best fit
x_mean = sum(d[0] for d in data) / len(data)
y_mean = sum(d[1] for d in data) / len(data)
xy_mean = sum(d[0] * d[1] for d in data) / len(data)
x_squared_mean = sum(d[0]**2 for d in data) / len(data)

slope = (xy_mean - x_mean * y_mean) / (x_squared_mean - x_mean**2)
intercept = y_mean - slope * x_mean

# Use equation of line to predict height for Pokémon with 85 attack
attack = 85
height = slope * attack + intercept
print(f"Predicted height for Pokemon with 85 attack: {height:.2f}")
