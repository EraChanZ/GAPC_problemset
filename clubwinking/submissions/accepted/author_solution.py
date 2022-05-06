from math import gcd

n = int(input())
t = int(input())

points = []

max_count = 0
max_color_count = 0
max_set = None

subtract_vecs = lambda vec1, vec2: tuple(vec1[i] - vec2[i] for i in range(n))

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
    points.append(tuple(line))
for i in range(t):
    hashmap = {}
    for j in range(i + 1, t):
        r = normalize_vec(subtract_vecs(points[i][:n], points[j][:n]))
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
            print("mul answers")
        if (value[2] > max_color_count) or ( (value[2] == max_color_count) and (value[0] > max_count) ):
            max_set = value[3]
            max_color_count = value[2]
            max_count = value[0]



print( max_count )
print(  *list(map(str, sorted(list(max_set)) )), sep="\n" )