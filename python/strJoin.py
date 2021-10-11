def MakeSnakeCase(s):
    return"_".join(s.split())


s = ["Hello", "World", "Goodbye~"]
print("-".join(s))
print(MakeSnakeCase("This is my name"))