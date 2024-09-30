import math

n = int(input())

ans = 0
for a in range(1, n+1):
    # Notera att vi börjar från a, vi vill inte dubbelräkna
    for b in range(a, n+1):
        c = math.sqrt(a ** 2 + b ** 2 - a * b)
        if c.is_integer() and 1 <= c and c <= n:
            ans += 1

print(ans)
