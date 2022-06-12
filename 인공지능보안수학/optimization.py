import numpy as np

sp1 = np.array[1.2, 1.2]
sp2 = np.array[-1.2, 1]

def func(x):
    return 100(x[1]-x[0]^2)^2 + (1-x[0])^2

def gradient(x):
    return [[-400(x[1]-x[0]^2)*x[0] - 2(1-x[0])], [200(x[1] - x[0]^2)]]

def Hessian(x):
    return [[-400([x[1]-3*x[0]^2])+2, -400*x[0]], [-400*x[0], 200]]

def minimization(x0, func):
    k = 0
    x[k] = x[0]
    while k < max.iter


def BacktrackingLS():
