import unittest

from lab_python_fp import field
from lab_python_fp import print_result


class FieldTest(unittest.TestCase):
    goods = [
        {'title': 'Ковер', 'price': 2000, 'color': 'green'},
        {'title': 'Диван для отдыха', 'color': 'black'}
    ]

    def test_1(self):
        self.assertEqual(field.field(self.goods, 'title', 'price'), [{'title': 'Ковер', 'price': 2000}, {'title': 'Диван для отдыха'}], 'wrong')
   
    def test_2(self):
        self.assertEqual(field.field(self.goods, 'title'), ['Ковер', 'Диван для отдыха'], 'wrong')
    
    def test_3(self):
        self.assertEqual(field.field(self.goods, 'color'), ['green', 'black'], 'wrong')

if __name__ == '__main__':
    unittest.main()