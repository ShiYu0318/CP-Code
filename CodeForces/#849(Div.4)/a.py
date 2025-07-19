text = list("codeforces")
n = int(input())
ans = []
for i in range(n):
    x = input()
    if x in text:
        ans.append("YES")
    else:
        ans.append("NO")
for i in ans:
    print(i)