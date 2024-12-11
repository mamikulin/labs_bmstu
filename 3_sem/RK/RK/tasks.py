def first_task(conductors, orchestras):
    r = [(
    conductor.fio, orchestra.name)
    for conductor in conductors 
        for orchestra in orchestras 
            if (conductor.orchestra_id == orchestra.id)
                and (conductor.fio[-2:] == "ни")]

    return r

def second_task(conductors, orchestras):
    r = [[_.name, 0, 0] for _ in orchestras]
    for conductor in conductors:
        r[conductor.orchestra_id - 1][1] += conductor.years_of_experience
        r[conductor.orchestra_id - 1][2] += 1

    r = [(_[0], _[1]/_[2]) for _ in r]
    r.sort(key=lambda r: r[1])

    return r

def third_task(conductors, orchestras, many_to_many):
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
    
    to_be_del.reverse()
    for i in to_be_del: 
        del r[i]
    return r

if __name__ == '__main__':
    main()
