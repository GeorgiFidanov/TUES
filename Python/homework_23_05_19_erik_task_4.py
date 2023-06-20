for i in range(1, 10):
    for j in range(10):
        # j e 0
        if i > j:  # dokato j ne stane i, printirame edno i sushto chislo(i)
            print(i, end="")  # printirame stojnostta na i
            j += 1  # uvelichaveme broqcha (j)
    print()  # po nov red za vsqko novo chislo
