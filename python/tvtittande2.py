n, k = map(int, input().split())
lens = list(map(int, input().split()))

timestamps = []
acc = 0
for i in range(n):
    line = map(int, input().split())
    d, c = next(line), next(line)

    for movie in line:
        # Notera att lens är 0-indexerad medan movie är 1-indexerad
        acc += lens[movie-1]

        # När vi har sett en film behöver vi inte se den igen
        lens[movie-1] = 0

    timestamps.append((d, acc))

last_party, watch_time = 0, 0
for day, stamp in timestamps:
    watch_time += 10 * (day - last_party)
    if watch_time < stamp:
        print('Nej')
        exit()
    # Bob kan inte titta på film när han är på kalas
    last_party = day + 1

print('Ja')
