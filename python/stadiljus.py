#!/usr/bin/env python3

n, x, y = map(int, [input() for _ in range(3)])

lamps = list(map(int, input().split()))
lamps.sort()

acc, count = 0, 0
for i in range(n):
    acc += x * lamps[i]
    count += 1

    if y < (acc + count - 1) // count:
        count -= 1
        break

print(count)
