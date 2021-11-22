def StackInterpreter():
    L = []  # Stack
    D = {"": lambda: None,  # Function Table
         "show": lambda: print(L),
         "push": lambda: L.extend(words[1:]),
         "pop": lambda: print(L.pop())}
    while True:
        line = input("Command? ")
        words = line.split()
        if words[0] == "quit":
            break
        D.get(words[0], lambda: print("Unknown command"))()


StackInterpreter()
