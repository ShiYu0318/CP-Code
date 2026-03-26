#include <bits/stdc++.h>
using namespace std;

struct DSU 
{
    vector<int> lead, sz;

    DSU(int n): lead(n), sz(n, 1) { iota(lead.begin(), lead.end(), 0); }

    int find(int x) { return x == lead[x] ? x : find(lead[x]); } // 無路徑壓縮
    
    void join(int x, int y) 
    {
        x = find(x);  y = find(y);
        if (x == y) return;
        // if (sz[x] < sz[y]) swap(x, y); // 無啟發式合併
        lead[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    int N, R, T;
    cin >> N >> R >> T;

    vector< pair<int, int> > pos(N);
    for(int i=0; i < N; ++i) cin >> pos[i].first >> pos[i].second;

    DSU dsu(N);

    // 建立網路區塊聯盟
    for(int i=0; i < N; ++i) 
    {
        for(int j=i + 1; j < N; ++j) 
        {
            int dx = pos[i].first - pos[j].first;
            int dy = pos[i].second - pos[j].second;
            if(dx * dx + dy * dy <= R * R) dsu.join(i, j);  // 加入共享區塊
        }
    }

    int Q; cin >> Q;
    while(Q--)
    {
        int op, A, B; cin >> op >> A >> B; --A; --B;
        if(op == 2)     // DSU
        {
            if(dsu.find(A) == dsu.find(B)) cout << "Yes " << dsu.sz[dsu.find(A)] << '\n';
            else cout << "No\n";
        }
    }
}
