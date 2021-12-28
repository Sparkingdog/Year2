# list ver
import sys
l = []
flat=[]#flatten use
money =0
def init_categories():
    return ['expense', ['food', ['meal','snack','drink'],'transportation', ['bus', 'railway']], 'income', ['salary', 'bonus']]

def is_category_valid(categories,category):
    if categories == None:
        return
    if category in categories:
        return True
    if type(categories)in{list,tuple}:
        for i in categories:
            is_category_valid(i,category)
    else:
        print(categories)

def view_categories(L,level=0):
    if L == None:
        return
    if type(L) in {list, tuple}:  # if is list or tuple
        for child in L:
            view_categories(child, level+1)
    else:  # element
        print(f'{" "*4*level}->{L}')
            
def find_subcategories(category, categories):
    if type(categories) == list:
        for v in categories:
            p = find_subcategories(category, v)
            if p == True:
                index = categories.index(v)
                if index + 1 < len(categories) and \
                        type(categories[index + 1]) == list:
                    return flatten(categories[index:index + 2])
                else:
                    # return only itself if no subcategories
                    return [v]
            if p != []:
                return p
    return True if categories == category else []
 
def flatten(L):
    for i in L:
        if type(L) == int:
            flat.append(i)
        if type(i)== list:
            flatten(i)
    return flat

    
    # return a flat list that contains all element in the nested list L
    # for example, flatten([1, 2, [3, [4], 5]]) returns [1, 2, 3, 4, 5]

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
        
def add():#expense[0]=category,expense[1]=item,expense[2]=price
    expense = input("Add an expense or income record with discription and amount:")
    expense = tuple((expense.split()))  # store the data in tuple
    try:  # if fail to split
        assert is_category_valid(init_categories(),expense[1])==True
        int(expense[2])
    except AssertionError:
        print("There is no current category")
    except:
        print("The format of a record should be like this: breakfast -50.")
        print("Fail to add a record")
    else:
        l.append(expense)
    return


def view(self):
    total = int(money)
    idx = 0
    print("Category          Description        Amount")
    print("========          ===========        ======")
    for i in l:
        idx = idx+1
        total += int(i[2])
        print(f"{idx}: {i[0]:<10}{i[1]:>10}{i[2]:>20}")  # i[0]->categories ,i[1]->item i[2]->price
    print("========          ===========        ======")
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
            elif command == "view categories":
                view_categories(init_categories())
            elif command == "find":
                find=input("Which category do you want to find?")
                find_subcategories(find,init_categories)
            elif command == "exit":
                record.writelines(f"{money}\n")
                record.writelines(f"{l}")
                break
            else:
                print("Invalid command. Try again.")
