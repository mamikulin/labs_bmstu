import datetime

def gen_random(num_count, begin, end):
    r = []
    for i in range(num_count):
        
        now = str(datetime.datetime.now())
        rnd = float(now[::-1][:3:])/1000
        rnd = int(begin + rnd*(end-begin))

        if  rnd + begin <= end:
            r.append(int(rnd) + begin)
        else:
            r.append(int(rnd))

    return r
