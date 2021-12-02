L = [1, 2, 3, 4, 5]
f = list(filter(lambda s: s % 2 == 0, L))
print(f)
L2 = ["Apple", "pen", "Pineapple pen", "Guava"]
f2 = list(filter(lambda s: s in {"pen"}, L2))
print(f2)
