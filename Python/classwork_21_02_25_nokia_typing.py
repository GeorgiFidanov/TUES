def translate(letter):
    number = "0"
    if letter == "A" or letter == "B" or letter == "C":
        number = "1"
    elif letter == "D" or letter == "E" or letter == "F":
        number = "2"
    elif letter == "G" or letter == "H" or letter == "I":
        number = "3"
    elif letter == "J" or letter == "K" or letter == "L":
        number = "4"
    elif letter == "M" or letter == "N" or letter == "O":
        number = "5"
    elif letter == "P" or letter == "Q" or letter == "R":
        number = "6"
    elif letter == "S" or letter == "T" or letter == "U":
        number = "7"
    elif letter == "V" or letter == "W" or letter == "X":
        number = "8"
    elif letter == "Y" or letter == "Z":
        number = "9"
    return number


def translateNumber(phoneNumLetter):
    result = ""
    for i in range(len(phoneNumLetter)):

        curr = phoneNumLetter[i]

        if curr.isalpha():
            curr = curr.upper()
            result += translate(curr)

        elif curr.isnumeric():
            result += curr

        else:
            return print("Your string is invalid, because of simbol:", curr)

    return result


phoneNumLetter = input("Please enter a phone number that contains letters: ")
print("Your original phone number was:", phoneNumLetter)
print("Your translated phone number is:", translateNumber(phoneNumLetter))
