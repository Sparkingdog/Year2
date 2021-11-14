# list_tuple to dict
# first version (dict)
dic = {}


def add():  # dict parameter#
    l = []
    expense = input(
        "Add an expense or income record with discription and amount:")
    expense = tuple((expense.split()))
    l.append(expense)
    dic.update(l)
    return


def view():
    total = int(money)
    print("Description      Amount")
    print("===========      ======")
    for i in dic:
        total += int(dic.get(i))
        print(f"{i:<10}{dic.get(i):>10}")
    print("===========      ======")
    print(f"Now you have {total} dollars.")
    return


def delete():
    Del = input("Which record do you want to delete?")

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
        else:
            break
