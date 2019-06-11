import math
from itertools import *
import numpy as np


def take(n, iterable):
    "Return first n items of the iterable as a list"
    return list(islice(iterable, n))

def facts():
    x = 1
    for n in count(1):
        yield x
        x *= n

def skip_even(xs):
    b = False
    for x in xs:
        if b:
            yield x
            b = False
        else:
            b = True

def signs():
    while True:
        yield 1
        yield -1

def x_n(x):
    x_n = float(1)
    while True:
        yield x_n
        x_n *= x


def sin(x, n=10):
    return sum(take(n, map(lambda s, a, b: s * a / b,
                           signs(),
                           skip_even(x_n(x)),
                           skip_even(facts()))))

def mysin(x, order=100, strict=True):
    if strict:
        assert 0 <= x
        assert x < np.pi

    a = x
    s = a
    for i in range(1, order):
        a *= -1 * x**2 / ((2 * i) * (2 * i + 1))
        s += a
    return s

def vec_sin():
    return np.vectorize(mysin, excluded=['order'])
