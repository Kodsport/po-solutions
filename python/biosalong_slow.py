n = int(input())
seats = input()

answer = 1000000000
for i in range(n):
    if seats[i] == '.':
        for j in range(i + 1, n):
            if seats[j] == '.':
                distance = j - i - 1
                if distance < answer:
                    answer = distance
                    
print(answer)
