def combinations(i):
    if i == len(crypt):
        return 1
    if crypt[i] == '0':
        return 0

    ans = combinations(i + 1)
    if i + 1 < len(crypt) and crypt[i] in ['1', '2']:
        ans += combinations(i + 2)

    return ans

crypt = input()
print(combinations(0))
