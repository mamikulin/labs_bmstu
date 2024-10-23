from lab_python_oop.rectangle import Rectangle

class Square(Rectangle):
    def __init__(self, side, color):
        super().__init__(side, side, color, "Квадрат")

    def __repr__(self):
        return "{} со сторогой {} и цвета: {}, площадью: {}".format(
            self.get_T(),
            self.w,
            self.color.get_color(),
            self.area())