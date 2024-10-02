def rec(keyboard):
    if len(keyboard) == len(keys):
        prev = notes[0]
        dist = 0
        for key in notes:
            dist += abs(keyboard[prev] - keyboard[key])
            prev = key
        return dist

    ans = 1e7
    for key in keys:
        if key in keyboard:
            continue

        ans = min(ans, rec(keyboard | {key: len(keyboard)}))

    return ans

notes = input()
keys = set(notes)
print(rec({}))

