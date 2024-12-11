import unittest

from src.conductor import *
from src.orchestra import *
from src.connection import *

import tasks

class TestRK(unittest.TestCase):
    
    orchestras = [
        Orchestra(1, "Royal Concertgebouw Orchestra", "Amsterdam"),
        Orchestra(2, "Berlin Philharmonic Orchestra", "Berlin"),
        Orchestra(3, "Los Angeles Philharmonic", "Los-Angeles")
    ]

    conductors = [
        Conductor(1, "Томас Бичем", 1, 10),
        Conductor(2, "Карло Мария Джулини", 2, 15),
        Conductor(3, "Артуро Тосканини", 3, 16),
        Conductor(4, "Вильгельм Фуртвенглер", 2, 19),
        Conductor(5, "Николаус Арнонкур", 1, 12)
    ]

    many_to_many = [
        ConductorOrchestra(3, 1),
        ConductorOrchestra(2, 1),
        ConductorOrchestra(1, 2),
        ConductorOrchestra(1, 3),
        ConductorOrchestra(4, 2)
    ]

    def test_1(self):
        self.assertEqual(tasks.first_task(self.conductors, self.orchestras), [('Карло Мария Джулини', 'Berlin Philharmonic Orchestra'), ('Артуро Тосканини', 'Los Angeles Philharmonic')], 'wrong')
   
    def test_2(self):
        self.assertEqual(tasks.second_task(self.conductors, self.orchestras), [('Royal Concertgebouw Orchestra', 11.0), ('Los Angeles Philharmonic', 16.0), ('Berlin Philharmonic Orchestra', 17.0)], 'wrong')
    
    def test_3(self):
        self.assertEqual(tasks.third_task(self.conductors, self.orchestras, self.many_to_many), [('Royal Concertgebouw Orchestra', ['Артуро Тосканини', 'Карло Мария Джулини'])], 'wrong')

if __name__ == '__main__':
    unittest.main()

    