def indent_list(L, level=0):
    if L == None:
        return
    if type(L) in {list, tuple}:  # if is list or tuple
        for child in L:
            indent_list(child, level+1)
    else:  # element
        print(f'{" "*4*level}{L}')


if __name__ == "__main__":
    L = ["a", ["b", "c", ["d", "e"]], "e"]
    indent_list(L)
