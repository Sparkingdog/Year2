#!/usr/bin/env python3
import sys
numberOfArgs = len(sys.argv)
if(numberOfArgs != 2):
    sys.stderr.write("Usage: %s inputFile\n" % sys.argv[0])
    sys.exit(1)
try:
    fh = open(sys.argv[1], "r")
except:
    sys.stderr.write("cannot open input file %s\n" % sys.argv[1])
    sys.exit(2)
lines = words = chars = 0  # init
for line in fh.readlines():
    lines += 1  # add 1 for each line
    words += len(line.split())
    chars += len(line)
fh.close()
print(f"{lines:8d} lines,{words:8d} words,{chars:8d} chars,filename: {sys.argv[1]}")
