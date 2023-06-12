import matplotlib.pyplot as plt

# Define list of column indices to calculate means for
mean_cols = [1, 2, 5, 6, 7, 8, 9, 10]

# Initialize dictionary to store counts and sums for each column
col_counts = {i: 0 for i in mean_cols}
col_sums = {i: 0 for i in mean_cols}

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

# Calculate means for each column
col_means = {i: col_sums[i] / col_counts[i] for i in mean_cols}

# Create table-like visualization
fig, ax = plt.subplots()
ax.axis('off')
table_data = [[header[i], '{:.2f}'.format(col_means[i])] for i in mean_cols]
table = ax.table(cellText=table_data, colLabels=['Column', 'Average'], loc='center')
table.auto_set_font_size(False)
table.set_fontsize(14)
table.scale(1, 1.5)
plt.show()
