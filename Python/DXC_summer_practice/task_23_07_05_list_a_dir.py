import os
from datetime import datetime

def display_directory_contents(directory):
    total_items = 0
    total_size = 0

    # align the display 
    print(f"Contents of directory: {directory}")
    print("{:<5} {:<20} {:<30} {:<10} {:<10}".format("Id", "Mtime", "Name", "Type", "Size"))
    print("-" * 78)

    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        item_type = "Directory" if os.path.isdir(item_path) else "File"
        item_size = os.path.getsize(item_path) if os.path.isfile(item_path) else 0
        item_mtime= datetime.fromtimestamp(os.path.getmtime(item_path)).strftime("%d.%m.%Y %H.%M") 

        total_items += 1
        total_size += item_size

        id_formated =  "{:<5}".format(total_items)
        modif_time_formatted = "{:<20}".format(item_mtime) 
        name_formatted = "{:<30}".format(item[:27] + '...' if len(item) > 30 else item)
        type_formatted = "{:<10}".format(item_type)
        size_formatted = "{:<10}".format(item_size)
        

        print(f"{id_formated }: {modif_time_formatted} {name_formatted} {type_formatted} {size_formatted}")

        

    print("-" * 78)
    print(f"Total items found: {total_items}")
    print(f"Total size of directory: {total_size} bytes")

dir = str(input("Enter the dir you want to list: "))
display_directory_contents(dir)
