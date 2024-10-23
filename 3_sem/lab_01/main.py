import argparse


def read():
    try:
        in_ = argparse.ArgumentParser()

        in_.add_argument("a", type=float, help="коэффициент при старшем члене")
        in_.add_argument("b", type=float, help="коэффициент при втором члене")
        in_.add_argument("c", type=float, help="свободный коэффициент")
        
        args = in_.parse_args()
        
        return {"a": args.a,"b": args.b,"c": args.c}

    except: 
        args = {
            "a": float(input("коэффициент при старшем члене: ")),
            "b": float(input("коэффициент при втором члене: ")), 
            "c": float(input("свободный коэффициент: "))
        }

        return args
    
def solve(args):
    r = []
    d = args["b"]**2 -  4 * args["a"] * args["c"]
    
    if d >= 0:
        ans_0 = (-args["b"] + d**0.5) / 2 * args["a"]
        ans_1 = (-args["b"] - d**0.5) / 2 * args["a"]

        r.append(ans_0)
        if ans_1 not in r:
            r.append(ans_1)
    
    return r 


def main():
    answer = solve(read())
    len_ = len(answer)
    
    if len_ == 0: 
        print("Нет корней")
    elif len_ == 1: 
        print("x1: {}, x2: {}".format(answer[0]))
    elif len_ == 2: 
        print("x1: {}, x2: {}".format(answer[0], answer[1]))

    
if __name__ == "__main__":
    main()