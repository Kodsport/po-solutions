n = int(input())

lines = [input() for _ in range(n)]

for line in lines[::-1]:
    print(line)

