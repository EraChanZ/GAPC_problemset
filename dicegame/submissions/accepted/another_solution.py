#!/usr/bin/python3

n, m = map(int, input().split())
q = ((m - 1) / m)**n
x = 1 / (1 - q) / m
for i in range(n):
    print(x)
    x *= (m - 1) / m
