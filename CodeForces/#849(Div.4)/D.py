n = int(input())
for i in range(n):
    c = int(input())
    s = list(input())
    ns = []
    ans = len(set(s))
    for j in range(c):
        ns.append(s[0])
        s.pop(0)
        nl = len(set(s)) + len(set(ns))
        if nl > ans:
            ans = nl
    print(ans)