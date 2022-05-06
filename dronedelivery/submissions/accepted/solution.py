#!/usr/bin/python3
n = int(input())
a = list(map(int, input().split(" ")))
prefix = [a[0]]
suffix = [a[n - 1]]
for i in range(1, n):
    prefix.append(prefix[-1] + a[i])
    suffix.append(suffix[-1] + a[n - i - 1])
A = sum([a[i] * i for i in range(n)])
minind = 1
minA = A
for i in range(n-1):
    A = A + prefix[i] - suffix[n - i - 2]
    if A < minA:
        minA = A
        minind = i + 2
print(minind)