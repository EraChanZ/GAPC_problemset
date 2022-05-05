#!/usr/bin/python3

p = input()
has_upper = any([c.isupper() for c in p])
has_digit = any([c.isdigit() for c in p])
has_lower = any([c.islower() for c in p])
if 8 <= len(p) <= 16 and has_upper and has_digit and has_lower:
  print("YES")
elif 7 <= len(p) <= 15 and sum([has_upper, has_digit, has_lower]) >= 2:
  print("YES")
else:
  print("NO")