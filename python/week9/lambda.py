w = ["Mon", "Tue", "Wed", "Thur", "Fri"]
d = {"Mon": 1, "Tue": 2, "Wed": 3, "Thur": 4, "Fri": 5}
l = w[:]
l.sort(key=lambda s: d[s])
print(l)
#
