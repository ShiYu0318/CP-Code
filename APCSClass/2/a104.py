n = int(input())
t = 1
sum = 0
for _ in range(n):
    sum += t**2
    t *= 2
print(sum)