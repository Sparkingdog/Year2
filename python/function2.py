def Average(*priceArgs):
    sum = 0
    for i in priceArgs:
        sum += i
    return(sum)/i


a = Average(1, 2, 3, 4)
print(a)
