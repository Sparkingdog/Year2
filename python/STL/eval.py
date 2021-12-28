# eval(s,globaldict,localdict)
import math
S = '2+3'
print(S)
print(eval(S))  # evaluate
print(eval('a+4', {'a': 50}))
# sandbox
a = 5
print(eval('sin(a+4)', {'__buildins__': None, 'sin': math.sin}))
