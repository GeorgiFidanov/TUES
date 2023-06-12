def counter(pepe):
    cnt1 = 0
    cnt2 = 0
    length_of_pepe = len(pepe)  # we get input's length

    for i in range(length_of_pepe):
        pe = pepe[i]
        #  print("Curr simbol:", pe)
        if pe.isalpha():  # Check if it's a letter
            if pe.isupper():  # Is it cap???
                cnt1 += 1
            elif pe.islower():   # Is it smol???
                cnt2 += 1

    print("Total uppercase:", cnt1)
    print("Total lowercase:", cnt2)


string = input("Enter pepe:")  # Get input
counter(string)
