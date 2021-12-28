# list ver
import sys

class Global:
    l = [] 
    money =0
    categories=['expense', ['food', ['meal','snack','drink'],'transportation', ['bus', 'railway']], 'income', ['salary', 'bonus']]

class Record:#Object
    def __init__(self,category,item,price):
        self.category=category
        self.item=item
        self.price=price
    #getter
    def category(self):
        return self.category
    def item(self):
        return self.item
    def price(self):
        return self.price
    def List(self):
        return [self.category,self.item,self.price]

class Records:#read from records.txt
    def __init__(self):
        try:
            with open("records.txt","r")as f:
                Global.l=eval(f.readline())
        except:
            print("fail to read file")

    def add(category,item,price):#expense[0]=category,expense[1]=item,expense[2]=price
        try:
            if Categories.is_category_valid(Global.categories,item)==False or \
            Categories.is_category_valid(Global.categories,category)==False:
                raise AssertionError
        except AssertionError:
            print("The specified category is not in the category list.")
            print("You can check the category list by command view categories.")
            print("Fail to add a record.")
        else:
            Global.l.append(Record(category,item,price).List())

    def view():
        total = int(Global.money)
        idx = 0
        print(f"{'   Category':<20}{'Description':^15}{'Amount':>20}")
        print(f"{'   ========':<20}{'===========':^15}{'======':>20}")
        for i in Global.l:
            idx = idx+1
            total += int(i[2])
            print(f"{idx}: {i[0]:<20}{i[1]:^15}{i[2]:>17}")  # i[0]->categories ,i[1]->item i[2]->price
        print(f"{'   ========':<20}{'===========':^15}{'======':>20}")
        print(f"Now you have {total} dollars.")
        return

    def delete():
    # index "name" "value"
        Records.view()
        Del = input("Which record do you want to delete? (Insert an index to delete)")
        try:
            int(Del)
        except:
            print("Invalid format. Fail to delete a record.")
            return
    # Del = Del.split()  # Del[0]=idx Del[1]=Name Del[2]=Value
        try:
            Global.l.pop(int(Del)-1)
        except:
            print(f"There's no record with index {Del}. Fail to delete a record.")
            return
    
    def save():
        try:
            with open("records.txt","w") as f:
                f.writelines(str(Global.l))
        except:
            print("fail to open the file")

class Categories:

    def view(categories,level=0):
        if  categories== None:
            return
        if type(categories) in {list, tuple}:  # if is list or tuple
            for child in categories:
                Categories.view(child,level+1)
        else:  # element
            print(f'{" "*4*level}->{categories}')
            
    def is_category_valid(categories,category):
        if type(categories) in {list, tuple}:
            for child in categories:
                p = Categories.is_category_valid(child, category)
                if p == True:
                    return True
        return categories == category
    
    
# def find_subcategories_gen(category, categories, found=False):
#     if type(categories) == list:
#         for index, child in enumerate(categories):
#             yield from find_subcategories_gen(category, child,found=True)
#             if child == category and index + 1 < len(categories) \
#                 and type(categories[index + 1]) == list:
#                 # When the target category is found,
#                 # recursively call this generator on the subcategories
#                 # with the flag set as True.
#                 yield from 
#     else:
#         if categories == category or found==True:
#             yield categories

if __name__=='__main__':
    categories = Categories()
    records = Records()
    while True:
        command = input('What do you want to do (add / view / delete / view categories / find / exit)? ')
        if command == 'add':#! Done
            record = input('Add an expense or income record with category, item, and price (separate by spaces):')
            record=record.split()
            try:
                Records.add(record[0],record[1],int(record[2]))
            except ValueError:
                print("Please Based on format (category,item,price)")
        elif command == 'view':#! Done
            Records.view()
        elif command == 'delete':#! Done
            Records.delete()
        elif command == 'view categories':#! Done
            Categories.view(Global.categories)
        elif command == 'find':# TODO
            target = input('Which category do you want to find? ')
            target_categories = Categories.find_subcategories(target)
            Records.find(target_categories)
        elif command == 'exit':#! Done
            Records.save()
            break
        else:
            sys.stderr.write('Invalid command. Try again.\n')#! Done
