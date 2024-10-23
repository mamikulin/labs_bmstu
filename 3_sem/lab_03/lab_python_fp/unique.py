class Unique(object):
    def __init__(self, items, **kwargs):
        self.items = items 
        self.index = 0
        d = []
        n = 1
        
        while n != None:
            n = self.__next__()
            id = self.index
            k = 1
            while k != None:

                k = self.__next__()
                if k != None:
                    if ((not kwargs and n == k) or (kwargs and str(n).lower() == str(k).lower())) and (self.index-1 not in d) :
                        d.append(self.index-1)
            self.index = id
  
        d = list(reversed(sorted(d)))
        for id in d: 
            del self.items[id]

        print(self.items)

    def __next__(self):
        
        if self.index >= len(self.items):
            pass
        else:
            self.index += 1
            return self.items[self.index - 1]

    def __iter__(self):
        return self

   
    
