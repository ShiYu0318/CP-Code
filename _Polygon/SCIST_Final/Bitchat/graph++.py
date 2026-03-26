import math
import random
import matplotlib.pyplot as plt
from collections import deque

# 參數設定
N = random.randint(100, 1000)    # 點數
R = random.randint(100, 300)    # 最大連接距離
T = random.randint(5, 15)       # TTL，畫圖用不到

K = random.randint(5, 10)        # 群集數

# 產生群集中心，彼此距離至少 3*R
cluster_centers = []
def dist_sq(p1, p2):
    return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2

while len(cluster_centers) < K:
    cx = random.randint(-1000, 1000)
    cy = random.randint(-1000, 1000)
    if all(dist_sq((cx, cy), c) >= (3*R)**2 for c in cluster_centers):
        cluster_centers.append((cx, cy))

# 平均分配每群集點數
cluster_sizes = [N // K] * K
for i in range(N % K):
    cluster_sizes[i] += 1

points = []
cluster_of_point = []

# 擴散生成點，類似 BFS
max_layers = 10
max_branch = 5

for c in range(K):
    need = cluster_sizes[c]
    q = deque()
    q.append(cluster_centers[c])
    points.append(cluster_centers[c])
    cluster_of_point.append(c)
    need -= 1

    layer = 0
    while need > 0 and q and layer < max_layers:
        sz = len(q)
        for _ in range(sz):
            if need <= 0:
                break
            cur = q.popleft()
            branches = random.randint(1, max_branch)
            for _ in range(branches):
                if need <= 0:
                    break
                angle = random.uniform(0, 2 * math.pi)
                dist = random.uniform(R/3, R)
                nx = int(cur[0] + dist * math.cos(angle))
                ny = int(cur[1] + dist * math.sin(angle))
                new_point = (nx, ny)
                points.append(new_point)
                cluster_of_point.append(c)
                q.append(new_point)
                need -= 1
        layer += 1

    # 補點在群集中心附近
    while need > 0:
        nx = cluster_centers[c][0] + random.randint(-R, R)
        ny = cluster_centers[c][1] + random.randint(-R, R)
        points.append((nx, ny))
        cluster_of_point.append(c)
        need -= 1

# 製造跨群集點（把某些群集的點移到別的群集附近，增加連通機率）
cross_edges = random.randint(K, 2 * K)
for _ in range(cross_edges):
    c1 = random.randint(0, K-1)
    c2 = (c1 + random.randint(1, K-1)) % K
    # 找 c1 群集最後一點移動
    for i in range(len(points)-1, -1, -1):
        if cluster_of_point[i] == c1:
            points[i] = (
                cluster_centers[c2][0] + random.randint(-R//2, R//2),
                cluster_centers[c2][1] + random.randint(-R//2, R//2)
            )
            break

# 畫圖
plt.figure(figsize=(12, 12))
colors = plt.cm.get_cmap('tab10', K)

def dist(p1, p2):
    return math.hypot(p1[0]-p2[0], p1[1]-p2[1])

N = len(points)
for i, (x, y) in enumerate(points):
    plt.scatter(x, y, color=colors(cluster_of_point[i]), s=40)
    plt.text(x+20, y+20, str(i+1), fontsize=6)

for i in range(N):
    for j in range(i+1, N):
        if dist(points[i], points[j]) <= R:
            plt.plot([points[i][0], points[j][0]], [points[i][1], points[j][1]], color=colors(cluster_of_point[i]), alpha=0.5, linewidth=0.7)

plt.title(f"Bluetooth network clusters (N={N}, R={R}, T={T}, K={K})")
plt.xlabel("X coordinate")
plt.ylabel("Y coordinate")
plt.grid(True)
plt.axis('equal')
plt.show()
