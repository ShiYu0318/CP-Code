M, N, k, r, c = map(int, input().split())

mp = []
for _ in range(M):
    mp.append(list(map(int, input().split())))

dir = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0]
]

d = 0
score = 0
cnt = 0

while mp[r][c] != 0:
    score += mp[r][c]
    mp[r][c] -= 1
    cnt += 1

    if score % k == 0:
        d = (d+1) % 4

    nr, nc = r + dir[d][0], c + dir[d][1]

    while not (0 <= nr < M and 0 <= nc < N) or mp[nr][nc] == -1:
        d = (d+1) % 4
        nr, nc = r + dir[d][0], c + dir[d][1]
    
    r, c = nr, nc

print(cnt)