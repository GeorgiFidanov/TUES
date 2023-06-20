#!/bin/bash
#3) Да се напише shell скрипт, който приканва потребителя да въведе пълното име на
#директория и извежда на стандартния изход подходящо съобщение за броя на всички файлове
#и всички директории в нея.

#directory_name=
echo "Enter the full name of the directory:"
read directory_name

#read -p "Enter a dictionary: " output
if [ -d "$directory_name" ]; then
    num_files=$(find "$directory_name" -type f | wc -l)
    num_dirs=$(find "$directory_name" -type d | wc -l)
    echo "The directory '$directory_name' contains $num_files files and $num_dirs directories."
else
    echo "Error: '$directory_name' is not a directory."
fi