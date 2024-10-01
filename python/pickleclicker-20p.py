best_time = 1e7
def rec(pickles, pps, time):
    global best_time

    pickles += pps
    time += 1
    if best_time <= time:
        return
    if t <= pickles:
        best_time = time
        return

    rec(pickles, pps, time)

    for p, c in buildings:
        if c <= pickles:
            rec(pickles - c, pps + p, time)

n, t = map(int, input().split())
buildings = []
for i in range(n):
    p, c = map(int, input().split())
    buildings.append((p, c))

rec(0, buildings[0][0], 0)
print(best_time)
