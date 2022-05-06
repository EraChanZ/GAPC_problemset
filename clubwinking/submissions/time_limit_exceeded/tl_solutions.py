#!/usr/bin/python3
from math import gcd
from functools import reduce

n = int(input())
t = int(input())

points = []
subtract_vecs = lambda vec1, vec2: [vec1[i] - vec2[i] for i in range(n)]
compare_vecs = lambda vec1, vec2: reduce(lambda x, y: x and y, [vec1[i] == vec2[i] for i in range(n)])

def normalize_vec(vec):
    for i in range(len(vec)):
        if abs(vec[i]):
            sign = vec[i] // abs(vec[i])
            break
    gcdd = gcd(*vec)
    return tuple((vec[i] // gcdd) * sign for i in range(n))

for _ in range(t):
    line = input().split(" ")
    line = [int(line[i]) if i < n else line[i] for i in range(n + 1)]
    points.append(line)


maxcount = 0
maxcolorcount = 0
indexes = set()

for i in range(t):
    for j in range(i + 1, t):
        colorset = set([points[i][n], points[j][n] ])
        curcount = 2
        curindexes = set([i, j])
        for k in range(t):
            if k != i and k != j:
                vec1 = normalize_vec(subtract_vecs(points[i], points[j] ))
                vec2 = normalize_vec(subtract_vecs(points[i], points[k]))
                if compare_vecs(vec1, vec2):
                    colorset.add( points[k][n] )
                    curindexes.add( k )
                    curcount += 1

        if len(colorset) > maxcolorcount or ( (len(colorset) == maxcolorcount) and (curcount > curcount)):
            maxcount = curcount
            maxcolorcount = len(colorset)
            indexes = curindexes

print( len(indexes) )        
print( *sorted(list(indexes)), sep="\n")