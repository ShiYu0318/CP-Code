#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, R, T;
    cin >> N >> R >> T;

    vector< pair<int, int> > pos(N);
    for(int i=0; i < N; ++i) cin >> pos[i].first >> pos[i].second;

    // 建邊
    vector< vector<int> > adj(N);
    for(int i=0; i < N; ++i) 
    {
        for(int j=i + 1; j < N; ++j) 
        {
            int dx = pos[i].first - pos[j].first;
            int dy = pos[i].second - pos[j].second;
            if(dx * dx + dy * dy <= R * R) 
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int Q; cin >> Q;
    while(Q--)
    {
        int op, A, B; cin >> op >> A >> B; --A; --B;
        if(op == 1)     // BFS
        {
            vector<int> dis(N, -1); dis[A] = 0;
            queue<int> q; q.push(A);
            while(!q.empty()) 
            {
                int u = q.front(); q.pop();
                if(dis[u] >= T) continue; // 跳數限制
                for(int v : adj[u]) 
                {
                    if(dis[v] == -1) 
                    {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
            }
            if(dis[B] == -1) cout << "No\n";
            else cout << "Yes " << dis[B] << '\n';
        }
    }
}
