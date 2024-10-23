data = [4, -30, 100, -100, 123, 1, 0, -1, -4]

def sort():
    result = sorted(data, key = abs)
    print(result)
    
    result_with_lambda = sorted(data, key = lambda el: abs(el))
    print(result_with_lambda)