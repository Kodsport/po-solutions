def rec(keyboard):
    if len(keyboard) == len(keys):
        prev = stycket[0]
        dist = 0
        for key in stycket:
            dist += abs(keyboard[prev] - keyboard[key])
            prev = key
        return dist

    ans = 1e7
    for key in keys:
        if key in keyboard:
            continue

        ans = min(ans, rec(keyboard | {key: len(keyboard)}))

    return ans

stycket = input()
keys = set(stycket)
print(rec({}))

