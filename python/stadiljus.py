n, x, y = map(int, [input() for _ in range(3)])

lamps = list(map(int, input().split()))
lamps.sort()

total, count = 0, 0
for i in range(n):
    new_total = total + x * lamps[i]
    # Nedan vill vi i vänsterledet beräkna ceil(new_total / (count + 1)), men
    # vi vill helst inte behöva jobba med icke-heltal. Därför gör vi ett litet
    # smart knep. I täljaren (new_total) adderar vi nämnaren - 1 (alltså
    # count + 1 - 1 = count). Divisionen av heltal (//) avrundar nedåt.
    # Tillsammans ger det vårt eftersökta värde utan att någonsin använda oss
    # av icke-heltal
    if (new_total + count) // (count + 1) <= y:
        total += x * lamps[i]
        count += 1
    else:
        break

print(count)
