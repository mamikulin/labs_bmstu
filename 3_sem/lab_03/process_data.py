import json
import sys
# Сделаем другие необходимые импорты
from lab_python_fp.print_result import print_result
from lab_python_fp.field import field
from lab_python_fp.gen_random import gen_random
from lab_python_fp.cm_timer import cm_timer_1

path = None

path = "lab_python_fp/db/data_light.json"
# Необходимо в переменную path сохранить путь к файлу, который был передан при запуске сценария

with open(path) as f:
    data = json.load(f)


# Далее необходимо реализовать все функции по заданию, заменив `raise NotImplemented`
# Предполагается, что функции f1, f2, f3 будут реализованы в одну строку
# В реализации функции f4 может быть до 3 строк

@print_result
def f1(arg):
    print(type(sorted(set(field(arg, "job-name"))) ))
    return sorted(set(field(arg, "job-name")))

@print_result
def f2(arg):
    return list(filter(lambda el: el.lower().startswith("программист"), arg))

@print_result
def f3(arg):
    return list(map(lambda el: el + " c опытом Python", arg))

@print_result
def f4(arg):
    sal = gen_random(len(arg), 100_000, 200_000)
    return ["{}, зарплата {}".format(job, sal) for job, sal in zip(arg, sal) ]

if __name__ == '__main__':
    with cm_timer_1():
        f4(f3(f2(f1(data))))