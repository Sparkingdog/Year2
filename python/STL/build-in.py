# try to protect the built in function dont use the same name
print(len([1, 2, 3]))
len = 'x,y,z'
print(len+'ABC')
len = __builtins__.len  # recover
print(len([1, 2, 3]))