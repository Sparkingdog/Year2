def numberOutline(L, prefix=()):  # prefix is tuple
    if type(L) in {list, tuple}:  # list or tiple
        i = 0
        for v in L:
            if type(v) not in {list, tuple}:#element
                i += 1
            numberOutline(v, prefix+(i,))
    else:  # element
        s = " "*4*(len(prefix)-1)
        s += ".".join(map(str, prefix))
        s += "."+L
        print(s)


if __name__ == "__main__":
    L = ["Introduction", ["Apple", "Pen", "Pineapple"],
         "Cupcake", ["Vodka", "Alcohol"]]
    numberOutline(L)