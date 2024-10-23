import abc
from lab_python_oop.color import Color

class Geometry(abc.ABC):
    
    def __init__(self, color, type):
        self.color = Color(color)
        self.TYPE = type

    def get_T(self):
        return self.TYPE

    @abc.abstractmethod 
    def area(self): pass