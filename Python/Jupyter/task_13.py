# Define list of column indices to calculate means for
mean_cols = [1, 2, 5, 6, 7, 8, 9, 10]

# Initialize dictionary to store counts and sums for each column
col_counts = {i: 0 for i in mean_cols}
col_sums = {i: 0 for i in mean_cols}
col_values = {i: [] for i in mean_cols}

# Open input file
with open('pokemon_stats.csv', 'r') as f:
    # Read header row
    header = f.readline().strip().split(',')
    # Process each line
    for line in f:
        row = line.strip().split(',')
        # Check if row is valid
        if len(row) != len(header):
            continue
        # Update column counts and sums
        for i in mean_cols:
            if row[i]:
                col_counts[i] += 1
                col_sums[i] += float(row[i])
                col_values[i].append(float(row[i]))

# Calculate means for each column
col_avrg = {i: col_sums[i] / col_counts[i] for i in mean_cols}

# Calculate mode for each column
col_modes = {}
for i in mean_cols:
    col_modes[i] = max(col_values[i], key=col_values[i].count)

# Print table of means and modes
print('Column\tMean\tMode\tDifference')
for i in mean_cols:
    difference = col_avrg[i] - col_modes[i]
    print('{}\t{:.2f}\t{}\t{:.2f}'.format(header[i], col_avrg[i], col_modes[i], difference))
