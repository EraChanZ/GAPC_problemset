#!/usr/bin/python3

n, m, k = map(int, input().split())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
 
def can(d, a, b, k):
	take = [a[::-1], b[::-1]]
	turn = 0
	last = int(-2e9)
	for x in range(2 * k - 1):
		while take[turn] and take[turn][-1] < last:
			take[turn].pop()
		if not take[turn]:
			return False
		last = take[turn][-1] + d
		take[turn].pop()
		turn ^= 1
	return True
 
l = int(0)
r = int(1e9)
while l <= r:
	mid = int((l + r) / 2)
	if can(mid, a, b, k):
		l = mid + 1
	else:
		r = mid - 1
 
print(r)