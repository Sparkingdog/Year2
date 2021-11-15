# list ver
import sys
l = []
money =0

def init():
    try:#try to read a file
        fh = open("records.txt","r")
        assert fh.read()!=""
    except (FileNotFoundError,AssertionError):  # fail to open file
        sys.stderr.write("No file is avalible\n")
        money = input("How much money do you have?")
        try:
            int(money) #if money is integer
        except:
            print("Invalid value for money. Set to 0 by default.")
            money = 0
    else:# success open a file
        p=open("records.txt", "r")
        money =p.readline().strip("\n")
        print(f"{money}")
        l=p.readline().strip("\n")
        print(f"{l}")
        p.close()
        fh.close()
        return
        
def add():
    expense = input(
        "Add an expense or income record with discription and amount:")
    expense = tuple((expense.split()))  # store the data in tuple
    try:  # if fail to split
        int(expense[1])
    except:
        print("The format of a record should be like this: breakfast -50.")
        print("Fail to add a record")
    else:
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
    Del = input("Which record do you want to delete? (Insert an index to delete)")
    try:
        int(Del)
    except:
        print("Invalid format. Fail to delete a record.")
        return
    # Del = Del.split()  # Del[0]=idx Del[1]=Name Del[2]=Value
    try:
        l.pop(int(Del)-1)
    except:
        print(f"There's no record with index {Del}. Fail to delete a record.")
        return


# main()
if __name__ == "__main__":
    money = input("How much money do you have?")
    try:
        int(money) #if money is integer
    except:
        print("Invalid value for money. Set to 0 by default.")
        money = 0
    with open("records.txt","w") as record:
        while(True):
            command = input("What do you want to do (add / view / delete / exit)?")
            if command == "add":
                add()
            elif command == "view":
                view()
            elif command == "delete":
                delete()
            elif command == "exit":
                record.writelines(f"{money}\n")
                record.writelines(f"{l}")
                break
            else:
                print("Invalid command. Try again.")
