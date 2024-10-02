def distributation(i, sum):
    if i == n:
        sums[sum] += 1
        return

    for j in range(1, m + 1):
        distributation(i + 1, sum + j)

n, m, k = map(int, input().split())

sums = [0 for _ in range(n * m + 1)]
distributation(0, 0)
sums.sort(reverse=True)

print(sum(sums[:k]) / (m ** n))
