
def x(categories,target):

    for child in categories:
        if type(child) == list:
            return x(child,target)
        if target == child:
            return True
    return False

def y(categories,target):

    if type(categories) not in {list,tuple}:#element
        return 
    else:#list or tuple
        if target in categories:
            return True
        for i in categories:
            y(i,target)
    return False
def is_category_valid(categories,category):#! BUG
    if category in categories:
        return True
    if type(categories) == list:
        for child in categories:
            map(is_category_valid(child,category),child)
    return 

def rec_find(L, val):
    if type(L) in {list, tuple}:
        for i, v in enumerate(L):  # i=0,1,2,3 , v = element in l
            p = rec_find(v, val)
            if p == True:
                return(i,)
            if p != False:
                return (i,)+p
    return L == val

categories=['expense', ['food', ['meal','snack','drink'],'transportation', ['bus', 'railway']], 'income', ['salary', 'bonus']]
while True:
    target =input()
    print(rec_find(categories,target))