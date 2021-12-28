class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return __class__.__name__+repr((self.x, self.y))


class colorPoint(Point):
    def __init__(self, x, y, color):
        super().__init__(x, y)
        self.color = color

    def __repr__(self):
        return __class__.__name__+repr((self.color, "x=", self.x, "y=", self.y))
