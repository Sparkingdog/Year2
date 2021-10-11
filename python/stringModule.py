import string


def camelcase(s):
    return "".join(string.capwords(s).split())


s = "my name is meow bot"
print(camelcase(s))
