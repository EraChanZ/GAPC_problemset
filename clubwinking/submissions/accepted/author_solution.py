from math import gcd

n = int(input())
t = int(input())

points = []
hashmap = {}

subtract_vecs = lambda vec1, vec2: tuple(vec1[i] - vec2[i] for i in range(n))

def normalize_vec(vec):
    sign = vec[0] // abs(vec[0])
    gcdd = gcd(*list(vec))
    return tuple((vec[i] // gcdd) * sign for i in range(n))

for _ in range(t):
    line = input().split(" ")
    line = [int(line[i]) if i < n else line[i] for i in range(n + 1)]
    points.append(tuple(line))

for i in range(t):
    for j in range(i+1, t):
        r = normalize_vec(subtract_vecs(points[i][:n], points[j][:n]))
        if r not in hashmap:
            hashmap[r] = [1, set([points[i][n], points[j][n]]), 1 + int(points[i][n] != points[j][n]), set([i, j]), 2 ]
        else:
            hashmap[r][0] += 1
            hashmap[r][1].add(points[i][n])
            hashmap[r][1].add(points[j][n])
            hashmap[r][2] = len(hashmap[r][1])
            hashmap[r][3].add(i)
            hashmap[r][3].add(j)
            hashmap[r][4] = len(hashmap[r][3])

hashmap_values = hashmap.values()
hashmap_values = max(hashmap_values, key=lambda x: (x[2], x[0]), reverse=True)
print( hashmap_values[0][2] )
print(  *list(map(str, list(hashmap_values[0][1]))), sep="\n" )