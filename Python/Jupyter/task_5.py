# Open the CSV file for reading
with open('pokemon_stats.csv', 'r') as file:
    # Read the header row
    header = file.readline().strip().split(',')

    # Create a list to hold the valid rows
    valid_rows = []

    # Loop through the remaining rows
    for line in file:
        # Strip any leading/trailing whitespace and split the row into a list
        row = line.strip().split(',')

        # Check if any of the columns are blank
        if '' in row:
            # Skip this row if any columns are blank
            continue

        # Add this row to the list of valid rows
        valid_rows.append(row)

# Open the CSV file for writing
with open('pokemon_stats_cleaned.csv', 'w') as file:
    # Write the header row
    file.write(','.join(header) + '\n')

    # Loop through the valid rows and write them to the file
    for row in valid_rows:
        file.write(','.join(row) + '\n')
