from lab_python_oop.geometry import Geometry
from lab_python_oop.color import Color



class Rectangle(Geometry):
 
    

    def __init__(self, h, w, color, type = "Прямоугольник"):
        self.h = h
        self.w = w
        super().__init__(color, type)
        
    def area(self):
        return self.h * self.w
    
    

    def __repr__(self):
        return "{}: {}:{} и цвета: {}, площадью: {}".format(
            self.get_T(), 
            self.w, self.h , 
            self.color.get_color(),
            self.area())
        