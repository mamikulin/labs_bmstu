import lab_python_oop.circle as circle
import lab_python_oop.rectangle as rectangle
import lab_python_oop.square as square

from autocorrect import Speller

spell = Speller(lang='en')


def main():
    A = circle.Circle(11, "Blue")
    B = rectangle.Rectangle(11, 11 , "Blue")
    C = square.Square(11, "Blue")

    print(A)
    print(B)
    print(C)

    print(spell('mussage'))
    print(spell('hte'))
    

if __name__ == "__main__":
    main()