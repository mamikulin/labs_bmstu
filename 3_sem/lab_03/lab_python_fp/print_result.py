def print_result(func):
    def wrapper(*args, **kwargs):
        print(func.__name__) 
        result = func(*args, **kwargs)
        if type(result) == dict: 
            for elm in result:
                print(f"{elm} = {result[elm]}")
        elif type(result) == list:
            for elm in result:
                print(f"{elm}")
        else:
            print(result)
        
        return result
    return wrapper

@print_result
def test_1():
    return 1


@print_result
def test_2():
    return 'iu5'


@print_result
def test_3():
    return {'a': 1, 'b': 2}


@print_result
def test_4():
    return [1, 2]


if __name__ == '__main__':
    print('!!!!!!!!')
    test_1()
    test_2()
    test_3()
    test_4()


# test_1
# 1
# test_2
# iu5
# test_3
# a = 1
# b = 2
# test_4
# 1
# 2