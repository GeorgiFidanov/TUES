def count_letters(word):
    return len(word)

def making_a_dict(text):
    # Split the text into words
    words = text.split()

    # Create a dictionary with word indices
    word_dict = {index + 1: word for index, word in enumerate(words)}

    return word_dict


def validate_input(input):
    while input.lower() != 'q':
        if input.isdigit():
            return True
        else:
            print("Invalid input. Please enter a valid word index.")
            return True
        
    else: 
        exit()
    
# Get the input text from the user
inp = input("Enter some text: ")

# Display the word indices
print("Word Indices:")

word_dict = making_a_dict(inp)
for index, word in word_dict.items():
    print(f"{word}: {index}")


while True:
    # Prompt for checking the letter count of a specific word
    check_index = input("Enter a word index to check its letter count (or 'q' to quit): ")

    # Check the letter count of the specified word index
    valid_in = validate_input(check_index)

    index = int(check_index)
    if index in word_dict:
        word = word_dict[index]
        letters = count_letters(word)
        print(f"The word with index {index} ('{word}') has {letters} letters.")
    else:
        print("Invalid word index.")

   # valid_in(check_index = input("Enter another word index (or 'q' to quit): "))

print("Program terminated.")
