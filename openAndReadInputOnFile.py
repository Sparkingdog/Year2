f = open("userInput.txt", 'r')
line = f.readlines()
print(f"My name is {line[0].rstrip()}")
print(f"I like to {line[1].rstrip()} and {line[2].rstrip()}")
