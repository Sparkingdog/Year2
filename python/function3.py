a = (1, 2, 3)
b = (4, 5)
res1 = max(*a, *b)  # unpacking
res2 = max(a, b)
print(res1)
print(res2, "\n")

####
D = {"file": "test.txt", "mode": "r"}
fh = open(**D)
data = fh.readlines()
print(data)
fh.close()
