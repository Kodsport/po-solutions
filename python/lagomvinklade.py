n = int(input())

ans = 0
for a in range(1, n+1):
    # Notera att vi börjar från a, vi vill inte dubbelräkna
    for b in range(a, n+1):
        for c in range(1, n+1):
            if c ** 2 == a ** 2 + b ** 2 - a * b:
                ans += 1

print(ans)
