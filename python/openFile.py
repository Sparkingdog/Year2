import sys
fileName = 'test.txt'

try:
    fh = open(fileName)
except:
    sys.stderr.write((f"cannot open file {fileName}.\n"))
    sys.exit(1)
print(f"file {fileName} opened succesfully\n")
