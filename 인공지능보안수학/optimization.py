import numpy as np

S0 = np.array([[1.2], [1.2]])
S1 = np.array([[-1.2], [1]])

tol = 1e-12
max_iter = 50000
a0 = 1.0
p = 0.5
c1 = 1e-4
max_ls_iter = max_iter/4

def func(x):
    return 100*(x[1][0]-x[0][0]**2)**2 + (1-x[0][0])**2

def gradient(x):
    return np.array([[-400*(x[1][0]-x[0][0]**2)*x[0][0] - 2*(1-x[0][0])], [200*(x[1][0] - x[0][0]**2)]])

def Hessian(x):
    return np.array([[-400*(x[1][0]-3*x[0][0]**2)+2, -400*x[0][0]], [-400*x[0][0], 200]])

def norm(x):
    return np.linalg.norm(x, 2)

def minimize(x0, direction, f):
    k = 0
    xk = x0
    f.write(f'x0: f={func(xk):e}, gnorm={norm(gradient(xk)):e}\n')
    while k < max_iter:
        grad_xk = gradient(xk)
        hess_xk = Hessian(xk)
        gnorm_grad_xk = norm(grad_xk)
        if gnorm_grad_xk < tol:
            break
        pk = {'GD': -grad_xk, 'NT': -np.linalg.inv(hess_xk).dot(grad_xk)}[direction]
        ak = BacktrackingLS(xk, pk)
        xk = xk + ak*pk
        f.write(f'Iteration {k}: alp={ak:e}, f={func(xk):e}, gnorm={norm(gradient(xk)):e}\n')
        k = k+1
    return xk

def BacktrackingLS(xk, pk):
    a = a0
    ls_iter = 0
    func_xk = func(xk)
    grad_func_xk = c1*np.dot(gradient(xk).T, pk)
    while ls_iter < max_ls_iter:
        if func(xk + a*pk) <= func_xk + a*grad_func_xk:
            break
        a = p*a
        ls_iter = ls_iter + 1
    return a

f1 = open('GD_S0.txt', 'w')
minimize(S0, 'GD', f1)
f1.close()

f2 = open('GD_S1.txt', 'w')
minimize(S1, 'GD', f2)
f2.close()

f3 = open('NT_S0.txt', 'w')
minimize(S0, 'NT', f3)
f3.close()

f4 = open('NT_S1.txt', 'w')
minimize(S1, 'NT', f4)
f4.close()