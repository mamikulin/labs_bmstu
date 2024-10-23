from src.conductor import *
from src.orchestra import *
from src.connection import *


orchestras = [
    Orchestra(1, "Royal Concertgebouw Orchestra", "Amsterdam"),
    Orchestra(2, "Berlin Philharmonic Orchestra", "Berlin"),
    Orchestra(3, "Los Angeles Philharmonic;", "Los-Angeles")
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


def first_task():
    r = [(
    conductor.fio, orchestra.name)
    for conductor in conductors 
        for orchestra in orchestras 
            if (conductor.orchestra_id == orchestra.id)
                and (conductor.fio[-2:] == "ни")]

    return r

def second_task():
    r = [[_.name, 0, 0] for _ in orchestras]
    for conductor in conductors:
        r[conductor.orchestra_id - 1][1] += conductor.years_of_experience
        r[conductor.orchestra_id - 1][2] += 1

    r = [(_[0], _[1]/_[2]) for _ in r]
    r.sort(key=lambda r: r[1])

    return r

def third_task():
    r = [(_.name, []) for _ in orchestras]
    connections = [(orchestras[connection.orchestra_id-1].name, conductors[connection.conductor_id-1].fio) for connection in many_to_many]
    for _ in connections: 
        for elm in r: 
            if elm[0] == _[0]:
                elm[1].append(_[1])
    to_be_del = []
    for i in range (len(r)): 
        if r[i][0][0] != "R":
            to_be_del.append(i)
    
    for i in range (len(to_be_del)): 
        del r[i]
    return r
         


def main():
    print(first_task())
    print(second_task())
    print(third_task())



if __name__ == '__main__':
    main()
