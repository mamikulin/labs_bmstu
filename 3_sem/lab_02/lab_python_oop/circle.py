from lab_python_oop.geometry import Geometry
from lab_python_oop.color import Color

import math

class Circle(Geometry):

    def __init__(self, rad, color):
        self.rad = rad
        super().__init__(color, "Круг")
        
    def area(self):
        return math.pi * (self.rad ** 2)

    def __repr__(self):
        return "{} радиуса: {} и цвета: {}, площади: {}".format(
            self.TYPE,
            self.rad, 
            self.color.get_color(),
            self.area())
        