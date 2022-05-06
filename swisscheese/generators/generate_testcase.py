#!/usr/bin/python3
from genericpath import exists
import sys
import random
from copy import deepcopy
import math

def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)
def in_circle(a, b, r, x, y):
    return ((a - x) ** 2) + ((b - y) ** 2) <= (r ** 2)

def in_bounds(x, y, n, m):
    return x >= 0 and y >= 0 and x < n and y < m

random.seed(sys.argv[1])
n = int(sys.argv[2]) if len(sys.argv) > 2 else random.randint(5,1000)
m = int(sys.argv[3]) if len(sys.argv) > 3 else random.randint(5,1000)
cheese_type = sys.argv[5] if len(sys.argv) > 5 else "perfect"

cheese = [[1 for _ in range(n)] for _ in range(m)]

hole_count = random.randint(1, min(10, int(0.1 * n*m)) ) if len(sys.argv) <= 4 else int(sys.argv[4])
made_holes = 0
existant = []
tries = 0
while made_holes < hole_count:

    r = max(1, int( min(n, m) * random.randint(1, 30)/100 ) ) if len(sys.argv) <= 6 else int(sys.argv[6])
    ran_x = random.randint(r, n-1-r)
    ran_y = random.randint(r, m-1-r)
    
    f = False
    for t in range(len(existant)):
        if manhattan_distance(ran_x, ran_y, existant[t][0], existant[t][1]) < 1.5*(r + existant[t][2]):
            f = True
            break
    if f:
        tries += 1
        if tries > 20:
            break
        continue
    tries = 0
    normal_count = 0
    broken_count = random.randint(1, int(2 * math.pi * r))
    for i in range(ran_x - r, ran_x + r + 1):
        for j in range(ran_y - r, ran_y + r + 1):
            cur_in_circle = ((ran_x - i) ** 2 + (ran_y - j) ** 2) <= (r ** 2)
            if cheese_type != "perfect" and normal_count < broken_count:
                normal_count += 1
                for shift in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                    if in_bounds(i + shift[0], j + shift[1], n, m) and in_circle(ran_x, ran_y, r, i + shift[0], j + shift[1]) and not cur_in_circle:
                        cheese[j][i] = 0
            if cur_in_circle:
                cheese[j][i] = 0
    existant.append((ran_x, ran_y, r))
    made_holes += 1

print(n, m)
print( "\n".join(list(map(lambda a: " ".join(list(map(str, a))), cheese))) )