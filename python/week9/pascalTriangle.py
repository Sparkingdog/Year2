def pascal(row, col):
    if col == 0 or row == col:
        return 1
    elif col > 0 and col < row:
        return (pascal(row-1, col)+pascal(row-1, col-1))


def printPascal(n):
    for i in range(n):
        for j in range(n):
            if j <= i:
                print(f"{pascal(i,j)} ", end="")
        print("\n")
    return


printPascal(20)
# exec(input())
