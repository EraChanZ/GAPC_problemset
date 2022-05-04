n, m = map(int, input().split(" "))

M = [list(map(int, input().split(" "))) for _ in range(m)]
visited = [[0 for _ in range(n)] for _ in range(m)]

def in_circle(a, b, r, x, y):
    return ((a - x) ** 2) + ((b - y) ** 2) <= (r ** 2)

def in_bounds(x, y, n, m):
    return x >= 0 and y >= 0 and x < n and y < m

def is_perfect(c_x, c_y, r):
    for i in range(c_x - r - 1, c_x + r + 2):
        for j in range(c_y - r - 1, c_y + r + 2):
            if not in_bounds(i, j, n, m):
                continue
            cur_in_circle = in_circle(c_x, c_y, r, i, j)
            for shift in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                if in_bounds(i + shift[0], j + shift[1], n, m) and in_circle(c_x, c_y, r, i + shift[0], j + shift[1]) and not cur_in_circle:
                    if not M[j][i]:
                        return False
            if cur_in_circle and M[j][i]:
                return False
    return True

def recognize(x, y):
    global visited
    minx = x
    miny = y
    maxx = x
    maxy = y
    cur_x = x
    cur_y = y
    while cur_y < m and not M[cur_y][x]:
        while cur_x >= 0 and not M[cur_y][cur_x]:
            visited[cur_y][cur_x] = 1
            cur_x -= 1
        cur_x += 1
        minx = min(minx, cur_x)
        cur_x = x
        while cur_x < n and not M[cur_y][cur_x]:
            visited[cur_y][cur_x] = 1
            cur_x += 1
        cur_x -= 1
        maxx = max(maxx, cur_x)
        cur_x = x

        maxy = cur_y
        cur_y += 1
    x_width = maxx - minx
    y_width = maxy - miny
    if x_width != y_width:
        return None
    if x_width % 2:
        return None
    radius = x_width // 2
    if radius < 1:
        return False
    return (minx + radius, miny + radius, radius) if is_perfect(minx + radius, miny + radius, radius) else None

holes = []
f = False
for j in range(m):
    for i in range(n):
        if visited[j][i]:
            continue
        if not M[j][i]:
            data = recognize(i, j)
            if not data:
                f = True
                break
            holes.append(data)
    if f:
        break
print("normal" if f else "perfect")
if not f:
    print(len(holes))
    print( "\n".join( list(map(lambda x: str(x[0]) + " " + str(x[1]) + " " + str(x[2]) , holes) ) ) )
    
