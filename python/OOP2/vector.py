import operator as op
class Vector:
    def __init__(self,*v):
        self._v=list(v)
    def __repr__(self):
        return __class__.__name__+