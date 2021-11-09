try:
    x = int(input("enter number num1 :"))
    y = int(input("enter number num2 :"))
    z = x/y
except ValueError:
    print("ValueError")
    z = 0
except ZeroDivisionError:
    print("ZeroDivisionError")
    z = x
print(z)
