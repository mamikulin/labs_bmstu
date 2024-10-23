import time
from contextlib import contextmanager


class cm_timer_1:
    def __enter__(self):
        self.stat = time.time()
    

    def __exit__(self, exc_type, exc_value, exc_traceback):
        self.working = time.time() - self.stat
        print(f"time: {self.working}")
    
@contextmanager
def cm_timer_2():
    start = time.time()
    yield
    working = time.time() - start
    print(f"time: {working}")


with cm_timer_1():
    time.sleep(5.5)

with cm_timer_2():
    time.sleep(5.5)