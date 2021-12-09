from sympy.abc import x
import sympy as sp
import numpy as np

def lagrange_interpolation(t, y):
    n = len(t)
    L = 0
    for i in range(n):
        l = y[i]
        for j in range(n):
            if i == j:
                continue
            else:
                l *= (x - t[j])/(t[i] - t[j])
        L += l

    return sp.simplify(L)


def split(inte, n):
    a, b = inte
    t = np.linspace(a, b, n+1)
    return t


def f(t):
  return 0.5 * t**2


def draw_polinomial(inte, func, lst):
    fig = sp.plot(func(x), (x, -5, 5), line_color='r', label='Original Fuction', legend=True, show=False)
    i = 0
    colors = ['b', 'y', 'g', 'r']
    for n in lst:
        t = split(inte, n)
        y = lagrange_interpolation(t, func(t))
        print(f"The {n}-order interpolation polinomial is {y}")
        color = colors[i]
        i += 1
        p = sp.plot(y, (x, -5, 5), line_color=color, label=f'n={n}', lengend=True, show=False)
        fig.extend(p)


def piecewise_linear_interpolation(t, y):
    n = len(t)
    L = []
    for i in range(n-1):
        l = lagrange_interpolation(t[i:i+2], y[i:i+2])
        L.append((sp.simplify(l), sp.And(x >= t[i], x <= t[i+1])))

    return sp.Piecewise(*L)


def draw_piecewise(inte, func, lst):
    fig = sp.plot(func(x), (x, -5, 5), line_color='r', label='Original Fuction', legend=True, show=False)
    i = 0
    colors = ['b', 'y', 'g', 'r']

    for n in lst:
        t = split(inte, n)
        y = piecewise_linear_interpolation(t, func(t))
        color = colors[i]
        i += 1
        p = sp.plot(y, (x, -5, 5), line_color=color, label=f'n={n}', lengend=True, show=False)
        fig.extend(p)
    fig.save('piecewise_interpolation.png')


if __name__ == '__main__':
    interval = [-5, 5]
    n_list = [5, 6, 7, 8]
    draw_polinomial(interval, f, n_list)
    draw_piecewise(interval, f, n_list)