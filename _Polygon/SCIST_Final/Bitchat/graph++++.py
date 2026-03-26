import sys
import math
import matplotlib.pyplot as plt
import networkx as nx
from collections import deque
from matplotlib.widgets import Button
import matplotlib.patheffects as path_effects

# =========================
# 讀入輸入資料
# =========================
N, R, TTL = map(int, sys.stdin.readline().split())
points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
Q = int(sys.stdin.readline())
queries = [tuple(map(int, sys.stdin.readline().split())) for _ in range(Q)]
# ⚠️ queries 保持 1-based，不再 -1
# (op, A, B)

# =========================
# 幫助函式
# =========================
def dist(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

# BFS with TTL (0-based index)
def bfs_path_with_ttl(graph, start, target, ttl):
    dist_arr = [-1] * N
    parent = [-1] * N
    dist_arr[start] = 0
    q = deque([start])
    while q:
        u = q.popleft()
        if dist_arr[u] >= ttl:
            continue
        if u == target:
            break
        for v in graph.neighbors(u):
            if dist_arr[v] == -1:
                dist_arr[v] = dist_arr[u] + 1
                parent[v] = u
                q.append(v)

    if dist_arr[target] == -1:
        max_dist = max([d for d in dist_arr if d != -1], default=-1)
        farthest = dist_arr.index(max_dist) if max_dist != -1 else start
        return None, dist_arr, farthest
    else:
        path = []
        cur = target
        while cur != -1:
            path.append(cur)
            cur = parent[cur]
        path.reverse()
        return path, dist_arr, target

# =========================
# 建立圖
# =========================
G = nx.Graph()
for i in range(N):
    G.add_node(i, pos=points[i])

for i in range(N):
    for j in range(i + 1, N):
        if dist(points[i], points[j]) <= R:
            G.add_edge(i, j)

# 找聯盟 (connected components)
components = list(nx.connected_components(G))
comp_id = [-1] * N
for idx, comp in enumerate(components):
    for v in comp:
        comp_id[v] = idx

# 配色：tab20
color_map = plt.cm.get_cmap("tab20", len(components))
max_degree = max(dict(G.degree()).values()) if N > 0 else 1

def get_node_color(u):
    base_color = color_map(comp_id[u])
    deg = G.degree(u)
    alpha = 0.3 + 0.7 * (deg / max_degree) if max_degree > 0 else 1
    return (base_color[0], base_color[1], base_color[2], alpha)

pos = {i: points[i] for i in range(N)}
node_colors = [get_node_color(u) for u in G.nodes()]

# =========================
# 繪圖函式
# =========================
def draw_base(ax):
    ax.clear()
    nx.draw_networkx_edges(G, pos, edge_color="gray", alpha=0.5, width=0.8, ax=ax)
    nx.draw_networkx_nodes(G, pos, node_color=node_colors, node_size=150, ax=ax)
    # 節點標號 (1-based)
    for i, (x, y) in pos.items():
        ax.text(x, y, f"{i+1}", fontsize=8, ha="center", va="center", color="white", weight="bold")

def draw_path(ax, path):
    L = len(path) - 1
    for i in range(L):
        x1, y1 = points[path[i]]
        x2, y2 = points[path[i + 1]]
        alpha = 0.3 + 0.7 * ((i + 1) / L)  # 後面的箭頭更深
        ax.annotate(
            "",
            xy=(x2, y2),
            xytext=(x1, y1),
            arrowprops=dict(arrowstyle="->", color=(1, 0, 0, alpha), lw=2),
        )
        d = math.hypot(x2 - x1, y2 - y1)
        # 更顯眼的距離標籤
        txt = ax.text((x1 + x2) / 2, (y1 + y2) / 2, f"{d:.1f}", color="red", fontsize=9, weight="bold")
        txt.set_path_effects([path_effects.Stroke(linewidth=2, foreground="white"), path_effects.Normal()])

# =========================
# 查詢處理 + UI 控制
# =========================
fig, ax = plt.subplots(figsize=(12, 12))
plt.subplots_adjust(bottom=0.2)

step = 0
auto = False

def update():
    global step
    op, a1, b1 = queries[step]  # ⚠️ 這裡是 1-based
    a, b = a1 - 1, b1 - 1       # 轉 0-based 給演算法用
    draw_base(ax)
    if op == 1:
        path, _, endpoint = bfs_path_with_ttl(G, a, b, TTL)
        if path is None:
            ax.annotate(
                "",
                xy=points[endpoint],
                xytext=points[a],
                arrowprops=dict(arrowstyle="->", color="red", lw=2, alpha=0.7),
            )
        else:
            draw_path(ax, path)
    elif op == 2:
        if comp_id[a] == comp_id[b]:
            ax.plot(
                [points[a][0], points[b][0]],
                [points[a][1], points[b][1]],
                color="green",
                linewidth=3,
                alpha=0.6,
            )
        else:
            ax.scatter(
                [points[a][0], points[b][0]],
                [points[a][1], points[b][1]],
                color="red",
                s=300,
                marker="x",
                alpha=0.3,
            )
    # 主標題：查詢資訊 (顯示 1-based)
    ax.set_title(f"Query {step+1}/{len(queries)}: op={op}, A={a1}, B={b1}")
    # 上方額外文字：N, R, TTL
    fig.suptitle(f"N={N}, R={R}, TTL={TTL}", fontsize=14, weight="bold", color="blue", y=0.95)
    fig.canvas.draw_idle()

def next_event(event=None):
    global step
    if step < len(queries) - 1:
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

# 按鈕
axprev = plt.axes([0.3, 0.05, 0.1, 0.075])
axnext = plt.axes([0.6, 0.05, 0.1, 0.075])
axauto = plt.axes([0.45, 0.05, 0.1, 0.075])
bnext = Button(axnext, "Next")
bprev = Button(axprev, "Prev")
bauto = Button(axauto, "Auto")
bnext.on_clicked(next_event)
bprev.on_clicked(prev_event)
bauto.on_clicked(auto_toggle)

# 自動播放 loop
def loop(event):
    if auto:
        next_event()
    fig.canvas.new_timer(interval=2000, callbacks=[(loop, [None])]).start()

# 啟動
update()
loop(None)
plt.show()
