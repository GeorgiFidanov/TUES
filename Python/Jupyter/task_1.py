input_file = 'pokemon_stats.csv'
output_file = 'pokemon_stats_cleaned.csv'

# Set to store seen rows
seen_rows = set()

# Read input file and store unique rows
with open(input_file, 'r') as f:
    header = f.readline().strip()  # read header row
    with open(output_file, 'w') as out_f:
        out_f.write(header + '\n')  # write header row to output file
        for line in f:
            row = line.strip()
            if row not in seen_rows:
                seen_rows.add(row)
                out_f.write(row + '\n')
