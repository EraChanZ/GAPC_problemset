#!/usr/bin/python3

def is_prime(x):
  d = 2
  while d * d <= x:
    if x % d == 0:
      return False
    d += 1
  return False if x == 1 else True

def is_prime_s(s):
  if (len(s) == 0):
    return True
  return False if s[0] == '0' else is_prime(int(s))

def is_good(s):
  if (len(s) == 0):
    return True
  return any([is_prime_s(s[:i]) & is_good(s[i:]) for i in range(1,len(s)+1)])
  
print("YES" if is_good(input()) else "NO")