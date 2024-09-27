n = int(input())

lines = [input() for _ in range(n)]

# lines[::-1] vänder på listan
lines = lines[::-1]

for line in lines:
    print(line)

