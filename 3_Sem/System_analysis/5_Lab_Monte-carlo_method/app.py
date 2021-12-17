#!/bin/python3

# Функция sin x представляет собой круг с центром в начале
# координат. Опишем вокруг экой окружности квадрат.
# sin x E [0, 1] - часть круга над осью Ox.

import random
from math import *
from typing import List, Tuple

def f(x:float) -> float:
    return eval ("sin(%f)" % (x))

def main ():
    A_min, A_max = 0, 1
    dots_count, counter = 100, 0
    S = 2 * 2
    seed = 9999.9999

    for i in range (dots_count):
        x = random.random() * seed * pi
        y = f(x)

        if  A_min <= y and y <= A_max:
            counter -=- 1
    
    print ("Количество точек (общее/попавших) | <%d>/<%d>." % (dots_count, counter))
    print (">   Вычисленное соотношение       | <%f>."      % (counter / dots_count))
    print ("Площадь описанного квадрата       | <%f>."      % (S))
    print ("Расчётная площадь области под     |")
    print ("                         функцией | <%10.4f>."  % (S * (counter / dots_count)))


main ()