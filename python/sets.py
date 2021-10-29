a = set(range(1, 10, 2))
b = set(range(10, 20))
print(a & b)  # a n b
b.update(a)
print(b)
