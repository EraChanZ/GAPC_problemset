from genericpath import exists
import sys
import random
from copy import deepcopy

def manhattan_distance(x1, y1, x2, y2):
    return abs(x1 - x2) + abs(y1 - y2)

n = int(sys.argv[1])
m = int(sys.argv[2])

cheese = [[1 for _ in range(n)] for _ in range(m)]

hole_count = random.randint(1, min(10, int(0.1 * n*m)) ) if len(sys.argv) <= 3 else int(sys.argv[3])
made_holes = 0
existant = []
tries = 0
while made_holes < hole_count:

    r = max(1, int( min(n, m) * random.randint(1, 30)/100 ) ) if len(sys.argv) <= 4 else int(sys.argv[4])
    ran_x = random.randint(r, n-1-r)
    ran_y = random.randint(r, m-1-r)
    
    f = False
    for t in range(len(existant)):
        if manhattan_distance(ran_x, ran_y, existant[t][0], existant[t][1]) < (r + existant[t][2]):
            f = True
            break
    if f:
        tries += 1
        if tries > 20:
            break
        continue
    tries = 0
    for i in range(n):
        for j in range(m):
            if ((ran_x - i) ** 2 + (ran_y - j) ** 2) <= (r ** 2):
                cheese[j][i] = 0
    existant.append((ran_x, ran_y, r))
    made_holes += 1

print(n, m)
print( "\n".join(list(map(lambda a: " ".join(list(map(str, a))), cheese))) )