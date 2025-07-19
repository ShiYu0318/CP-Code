#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
long long A[MAXN];
vector<int> graph[MAXN];
bool visited[MAXN];

struct Node {
    int id;
    long long beauty;
    Node(int i, long long b) : id(i), beauty(b) {}
    bool operator<(const Node& other) const {
        return beauty > other.beauty;
    }
};

void dfs(int u, vector<int>& leaves) {
    visited[u] = true;
    bool isLeaf = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, leaves);
            isLeaf = false;
        }
    }
    if (isLeaf) leaves.push_back(u);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    priority_queue<Node> pq;
    for (int i = 1; i <= N; i++) {
        pq.push(Node(i, A[i]));
    }

    vector<pair<int, int>> result;
    vector<int> leaves;

    // 找到美丽指数最大的部件作为起始点
    int start = pq.top().id;
    pq.pop();

    dfs(start, leaves);

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (!visited[node.id]) {
            int leaf = leaves.back();
            leaves.pop_back();

            result.push_back({leaf, node.id});
            graph[leaf].push_back(node.id);
            graph[node.id].push_back(leaf);

            vector<int> new_leaves;
            dfs(node.id, new_leaves);
            leaves.insert(leaves.end(), new_leaves.begin(), new_leaves.end());
        }
    }

    for (auto& edge : result) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}