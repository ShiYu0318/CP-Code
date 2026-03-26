import sys
import math
import matplotlib.pyplot as plt
import networkx as nx
from collections import deque
from matplotlib.widgets import Button
import matplotlib.patheffects as path_effects
import random

# =========================
# 讀入資料
# =========================
N, R, TTL = map(int, sys.stdin.readline().split())
points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
Q = int(sys.stdin.readline())
queries = [tuple(map(int, sys.stdin.readline().split())) for _ in range(Q)]
# queries 保持 1-based (op, A, B)

# ==================================================================================


# N = 1000;
# Q = 50;
# M = 1000;

# # 題目基本參數
# N = random.randint(N-100, N)  # 裝置數量
# R = random.randint(250, 300)     # 最遠可連接距離
# TTL = random.randint(7, 10)      # 最多跳數
# print(N, R, TTL)

# # 藍芽裝置座標
# points = []
# for _ in range(N):
#     x = random.randint(-M, M)
#     y = random.randint(-M, M)
#     points.append((x, y))
#     print(x, y)

# # 查詢次數
# Q = random.randint(Q-10, Q)
# print(Q)

# # 操作生成
# op_sub = 1  # 最大操作類型 (1=子題1, 2=子題2, 3=子題3)
# queries = []
# for _ in range(Q):
#     op = random.randint(1, 2) if op_sub == 3 else op_sub
#     a = random.randint(1, N)
#     b = random.randint(1, N)
#     while b == a:
#         b = random.randint(1, N)  # 避免 a == b
#     queries.append((op, a, b))
#     print(op, a, b)



#==================================================================================









# =========================
# DSU
# =========================
class DSU:
    def __init__(self, n):
        self.lead = list(range(n))
        self.sz = [1]*n

    def find(self, x):
        if self.lead[x] != x:
            self.lead[x] = self.find(self.lead[x])
        return self.lead[x]

    def join(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.sz[x] < self.sz[y]:
            x, y = y, x
        self.lead[y] = x
        self.sz[x] += self.sz[y]

# =========================
# 幫助函式
# =========================
def dist(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

def bfs_path_with_limits(start, target, R, TTL=float('inf')):
    """BFS，每一步距離 <= R，步數 <= TTL"""
    parent = [-1]*N
    dis = [-1]*N
    dis[start] = 0
    q = deque([start])
    while q:
        u = q.popleft()
        if dis[u] >= TTL:
            continue
        for v in range(N):
            if u == v:
                continue
            if dist(points[u], points[v]) <= R and dis[v]==-1:
                dis[v] = dis[u]+1
                parent[v] = u
                q.append(v)
                if v == target:
                    break
    if dis[target]==-1:
        return None
    path = []
    cur = target
    while cur != -1:
        path.append(cur)
        cur = parent[cur]
    path.reverse()
    return path

# =========================
# 建圖 & DSU
# =========================
G = nx.Graph()
for i in range(N):
    G.add_node(i, pos=points[i])

dsu = DSU(N)
adj = [[] for _ in range(N)]
for i in range(N):
    for j in range(i+1, N):
        if dist(points[i], points[j]) <= R:
            adj[i].append(j)
            adj[j].append(i)
            G.add_edge(i, j)
            dsu.join(i, j)

# 連通分量顏色
components = list(nx.connected_components(G))
comp_id = [-1]*N
for idx, comp in enumerate(components):
    for v in comp:
        comp_id[v] = idx
color_map = plt.cm.get_cmap("tab20", len(components))
max_degree = max(dict(G.degree()).values()) if N>0 else 1
def get_node_color(u):
    base_color = color_map(comp_id[u])
    deg = G.degree(u)
    alpha = 0.3 + 0.7*(deg/max_degree) if max_degree>0 else 1
    return (base_color[0], base_color[1], base_color[2], alpha)

pos = {i: points[i] for i in range(N)}
node_colors = [get_node_color(u) for u in G.nodes()]

# =========================
# 繪圖
# =========================
def draw_base(ax):
    ax.clear()
    nx.draw_networkx_edges(G, pos, edge_color="gray", alpha=0.5, width=0.8, ax=ax)
    nx.draw_networkx_nodes(G, pos, node_color=node_colors, node_size=150, ax=ax)
    for i, (x, y) in pos.items():
        ax.text(x, y, f"{i+1}", fontsize=8, ha="center", va="center", color="white", weight="bold")

def draw_path(ax, path, color="blue"):
    """繪製箭頭，每一步標示 步數:距離"""
    if not path:
        return
    L = len(path)-1
    for i in range(L):
        x1, y1 = points[path[i]]
        x2, y2 = points[path[i+1]]
        alpha = 0.3 + 0.7*((i+1)/L)
        ax.annotate("", xy=(x2, y2), xytext=(x1, y1),
                    arrowprops=dict(arrowstyle="->", color=color, lw=2, alpha=alpha))
        d = dist(points[path[i]], points[path[i+1]])
        txt = ax.text((x1+x2)/2, (y1+y2)/2, f"{i+1}:{d:.1f}", color=color, fontsize=9, weight="bold", ha="center")
        txt.set_path_effects([path_effects.Stroke(linewidth=2, foreground="white"), path_effects.Normal()])

# =========================
# 記錄查詢結果
# =========================
query_results = []
for op, A1, B1 in queries:
    a, b = A1-1, B1-1
    if op == 1:
        path = bfs_path_with_limits(a, b, R, TTL)
        if path:
            query_results.append(f"Yes, steps={len(path)-1}")
        else:
            # 計算不受 TTL 限制的最短步數
            full_path = bfs_path_with_limits(a, b, R, float('inf'))
            steps = len(full_path)-1 if full_path else -1
            query_results.append(f"No (steps={steps})")
    elif op == 2:
        if dsu.find(a) == dsu.find(b):
            query_results.append(f"Yes, component={dsu.sz[dsu.find(a)]}")
        else:
            query_results.append("No")

# =========================
# 放大函式
# =========================
def zoom_to_nodes(ax, nodes, extra_ratio=0.2):
    if not nodes:
        return
    xs = [points[i][0] for i in nodes]
    ys = [points[i][1] for i in nodes]
    min_x, max_x = min(xs), max(xs)
    min_y, max_y = min(ys), max(ys)
    dx = max(max_x - min_x, 1)
    dy = max(max_y - min_y, 1)
    margin_x = dx * extra_ratio
    margin_y = dy * extra_ratio
    ax.set_xlim(min_x - margin_x, max_x + margin_x)
    ax.set_ylim(min_y - margin_y, max_y + margin_y)

def zoom_full(ax, extra_ratio=0.05):
    xs = [p[0] for p in points]
    ys = [p[1] for p in points]
    min_x, max_x = min(xs), max(xs)
    min_y, max_y = min(ys), max(ys)
    dx = max(max_x - min_x, 1)
    dy = max(max_y - min_y, 1)
    margin_x = dx * extra_ratio
    margin_y = dy * extra_ratio
    ax.set_xlim(min_x - margin_x, max_x + margin_x)
    ax.set_ylim(min_y - margin_y, max_y + margin_y)

# =========================
# 更新函式
# =========================
step = 0
auto = False

def update():
    global step
    op, A1, B1 = queries[step]
    a, b = A1-1, B1-1
    draw_base(ax)
    result_text = ""
    zoom_nodes = [a, b]
    # 標示起點 A
    ax.scatter(points[a][0], points[a][1], s=300, edgecolors='yellow', facecolors='none', linewidths=2, zorder=5)
    ax.text(points[a][0], points[a][1]+0.5, f"A={A1}", fontsize=10, color="yellow", weight="bold", ha="center")

    # 標示終點 B
    ax.scatter(points[b][0], points[b][1], s=300, edgecolors='orange', facecolors='none', linewidths=2, zorder=5)
    ax.text(points[b][0], points[b][1]+0.5, f"B={B1}", fontsize=10, color="orange", weight="bold", ha="center")

    if op == 1:
        path = bfs_path_with_limits(a, b, R, TTL)
        if path is None:
            # 超過 TTL，畫完整路徑為紅色
            full_path = bfs_path_with_limits(a, b, R, float('inf'))
            if full_path:
                draw_path(ax, full_path, color="red")
                result_text = f"A={A1}→B={B1}: No (steps={len(full_path)-1})"
                zoom_nodes = full_path
            else:
                result_text = f"A={A1}→B={B1}: No"
        else:
            result_text = f"A={A1}→B={B1}: Yes (steps={len(path)-1})"
            draw_path(ax, path, color="blue")
            zoom_nodes = path
    elif op == 2:
        if dsu.find(a) == dsu.find(b):
            result_text = f"A={A1}↔B={B1}: Yes (component size={dsu.sz[dsu.find(a)]})"
            ax.plot([points[a][0], points[b][0]], [points[a][1], points[b][1]], color="green", linewidth=3, alpha=0.6)
        else:
            result_text = f"A={A1}↔B={B1}: No"
            ax.scatter([points[a][0], points[b][0]], [points[a][1], points[b][1]], color="red", s=300, marker="x", alpha=0.3)

    zoom_to_nodes(ax, zoom_nodes, extra_ratio=0.3)

    ax.set_title(f"Query {step+1}/{len(queries)}: {result_text}")
    fig.suptitle(f"N={N}, R={R}, TTL={TTL}", fontsize=14, weight="bold", color="blue", y=0.95)

    # 左側答案列表
    ax_answers.clear()
    ax_answers.axis('off')
    for idx, res in enumerate(query_results):
        color = "blue" if "Yes" in res else "red"
        weight = "bold" if idx==step else "normal"
        ax_answers.text(0, 1-idx*0.05, f"{idx+1}. {res}", color=color, fontsize=10, weight=weight, va='top')

    fig.canvas.draw_idle()

# =========================
# 按鈕事件
# =========================
def next_event(event=None):
    global step
    if step < len(queries)-1:
        step += 1
    update()

def prev_event(event=None):
    global step
    if step > 0:
        step -= 1
    update()

def auto_toggle(event=None):
    global auto
    auto = not auto

def fullmap_event(event=None):
    draw_base(ax)
    zoom_full(ax, extra_ratio=0.05)
    ax.set_title("Full Map")
    fig.canvas.draw_idle()

# =========================
# 建立圖形與按鈕
# =========================
fig, ax = plt.subplots(figsize=(12,12))
plt.subplots_adjust(left=0.3, bottom=0.2)

axprev = plt.axes([0.65, 0.05, 0.1, 0.075])
axnext = plt.axes([0.8, 0.05, 0.1, 0.075])
axauto = plt.axes([0.5, 0.05, 0.1, 0.075])
axfull = plt.axes([0.35, 0.05, 0.1, 0.075])

bprev = Button(axprev, "Prev")
bnext = Button(axnext, "Next")
bauto = Button(axauto, "Auto")
bfull = Button(axfull, "Full Map")

bprev.on_clicked(prev_event)
bnext.on_clicked(next_event)
bauto.on_clicked(auto_toggle)
bfull.on_clicked(fullmap_event)

# 左側顯示答案列表
ax_answers = fig.add_axes([0.02, 0.1, 0.25, 0.8], frameon=False)

# =========================
# 自動播放定時器
# =========================
def auto_loop():
    if auto:
        next_event()
    timer = fig.canvas.new_timer(interval=2000)
    timer.add_callback(auto_loop)
    timer.start()

update()
auto_loop()
plt.show()
