class MyList(list):
    def __repr__(self):
        return self.__class__.__name__+"("+super().__repr__()+")"

    def find(self, val):


if __name__ == "__main__":
    L = MyList([1, 2, 3])
