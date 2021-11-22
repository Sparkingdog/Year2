#! filter out num <0
L1 = [1, 2, -5, -6, -4, 7, 9]
F1 = list(filter(lambda s: s >= 0, L1))
print(F1)
#! filter out word <=4
L2 = ["Apple", "Orange", "", "Banana", "Lamb", "Kid"]
F2 = list(filter(lambda x: len(x) > 4, L2))
print(F2)
