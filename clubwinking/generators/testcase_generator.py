#!/usr/bin/python3

import sys
import random
import string
from math import gcd, ceil
import random
import time

def random_vec(n):
    return [random.randint(-point_range, point_range) for _ in range(n)]

subtract_vecs = lambda vec1, vec2, n: tuple(vec1[i] - vec2[i] for i in range(n))

def normalize_vec(vec, n):
    for i in range(len(vec)):
        if abs(vec[i]):
            sign = vec[i] // abs(vec[i])
            break
    
    gcdd = gcd(*vec)
    return tuple((vec[i] // gcdd) * sign for i in range(n))

def solve(n, t, points, toprint=True):
    max_count = 0
    max_color_count = 0
    max_set = None
    count_notunique = 0
    for i in range(t):
        hashmap = {}
        for j in range(i + 1, t):
            r = normalize_vec(subtract_vecs(points[i][:n], points[j][:n], n), n)
            if r not in hashmap:
                hashmap[r] = [2, set([points[i][n], points[j][n]]), 1 + int(points[i][n] != points[j][n]), set([i, j]), 2 ]
            else:
                hashmap[r][0] += 1
                hashmap[r][1].add(points[i][n])
                hashmap[r][1].add(points[j][n])
                hashmap[r][2] = len(hashmap[r][1])
                hashmap[r][3].add(i)
                hashmap[r][3].add(j)
                hashmap[r][4] = len(hashmap[r][3])

        for value in hashmap.values():
            if value[2] == max_color_count and value[0] == max_count:
                count_notunique += 1
            if (value[2] > max_color_count) or ( (value[2] == max_color_count) and (value[0] > max_count) ):
                max_set = value[3]
                max_color_count = value[2]
                max_count = value[0]
                count_notunique = 0

    if toprint:
        print( max_count )
        print(  *list(map(str, sorted(list(max_set)) )), sep="\n" )

    return count_notunique == 0

randomstring = lambda : "".join([random.choice(string.ascii_lowercase) for _ in range(random.randint(1, 10))])

ran_seed = int(sys.argv[1]) if len(sys.argv) > 1 else time.time()
random.seed(ran_seed)
n = int(sys.argv[2]) if len(sys.argv) > 2 and sys.argv[1] != "skip" else random.randint(1, 100)
t = int(sys.argv[3]) if len(sys.argv) > 3 and sys.argv[2] != "skip" else random.randint(1, 10**5)
point_range = int(sys.argv[4]) if len(sys.argv) > 4 else 100000
scalar_range = int(sys.argv[5]) if len(sys.argv) > 5 else 100000

rem_t = t
while True:
    k = random.randint(1, t) if n > 1 else 1
    colors = random.randint(1, 10)
    color_names = [randomstring() for _ in range(colors)]
    distrib = [0] + sorted(random.sample(range(1, t), k - 1)) + [t]
    pts = {}
    for i in range(k):
        am_points = distrib[i + 1] - distrib[i]
        vec_line = normalize_vec(random_vec(n), n)
        for _ in range(am_points):
            ass_color = random.choice(color_names)
            scalar = random.randint(-scalar_range, scalar_range)
            while tuple([el * scalar for el in vec_line]) in pts:
                scalar = random.randint(-scalar_range, scalar_range)
            pts[tuple([el * scalar for el in vec_line])] = ass_color
    pts = list(pts.items())
    pts = [ tuple(list(pts[i][0]) + [pts[i][1]]) for i in range(t)]
    if solve(n, t, pts, toprint = False):
        break

print(n)
print(t)
random.shuffle(pts)
for p in pts:
    print( *list(p) )



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