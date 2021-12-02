import os


def countingFiles(path="/root/Meowbot_ΦωΦ"):
    if not os.path.isdir(path):  # is file
        return 1
    return(sum(map(countingFiles, os.listdir(path))))


print(countingFiles())
