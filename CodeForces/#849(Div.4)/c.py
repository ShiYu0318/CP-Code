n = int(input())
def change(s):
    if len(s) == 0:
        return 0
    elif s[0] != s[-1]:
        s.pop(0)
        s.pop(-1)
        return change(s)
    else:
        return len(s)
for i in range(n):
    c = int(input())
    s = list(input())
    print(change(s))
