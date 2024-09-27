n = int(input())
seats = input()

answer = 1000000000
closest_seat = -100000000
for i in range(n):
    if seats[i] == '.':
        distance = i - closest_seat - 1
        if distance < answer:
            answer = distance
        closest_seat = i
        
print(answer)
