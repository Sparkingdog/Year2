import os

#! os.getcwd() , os.listdir(d) , os.path.isdir(d)


def countingFiles(p="."):
    if not os.path.isdir(p):  # is file
        return 1
    else:  # is directories
        return(sum(map(countingFiles, os.listdir(p))))


print(countingFiles())
