import random
import math
import matplotlib.pyplot as plt

# 參數設定
N = random.randint(100, 1000)   # 裝置數量 (為方便畫圖可調整)
R = random.randint(100, 300)   # 最大連接距離
T = random.randint(5, 15)      # 最多跳數（這裡沒用，只輸出）

print(f"{N} {R} {T}")

# 產生 K 個群集中心，彼此距離至少 2*R
K = random.randint(5, 10)
cluster_centers = []

def dist_sq(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

while len(cluster_centers) < K:
    cx = random.randint(-10000, 10000)
    cy = random.randint(-10000, 10000)
    valid = True
    for c in cluster_centers:
        if dist_sq((cx, cy), c) < (2*R)**2:
            valid = False
            break
    if valid:
        cluster_centers.append((cx, cy))

# 分配每個群集點數
cluster_sizes = [0] * K
for _ in range(N):
    cluster_sizes[random.randint(0, K-1)] += 1

# 產生點，群集內均勻散布於中心附近 (±R)
points = []
cluster_of_point = []  # 紀錄每點屬於哪個群集，方便上色
for i, (cx, cy) in enumerate(cluster_centers):
    for _ in range(cluster_sizes[i]):
        x = cx + random.randint(-R, R)
        y = cy + random.randint(-R, R)
        points.append((x, y))
        cluster_of_point.append(i)

# 印出輸入格式
for x, y in points:
    print(f"{x} {y}")

Q = random.randint(20, 30)
print(Q)

op_max = 3
queries = []
for _ in range(Q):
    op = random.randint(1, op_max)
    a = random.randint(1, N)
    b = random.randint(1, N)
    while a == b:
        b = random.randint(1, N)
    queries.append((op, a, b))
    print(f"{op} {a} {b}")

# 繪圖
plt.figure(figsize=(12, 12))

colors = plt.cm.get_cmap('tab10', K)

for i, (x, y) in enumerate(points):
    plt.scatter(x, y, color=colors(cluster_of_point[i]), s=40)
    plt.text(x + 50, y + 50, str(i + 1), fontsize=6)

# 繪製距離 ≤ R 的連線
def distance(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

for i in range(N):
    for j in range(i + 1, N):
        if distance(points[i], points[j]) <= R:
            x1, y1 = points[i]
            x2, y2 = points[j]
            c = colors(cluster_of_point[i])
            plt.plot([x1, x2], [y1, y2], color=c, linewidth=0.7, alpha=0.5)

plt.title(f"Bluetooth Clusters (N={N}, R={R}, T={T}, K={K})")
plt.xlabel("X coordinate")
plt.ylabel("Y coordinate")
plt.grid(True)
plt.axis('equal')
plt.show()
