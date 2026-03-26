import sys
import math
import matplotlib.pyplot as plt
import networkx as nx
from collections import deque

# =========================
# 讀取輸入
# =========================
# N = 節點數量
# R = 通訊半徑，若兩點距離 <= R 則連邊
# TTL = 傳輸的最大跳數
N, R, TTL = map(int, sys.stdin.readline().split())

# 節點座標
points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]

# 查詢數量
Q = int(sys.stdin.readline())

# queries = (op, A, B)
# op=1 → BFS+TTL 找路徑
# op=2 → 判斷是否在同一個聯盟(connected component)
queries = [tuple(sys.stdin.readline().split()) for _ in range(Q)]
for i in range(Q):
    queries[i] = (int(queries[i][0]), int(queries[i][1])-1, int(queries[i][2])-1)  # 轉為 0-based index

# =========================
# 幫助函式：計算兩點的歐式距離
# =========================
def dist(p1, p2):
    return math.hypot(p1[0] - p2[0], p1[1] - p2[1])

# =========================
# 建立圖 G
# =========================
G = nx.Graph()
for i in range(N):
    G.add_node(i, pos=points[i])  # 加入節點，並存座標資訊

# 若距離 <= R，則加無向邊
for i in range(N):
    for j in range(i+1, N):
        if dist(points[i], points[j]) <= R:
            G.add_edge(i, j)

# =========================
# 找聯盟（Connected Components）
# =========================
components = list(nx.connected_components(G))   # 每個 component 是一個 set
comp_id = [-1]*N                                # comp_id[i] = 第 i 個節點所屬聯盟編號
for idx, comp in enumerate(components):
    for v in comp:
        comp_id[v] = idx

# =========================
# 設定節點顏色：依據聯盟分類 + 節點度數調整深淺
# =========================
max_degree = max(dict(G.degree()).values()) if N > 0 else 1

# tab20 調色盤 → 最多 20 個聯盟色系
color_map = plt.cm.get_cmap('tab20', len(components))

def get_node_color(u):
    base_color = color_map(comp_id[u])  # 基礎顏色取決於聯盟
    deg = G.degree(u)
    # 節點度數越大 → 顏色越深
    alpha = 0.3 + 0.7 * (deg / max_degree) if max_degree > 0 else 1
    return (base_color[0], base_color[1], base_color[2], alpha)

# =========================
# 開始繪圖
# =========================
plt.figure(figsize=(14, 14))
ax = plt.gca()
pos = {i: points[i] for i in range(N)}

# 畫邊（灰色）
nx.draw_networkx_edges(G, pos, edge_color='gray', alpha=0.5, width=0.8)

# 畫節點（顏色依聯盟+度數調整）
node_colors = [get_node_color(u) for u in G.nodes()]
nx.draw_networkx_nodes(G, pos, node_color=node_colors, node_size=150)

# 節點標號（編號從 1 開始）
for i, (x, y) in enumerate(points):
    plt.text(x+10, y+10, str(i+1), fontsize=8)

# =========================
# BFS with TTL
# =========================
def bfs_path_with_ttl(graph, start, target, ttl):
    dist = [-1]*N     # 記錄距離
    parent = [-1]*N   # 用於重建路徑
    dist[start] = 0
    q = deque([start])

    while q:
        u = q.popleft()
        if dist[u] >= ttl:   # 超過 TTL 停止擴展
            continue
        if u == target:      # 找到目標即可跳出
            break
        for v in graph.neighbors(u):
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                parent[v] = u
                q.append(v)

    # 若目標不可達
    if dist[target] == -1:
        # 找到距離最遠的可達點 (作為 fallback)
        max_dist = max([d for d in dist if d != -1], default=-1)
        farthest = dist.index(max_dist) if max_dist != -1 else start
        return None, dist, farthest
    else:
        # 重建路徑
        path = []
        cur = target
        while cur != -1:
            path.append(cur)
            cur = parent[cur]
        path.reverse()
        return path, dist, target

# =========================
# 處理查詢
# =========================
for idx, (op, a, b) in enumerate(queries, 1):
    plt.title(f"Query {idx}: op={op}, A={a+1}, B={b+1}")

    if op == 1:
        # BFS + TTL 路徑查詢
        path, dist, endpoint = bfs_path_with_ttl(G, a, b, TTL)
        if path is None:
            print(f"Query {idx}: No path from {a+1} to {b+1} within TTL {TTL}.")
            # 畫一個 a → 最遠可達點 的箭頭
            ax.annotate("",
                xy=points[endpoint], xycoords='data',
                xytext=points[a], textcoords='data',
                arrowprops=dict(arrowstyle="->", color='red', lw=2, alpha=0.7))
            plt.text(points[endpoint][0], points[endpoint][1]+50, "Farthest reachable", color='red')
            plt.text(points[a][0], points[a][1]+50, "Start", color='red')
        else:
            print(f"Query {idx}: Path found with length {len(path)-1}.")
            # 畫出路徑上的箭頭
            for i in range(len(path)-1):
                start_pt = points[path[i]]
                end_pt = points[path[i+1]]
                ax.annotate("",
                    xy=end_pt, xycoords='data',
                    xytext=start_pt, textcoords='data',
                    arrowprops=dict(arrowstyle="->", color='red', lw=2))
            # 標示起點和終點
            plt.text(points[a][0], points[a][1]+50, "Start", color='red')
            plt.text(points[b][0], points[b][1]+50, "End", color='red')

    elif op == 2:
        # 判斷是否同聯盟（DSU概念）
        if comp_id[a] == comp_id[b]:
            print(f"Query {idx}: YES, same alliance.")
            # 粗線標示 A-B
            plt.plot([points[a][0], points[b][0]], [points[a][1], points[b][1]], color='green', linewidth=3, alpha=0.6)
            plt.scatter([points[a][0], points[b][0]], [points[a][1], points[b][1]], color='green', s=300, marker='o', alpha=0.3)
            plt.text(points[a][0], points[a][1]-50, f"A({a+1})", color='green')
            plt.text(points[b][0], points[b][1]-50, f"B({b+1})", color='green')
        else:
            print(f"Query {idx}: NO, different alliance.")
            # 標示 A、B 為紅色
            plt.scatter([points[a][0], points[b][0]], [points[a][1], points[b][1]], color='red', s=300, marker='x', alpha=0.3)
            plt.text(points[a][0], points[a][1]-50, f"A({a+1})", color='red')
            plt.text(points[b][0], points[b][1]-50, f"B({b+1})", color='red')

    # =========================
    # 每個查詢後 → 暫停顯示，再清空畫布，重新畫基礎圖
    # =========================
    plt.pause(1.5)
    ax.clear()

    nx.draw_networkx_edges(G, pos, edge_color='gray', alpha=0.5, width=0.8, ax=ax)
    nx.draw_networkx_nodes(G, pos, node_color=node_colors, node_size=150, ax=ax)
    for i, (x, y) in enumerate(points):
        plt.text(x+10, y+10, str(i+1), fontsize=8)

# =========================
# 最後顯示圖形
# =========================
plt.show()
