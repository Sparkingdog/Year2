L1 = [3, 7, 2, 5, 10]
L2 = [6, 1, 0, 9, 8]
L3 = [4, 8, 3, 6, 11]

m = list(map(max, L1, L2, L3))
print(m)
# zip like [(L1[0]),L2[0],L3[0]]
#! zip
z = list(zip(L1, L2, L3))
print([max(*i) for i in z])
