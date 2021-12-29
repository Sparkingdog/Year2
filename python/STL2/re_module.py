import re
#pattern matching
s=re.search('Gary','Mary had a little lamb') #if not found ,s is none
x=re.search('little','Mary had a little lamb')
ref=re.findall('little','Mary had a little lamb,little lamb')
