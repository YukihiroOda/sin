#!/usr/bin/env python3

from functions import sin, vec_sin, mysin
import math
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def main():
    df = pd.DataFrame(columns=['deg', 'rad', 'numpy', 'approx', 'res'])
    # 0 <= x < pi
    rad_values = [math.radians(deg) for deg in range(0, 180, 10)]
    mysin = vec_sin()
    for rad in rad_values:
#        my_sin = sin(rad)
        my_sin = mysin(rad)
        ori_sin = math.sin(rad)
        res = abs(my_sin - ori_sin)
        tmp_element = pd.Series([math.degrees(rad), rad, ori_sin, my_sin, res],
                                index=df.columns)
        df = df.append(tmp_element, ignore_index=True)
#        print(math.degrees(rad), rad, my_sin, ori_sin, res)
#    print(sin(0))
#    print(sin(math.pi/6))
#    print(sin(math.pi/2))
    print(df)

def numpy_main():
    df = pd.DataFrame(columns=['deg', 'rad', 'res_10', 'res_100', 'res_1000'])

    # 0 <= x < pi
    x = np.linspace(0, np.pi, 1001)
    mysin = vec_sin()

    ori_sin = np.sin(x)
    res_10 = abs(mysin(x, 10) - ori_sin)
    res_100 = abs(mysin(x, 100) - ori_sin)
    res_1000 = abs(mysin(x, 1000) - ori_sin)
    df['sin_10'] = mysin(x, 10)
    df['sin_100'] = mysin(x, 100)
    df['sin_1000'] = mysin(x, 1000)
#    res_10 = mysin(x, 10)
#    res_100 = mysin(x, 100)
#    res_1000 = mysin(x, 1000)
    df['deg'] = pd.Series(np.degrees(x))
    df['rad'] = pd.Series(x)
    df['res_10'] = pd.Series(res_10)
    df['res_100'] = pd.Series(res_100)
    df['res_1000'] = pd.Series(res_1000)
    print(df)
#    df.plot(x='rad', y=['res_10', 'res_100', 'res_1000'])
#    df.plot(x='rad', y=['res_100', 'res_1000'])
    df['res_100'] = df[['res_100']].rolling(12).mean()
    df['res_1000'] = df[['res_1000']].rolling(12).mean()
    df.plot(x='rad', y=['res_100', 'res_1000'])
#    import scipy
#    from scipy.interpolate import interp1d
#    plt.plot(np.degrees(x), res_10, label='res 10')
#    plt.plot(np.degrees(x), res_100, label='res 100')
#    plt.plot(np.degrees(x), res_1000, label='res 1000')
    plt.legend()
    plt.xlabel('degrees')
    plt.ylabel('Residual Error')
    plt.show()

def kyopro_style():
    num = int(input())
    rad_list = [float(input()) for i in range(num)]
    for rad in rad_list:
        print(mysin(rad, order=100))

if __name__ == '__main__':
#    numpy_main()
    kyopro_style()
