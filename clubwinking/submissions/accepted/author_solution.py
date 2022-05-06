#!/usr/bin/python3

from math import gcd

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
    colortoind = {}
    count_notunique = 0
    for i in range(t):
        hashmap = {}
        for j in range(i + 1, t):
            r = normalize_vec(subtract_vecs(points[i][:n], points[j][:n], n), n)
            if points[i][n] not in colortoind:
                colortoind[points[i][n]] = len(colortoind)
            if points[j][n] not in colortoind:
                colortoind[points[j][n]] = len(colortoind)  

            if r not in hashmap:
                hashmap[r] = [2, set([ colortoind[points[i][n]], colortoind[points[j][n]] ]), 1 + int( colortoind[points[i][n]] != colortoind[points[j][n]] ), set([i, j]), 2 ]
            else:
                hashmap[r][0] += 1
                hashmap[r][1].add(colortoind[points[i][n]])
                hashmap[r][1].add(colortoind[points[j][n]])
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

if __name__ == "__main__":
    n = int(input())
    t = int(input())

    points = []
    for _ in range(t):
        line = input().split(" ")
        line = [int(line[i]) if i < n else line[i] for i in range(n + 1)]
        points.append(tuple(line))

    solve(n, t, points)