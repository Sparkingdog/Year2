from collections import namedtuple
Point = namedtuple('Point',['x','y'])#immutable class
p=Point(2,3)
print(p)
q=p._replace(y=5)
print(q)
#p[1]=5 does not support assignment

