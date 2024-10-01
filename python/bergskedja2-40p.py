def rec(r, c, used):
    global grid, mi, ma

    if c == n:
        c = 0
        r += 1

    if r == m:
        allowed = True
        for a in range(n):
            for b in range(m):
                smaller = 0
                if a != 0 and grid[a-1][b] < grid[a][b]:
                    smaller += 1
                if b != 0 and grid[a][b-1] < grid[a][b]:
                    smaller += 1
                if a != n-1 and grid[a+1][b] < grid[a][b]:
                    smaller += 1
                if b != m-1 and grid[a][b+1] < grid[a][b]:
                    smaller += 1

                if smaller != neighbours[a][b]:
                    allowed = False
                    break

        if allowed:
            mi = min(mi, grid[0][0])
            ma = max(ma, grid[0][0])

        return

    for i in range(1, n*m+1):
        if i in used:
            continue
        grid[c][r] = i
        rec(r, c + 1, used + [i])

n, m = map(int, input().split())
neighbours = []
for i in range(n):
    neighbours.append(list(map(int, list(input()))))
grid = [[-100 for _ in range(m)] for _ in range(n)]

mi, ma = 1e5, -1e5
rec(0, 0, [])
print(mi, ma)
