import sys


def RockPaperScissors():
    global a
    a = input("Plese enter rock paper or scissors :")
    if a == "q":  # quit
        sys.exit(0)
    return a


try:
    RockPaperScissors()
    assert a in {"r", "p", "s"}
except AssertionError:
    print("Only rps input")
