# practise allignment and function

def MultTable(L, R):
    for left in L:
        for right in R:
            print("{:3d} x {:3d} = {:3d}".format(left, right, left*right))


if __name__ == "__main__":
    lRange = range(1, 10)
    rRange = range(1, 10)
    MultTable(lRange, rRange)  # multiplication table for 9x9
