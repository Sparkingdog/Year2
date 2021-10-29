calander = {1: "january", 2: "febuary", 3: "march"}
print(calander.get(1))
calander2 = {4: "april", 5: "may", 1: "satu"}
calander.update(calander2)  # update can be add or modifying original dict
print((calander.keys()))
print((calander.values()))
