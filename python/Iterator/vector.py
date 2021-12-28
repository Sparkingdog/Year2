import operator as op
class vector:
    def __init__(self,*v):
        self._v = list(v)
    def __repr__(self):
        return self.__class__.__name__+repr(tuple(self._v))
    def __add__(self,right):
        return vector(*map(op.add,self._v,right._v))
    def __len__(self):
        return len(self._v)
    def __getitem__(self,idx):
        if type(idx) == int:
            return self._v[idx]
        elif type(idx) == slice:
            return vector(*(self._v[idx]))
        else:
            raise TypeError(type(idx).__name__+"unsupported for getitem")
    def __setitem__(self, idx,v):
        if type(idx) == int:
            self._v[idx]=v
        elif type(idx) == slice:
            self._v[idx] = v if not isinstance(v,vector) else v._v[:]
        else:
            raise TypeError(type(idx).__name__+'unsupported for setitem')
    def __iter__(self):
        return vector_Iterator(self)
    
class vector_Iterator:
    def __init__(self,vec):
        self._vec=vec
        self._i=0
    def __next__(self):
        if self._i >=len(self._vec):
            raise StopIteration
        val = self._vec[self._i]
        self._i+=1
        return val

if __name__ == "__main__":
    A=vector(1,2,3,4,5)
    B=vector(6,7,8,9,10)
    ptr=iter(A)
    print(*ptr)
    print(next(ptr))
