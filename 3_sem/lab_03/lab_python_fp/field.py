def field(items, *args):
    assert len(args) > 0
    r = []
    for item in items: 
        s = {
        }
        
        for cat in item: 
            if cat in args: 
                if len(args) > 1:
                    s[cat] = item[cat]
                else:
                    r.append(item[cat])
        if s:
            r.append(s)

    return r
 