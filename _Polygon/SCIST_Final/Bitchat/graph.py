import random
import math
import matplotlib.pyplot as plt

# 設定參數
N = random.randint(10, 100)     # 裝置數量，為了方便畫圖先用小一點
R = random.randint(300, 500)    # 最遠可連接距離
T = random.randint(10, 15)      # 最多跳數
Q = random.randint(20, 50)      # 查詢數量
op_max = 3                      # 最大操作類型（可調整為 1~3）

print(f"{N} {R} {T}")

# 產生裝置座標
points = []
for _ in range(N):
    x = random.randint(-1000, 1000)
    y = random.randint(-1000, 1000)
    points.append((x, y))
    print(f"{x} {y}")

print(Q)
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
plt.figure(figsize=(10, 10))
for i, (x, y) in enumerate(points):
    plt.scatter(x, y, color='blue')
    plt.text(x + 5, y + 5, str(i + 1), fontsize=8)

# 畫出距離在 R 以內的連線
def distance(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

for i in range(N):
    for j in range(i + 1, N):
        if distance(points[i], points[j]) <= R:
            x1, y1 = points[i]
            x2, y2 = points[j]
            plt.plot([x1, x2], [y1, y2], color='gray', linewidth=0.5)

plt.title(f"N={N}, R={R}, T={T}")
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.axis("equal")
plt.show()
