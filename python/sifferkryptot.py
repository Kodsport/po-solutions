def combinations(i):
    if i == len(crypto):
        return 1
    if crypto[i] == '0':
        return 0

    ans = combinations(i + 1)
    if i + 1 < len(crypto) and crypto[i] in ['1', '2']:
        ans += combinations(i + 2)

    return ans

crypto = input()
print(combinations(0))
