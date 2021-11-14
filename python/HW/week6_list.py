# list ver
l = []


def add():
    expense = input(
        "Add an expense or income record with discription and amount:")
    expense = tuple((expense.split()))
    l.append(expense)
    return


def view():
    total = int(money)
    idx = 0
    print("Description      Amount")
    print("===========      ======")
    for i in l:
        idx = idx+1
        total += int(i[1])
        print(f"{idx}: {i[0]:<10}{i[1]:>10}")  # i[0]->item i[1]->price
    print("===========      ======")
    print(f"Now you have {total} dollars.")
    return


def delete():
    # index "name" "value"
    view()
    Del = input(
        "Which record do you want to delete? (Insert an index to delete)")
    # Del = Del.split()  # Del[0]=idx Del[1]=Name Del[2]=Value
    l.pop(int(Del)-1)
    return


# main()
if __name__ == "__main__":
    money = input("How much money do you have?")

    while(True):
        command = input("What do you want to do (add / view / delete / exit)?")
        if command == "add":
            add()
        elif command == "view":
            view()
        elif command == "delete":
            delete()
        elif command == "exit":
            break
