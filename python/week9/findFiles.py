
def rec_find(L, val):
    if type(L) in {list, tuple}:
        for i, v in enumerate(L):  # i=0,1,2,3 , v = element in l
            p = rec_find(v, val)
            if p == True:
                return(i,)
            if p != False:
                return (i,)+p
    return L == val


L = [1, 2, [3, 4], 5]
print(L.index(3))
