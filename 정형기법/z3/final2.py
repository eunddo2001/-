from z3 import *

s, e, n, d, m, o, r, y = Ints('s e n d m o r y')

p = Solver()

p.add([s>0, m>0])

p.add(s>=0, s<=9, e>=0, e<=9, n>=0, n<=9, d>=0, d<=9, m>=0, m<=9, o>=0, o<=9, r>=0, r<=9, y>=0, y<=9,)

p.add(Distinct(s, e, n, d, m, o, r, y))

p.add((s*1000 + e*100 + n*10 + d + m*1000 + o*100 + r*10 + e) == m*10000 + o*1000 + n*100 + e*10 + y)

p.check()
m = p.model()

for d in m.decls():
    print ("%s = %s" % (d.name(), m[d]))