# while : else break continue
# for

eng = {"one": 3, "two": 2, "three": 3}
malay = {"satu": 1, "dua": 2, "tiga": 3}

while True:
    word = input("Please enter a word :")
    if word in eng:
        print(f"in English: {eng[word]}")
    elif word in malay:
        print(f"in Malay: {malay[word]}")
    else:
        print(f"{word} does not found in local dictionaries")
