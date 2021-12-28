
def rec_find(L, val):
    if type(L) in {list, tuple}:
        for v in L:  # i=0,1,2,3 , v = element in l
            p = rec_find(v, val)
            if p == True:
                return True
    return L == val


def word_find(L,word):
    for i in L:
        if type(i)in{list}:
            for child in i:
                word_find(child,word)
        if word in i:
            return True
    return False
L = ["1", "2", ["3", "Hello",["banana"]], "5"]
while True:
    x=input("Enter a word to search in list :")
    print(rec_find(L,x))

