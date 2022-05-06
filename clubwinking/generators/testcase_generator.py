import sys
import random
import string
from math import gcd, ceil
import random

def random_vec(n):
    return [random.randint(-100,100) for _ in range(n)]

def normalize(vec):
    gcd_val = gcd(*vec)
    return [at // gcd_val  for at in vec]

randomstring = lambda : "".join([random.choice(string.ascii_lowercase) for _ in range(random.randint(1, 10))])

n = int(sys.argv[1]) if len(sys.argv) > 1 and sys.argv[1] != "skip" else random.randint(1, 100)
t = int(sys.argv[2]) if len(sys.argv) > 2 and sys.argv[2] != "skip" else random.randint(1, 10**5)

print(n)
print(t)

rem_t = t

k = random.randint(1, t) if n > 1 else 1

colors = random.randint(1, 10)
color_names = [randomstring() for _ in range(colors)]
distrib = [0] + sorted(random.sample(range(1, t), k - 1)) + [t]
for i in range(k):
    am_points = distrib[i + 1] - distrib[i]
    vec_line = normalize(random_vec(n))
    for _ in range(am_points):
        ass_color = random.choice(color_names)
        scalar = random.randint(-100, 100)
        print( *[el * scalar for el in vec_line], end=" ")
        print(ass_color)



"""

total of t
k number of lines 

x > math.ceil((t - x) / (k - 1))

x > (t - x) / (k - 1)
(k - 1) * x > (t - x)
kx - x + x > t
kx > t
x > t/k


"""