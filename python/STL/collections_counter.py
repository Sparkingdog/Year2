from collections import Counter
c=Counter({'red':4,'blue':2})
d=Counter('abcdeaacc')
print(d.most_common())
print(d.most_common()[-1])#least common