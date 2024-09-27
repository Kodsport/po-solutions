n, k, h = map(int, input().split())
dist_m = list(map(int, input().split()))

p = 0
for dist in dist_m[::-1]: # Gå igenom avstånden baklänges
    extra_dist = max(dist * h - p * (k - 1), 0)
    # Här adderar vi täljaren med nämnaren - 1 för att göra om floor (//) till
    # ceil. Alltså avrunda uppåt istället för nedåt.
    p += (extra_dist + k - 1) // k

print(p)
