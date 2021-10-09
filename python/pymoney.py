starting_money = input("How much money do you have?")
string = input()
amount = string.split(' ')
print("Now you have %d dollars." % (int(starting_money)+int(amount[1])))
