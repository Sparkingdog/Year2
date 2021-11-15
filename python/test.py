l=[]
money=0
try:#try to read a file
    fh = open("records.txt","r")
    assert fh.read()!=""
except (FileNotFoundError,AssertionError):  # fail to open file
    money = input("How much money do you have?")
    try:
            int(money) #if money is integer
    except:
        print("Invalid value for money. Set to 0 by default.")
        money = 0
else:# success open a file
    money =fh.readline().strip("\n")
    print(money)
    l=fh.readline().strip("\n")
    print(l)
    fh.close()