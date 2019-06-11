from functions import mysin
import numpy as np
import pytest

#max_tolerance = 1.0e-15
max_tolerance = 1.0e-14

def cos_1(x):
    # input 0 < x <= pi
    return mysin(np.pi - x)

def cos_2(x):
    cos = np.sqrt(1 - min(np.power(mysin(x), 2), 1.0))
    if x <= np.pi/2:
        return cos
    else:
        return -cos

@pytest.mark.parametrize('test_input',
    np.radians(np.linspace(0, 60, 100, endpoint=False)).tolist())
def test_sin3theta(test_input):
    rad = test_input
    res = abs((3 * mysin(rad) - 4 * (mysin(rad)** 3)) - mysin(3 * rad))
    assert res < max_tolerance


@pytest.mark.parametrize('test_input',
    np.radians(np.linspace(0.0001, 180, 100, endpoint=False)).tolist())
def test_symentric_rule_against_y_axis(test_input):
    rad = test_input
    res = abs(mysin(np.pi - rad) - mysin(rad))
    assert res < max_tolerance


def random_range(a, b):
    return (b - a) * np.random.rand() + a


def generate_alpha_beta(num=100):
    ret = list()
    idx = 0
    while num > idx:
        try:
            alpha = random_range(0, np.pi)
            print
            assert 0 < alpha
            beta = random_range(0, alpha)
            assert 0 < beta

            assert 0 < alpha + beta
            assert alpha + beta < np.pi
            ret.append((alpha, beta))
            idx +=1
        except:
            import traceback
            print(traceback.format_exc())

    return ret

@pytest.mark.parametrize('test_input',
                         generate_alpha_beta(10))
def test_addition_theorem_1(test_input):
    x, y = test_input
    res = abs(mysin(x + y) - (mysin(x)*cos_2(y) + cos_2(x)*mysin(y)))
    assert res < max_tolerance

@pytest.mark.parametrize('test_input',
                         generate_alpha_beta(10))
def test_addition_theorem_2(test_input):
    x, y = test_input
    res = abs(cos_2(x + y) - (cos_2(x)*cos_2(y) - mysin(x)*mysin(y)))
    assert res < max_tolerance
