def count(L, x):
    if type(L) not in {list, tuple}:
        if L == x:
            return 1
        return 0
    return sum(count(i, x) for i in L)


target = 1
L = [1, 2, 3, [4, 5, [1, 1]]]
print(f"There are {count(L,target)} \"{target}\" element in the list.")
