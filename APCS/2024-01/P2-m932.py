m,n,k = map(int,input().split())
g = []
for i in range (m):
    ro = input()
    g.append(ro)
a = list(map(int,input().split()))
r = m - 1
c = 0
an = ""

# 建表
dir = [
    [-1, 0], # 0
    [0, 1],  # 1
    [1, 1],  # 2
    [1, 0],  # 3
    [0, -1], # 4
    [-1, -1] # 5
]

for ac in a:
    nr = r + dir[ac][0]
    nc = c + dir[ac][1]
    # if ac == 0:
    #     nr = r - 1
    #     nc = c
    # if ac == 1:
    #     nr = r
    #     nc = c + 1
    # if ac == 2:
    #     nr = r + 1
    #     nc = c + 1
    # if ac == 3:
    #     nr = r + 1
    #     nc = c
    # if ac == 4:
    #     nr = r
    #     nc = c - 1
    # if ac == 5:
    #     nr = r - 1
    #     nc = c - 1
    if 0 <= nr < m and 0<= nc < n:
        r = nr
        c = nc
    an += g[r][c]

print(an)
print(len(set(an)))