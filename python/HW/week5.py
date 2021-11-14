# list_tuple function
money = input("How much money do you have?")
total = int(money)
expense = input("Add an expense or income record with discription and amount:")
expense = expense.split(",")
for i in range(len(expense)):  # ["a 100","b 200","c 300"]
    expense[i] = tuple(expense[i].split())  # [("a","200"),("b""100")]
print("Here's your expense and income records:")
for j in expense:  # for every j = tuple
    print(" ".join(j))  # print out expense
    total += int(j[1])  # sum up the total expense
print(f"Now you have {total} dollars.")
