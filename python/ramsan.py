words, n = map(int, input().split())

people = list(range(1, n + 1))
position = 0
for i in range(n-1):
    position = (position + words - 1) % len(people);
    people.pop(position)

print(people[0])
