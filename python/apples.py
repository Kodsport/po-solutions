def count(x, y, visited_count):
    global visited

    if x < 0 or n <= x:
        return 0
    if visited[y][x]:
        return 0
    if visited_count == k:
        return 0

    visited[y][x] = True
    apples = grid[y][x] + max(count(x+1, y, visited_count+1),
                              count(x-1, y, visited_count+1),
                              count(x, 1-y, visited_count+1))
    visited[y][x] = False

    return apples

n, k = map(int, input().split())
north = list(map(int, input().split()))
south = list(map(int, input().split()))

grid = [north, south]
visited = [[False for _ in range(n)],
           [False for _ in range(n)]]

print(count(0, 1, 0))
