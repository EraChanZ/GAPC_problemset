#!/usr/bin/python3

import math
def tarea(x, r):
  return math.fabs(x*x*math.sin(r*math.pi/180)*math.cos(r*math.pi/180))
w, h, r = map(int, input().split())
print(tarea(w,r) + tarea(h, r + 90))