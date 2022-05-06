#!/usr/bin/python3

import sys
import random
import string
from math import gcd
import time

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
ran_seed = int(sys.argv[1]) if len(sys.argv) >= 2 else time.time()
random.seed(ran_seed)
n = int(sys.argv[2]) if len(sys.argv) >= 3 else random.randint(1, 50)
t = int(sys.argv[3]) if len(sys.argv) >= 4 else random.randint(1, 10**3)
point_value_range = int(sys.argv[4]) if len(sys.argv) >= 5 else 1000
n_colors = int(sys.argv[5]) if len(sys.argv) >= 6 else random.randint(1, 10)

def gen_testcase(n, t, point_value_range, n_colors, toprint=True):
    allstrings = [randomstring() for _ in range(n_colors)]
    points = {}

    for i in range(t):
        p = tuple([random.randint(-point_value_range, point_value_range) for _ in range(n)])
        while p in points:
            p = tuple([random.randint(-point_value_range, point_value_range) for _ in range(n)])
        points[p] = random.choice(allstrings)
    points_items = list(points.items())
    return list(map(lambda x: tuple(list(x[0]) + [x[1]]), points_items))

cur_points = gen_testcase(n, t, point_value_range, n_colors)
sol_out = solve(n, t, cur_points, toprint=False)
while not sol_out:
    cur_points = gen_testcase(n, t, point_value_range, n_colors)
    sol_out = solve(n, t, cur_points, toprint=False)

print(n)
print(t)
print( *list(map(lambda x: " ".join(list(map(str, x))), cur_points)), sep="\n" )