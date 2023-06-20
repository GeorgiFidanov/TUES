#!/bin/bash

# Check the number of arguments
if [ "$#" -ne 3 ]; then
  echo "Error: Wrong number of arguments"
  exit 1
fi

# Assign arguments to variables
answers="$1"
answers_sheet="$2"
results="$3"
i=1;
max=25;


# Check if each file in the first argument contains exactly 25 lines and it's readable
for i in $max; do
  file_path="$answers/$i"
    
  line_count=$(wc -l < "$file_path")
  if [ "$line_count" -ne $max ]; then
    echo "Error: Each file in the directory must contain exactly 25 lines."
    exit 1
  fi

  if [ ! -f "$file_path" ] || [ ! -r "$file_path" ]; then
  echo "Error: Each file in the directory must be a readable file."
  exit 1
  fi
done

# Check if the second argument is a readable file
if [ ! -f "$answers_sheet" ] || [ ! -r "$answers_sheet" ]; then
  echo "Error: The second argument must be a readable file."
  exit 1
fi

# Check if the second argumen contains exactly 25 lines
line_count=$(wc -l < "$answers_sheet")
if [ "$line_count" -ne $max ]; then
  echo "Error: The file must contain exactly 25 lines."
  exit 1
fi

# Check if the third argument is an empty directory with the right permissions
if [ ! -d "$results" ]; then
  echo "Error: The third argument must be a directory."
  exit 1
fi

if [ "$(ls -A "$results")" ]; then
  echo "Error: The third directory must be empty."
  exit 1
fi

if [ ! -w "$results" ]; then
  echo "Error: The script does not have write permissions in results directory."
  exit 1
fi

# Grade and create the output files
for ((j=1; j<=25; j++)); do
  file_path="$answers/$j"
  output_file="$results/$j"  
  grade=0

  # Read one character from two inputs: the student's answer file and the answer key file
  while IFS= read -r -n1 ans && IFS= read -r -n1 key <&3; do

    # Validate student's answers and the answer file
    if test $(grep -E '^[ABCD]$' "$file_path" | wc -l) -ne 25; then
      echo "Invalid answer in student $j's answer file: $ans"
      exit 1
    fi

    if test $(grep -E '^[ABCD]$' "$answers_sheet" | wc -l) -ne 25; then
      echo "Invalid answer in correct answers sheet file: $key"
      exit 1
    fi

    if [ "$ans" == "$key" ]; then
      ((grade += 1))
    fi

  # Redirect the inputs to fd 3 (for simultaneous reading)  
  done < "$file_path" 3< "$answers_sheet"
  
  # Remove the found newline 
  ((grade -= 25)) 
  
  # Grades
  if ((grade >= 0 && grade <= 13)); then
    grade=2
  elif ((grade >= 14 && grade <= 16)); then
    grade=3
  elif ((grade >= 17 && grade <= 19)); then
    grade=4
  elif ((grade >= 20 && grade <= 22)); then
    grade=5
  elif ((grade >= 23 && grade <= 25)); then
    grade=6
  fi  
  echo "$grade" > "$output_file"
done

echo "Grading completed successfully."
exit 0
