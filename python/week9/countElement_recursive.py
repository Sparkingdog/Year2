def recCount(x):
    if type(x) != list:  # element
        return 1
    c = 0
    for i in x:  # list
        c += recCount(i)
    return c


def count(x):
    if type(x) != list:  # element
        return 1
    return sum(map(count, x))


def r_count(x):
    if type(x) != type([]):
        return 1  # not empty list
    elif len(x) == 0:  # empty list
        return 0
    else:
        return r_count(x[0])+r_count(x[1:])


L = ["a", ["b", "c", ["d", "e"], "f", "g"]]
print(count(L))
