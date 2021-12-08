import math


class Point:
    count = 0

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.id = Point.count
        Point.count += 1

    @property
    def r(self):
        return math.sqrt(self.x**2+self.y**2)

    @property
    def theta(self):
        return math.atan((self.y/self.x)*180/math.pi)

    def __repr__(self):
        return f'Point({self.x},{self.y})'
