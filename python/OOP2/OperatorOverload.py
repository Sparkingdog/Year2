import operator as op

class Vector:
    def __init__(self,*v):
        self._v=list(v)

    def __repr__(self):
        return __class__.__name__+repr(tuple(self._v))
    def __add__(self,right):
        return Vector(*map(op.add,self._v,right._v))
    def __sub__(self,right):
        return Vector(*map(op.sub,self._v,right._v))

A=Vector(1,2,3,4)
B=Vector(5,6,7,8)
print(A+B)