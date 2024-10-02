# Insikt: vi vill aldrig gå åt vänster, bara upp/ner/höger
def count(r, c, visited_row, visited_count):
    if r < 0 or r >= 2 or c >= n:
        return 0
    if visited_count == k:
        return 0

    # Vi kan alltid gå åt höger
    best_from_here = count(r, c+1, 0, visited_count+1)
    # Vi kan inte gå upp, ner och sen upp igen. För att förbjuda
    # detta håller vi koll på om vi besökt den andra på den här raden
    if visited_row == 0:
        best_from_here = max(best_from_here, count(1-r, c, 1, visited_count+1))
    apples = grid[r][c] + best_from_here
    return apples
n, k = map(int, input().split())
north = list(map(int, input().split()))
south = list(map(int, input().split()))
grid = [north, south]

print(count(1, 0, 0, 0))
