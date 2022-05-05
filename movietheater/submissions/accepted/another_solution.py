#!/usr/bin/python3

n, m = map(int, input().split())
a = [input() for i in range(n)]
dx = [1, -1,  0, 0]
dy = [0,  0, -1, 1]
 
def bfs(q, n, m):
	d = { p:0 for p in q }
	iq = 0
	while iq < len(q):
		x, y = q[iq]
		for nx, ny in [(x + dx[i], y + dy[i]) for i in range(4)]:
			if nx < 0 or ny < 0 or nx >= n or ny >= m or (nx, ny) in d:
				continue
			d[(nx, ny)] = d[(x,y)] + 1
			q.append((nx, ny))
		iq += 1
	return d
 
def collect(a, n, m, c):
	return [(i,j) for j in range(m) for i in range(n) if a[i][j] == c]
 
qX = collect(a,n,m,'X')
dX = bfs(qX, n, m)
qE = collect(a,n,m,'E')
dE = bfs(qE, n, m)
print(min([dX[p] + dE[p] for p in collect(a,n,m,'S')]))
