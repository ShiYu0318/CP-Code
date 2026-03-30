n = int(input())
h = list(map(int,input().split(' ')))
ans = 0
for i in range(n):
    if h[i] == 0:
        if i == 0:
            ans += h[i+1]
        elif i == n-1:
            ans += h[n-2]
        else:
            ans += min(h[i-1],h[i+1])
print(ans)