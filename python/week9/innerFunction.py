def StackInterpreter():  # ! DocString let other people use
    """This is a stack interpreter.The commands are:
    show                    --shows stack contcnt
    push item1 item2 item3  --pushes item1,...
    pop                     --pop
    quit                    --quit
    """
    L = []  # Stack

    def show():
        print(L)

    def push():
        L.extend(words[1:])

    def pop():
        print(L.pop())

    def unknown():
        print("unknown command")

    D = {"": lambda: None,  # Function Table
         "show": show,
         "push": push,
         "pop":  pop}
    while True:
        line = input("Command? ")
        words = line.split()
        if words[0] == "quit":
            break
        D.get(words[0], unknown)()


StackInterpreter()
