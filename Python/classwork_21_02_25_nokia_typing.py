phoneNumLetter = [str(input("Please enter a phone number that contains letters: "))]


def translate(char):
    number = 0
    if char.upper() == "A" or char.upper() == "B" or char.upper() == "C":
        number = 2
    elif char.upper() == "D" or char.upper() == "E" or char.upper() == "F":
        number = 3
    elif char.upper() == "G" or char.upper() == "H" or char.upper() == "I":
        number = 4
    elif char.upper() == "J" or char.upper() == "K" or char.upper() == "L":
        number = 5
    elif char.upper() == "M" or char.upper() == "N" or char.upper() == "O":
        number = 6
    elif char.upper() == "P" or char.upper() == "Q" or char.upper() == "R" or char.upper() == "S":
        number = 7
    elif char.upper() == "T" or char.upper() == "U" or char.upper() == "V":
        number = 8
    elif char.upper() == "W" or char.upper() == "X" or char.upper() == "Y" or char.upper() == "Z":
        number = 9
    return number


def translateNumber(phoneNumLetter):
    result =''
    char =['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
                      'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

    number = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    i = 0

    if char in phoneNumLetter[i]:
        result[i] = translate(phoneNumLetter[i])
        i = i + 1

    if number in phoneNumLetter[i]:
        result[i] = phoneNumLetter[i]
        i = i + 1

    if phoneNumLetter[i] == number:
        result[i] = phoneNumLetter[i]

    return result


def main():
    print("Your original phone number was: ", phoneNumLetter)
    print("Your translated phone number is: ", translateNumber(phoneNumLetter))


main()
