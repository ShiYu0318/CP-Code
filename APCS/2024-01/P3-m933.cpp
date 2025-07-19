#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define EB emplace_back
#define F pre[t][0]
#define S pre[t][1]
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)

// 拓墣排序 + DP（類似）

signed main()
{
    ShiYu;

    // 輸入閘資料、邏輯閘類別
    int p,q,r,m,n,a,b,t, now = 0, mx = 0;
    cin >> p >> q >> r >> m; n = p+q+r;
    vi data(n+1), gate(n+1), delay(n+1,0), indeg(n+1,0), topo;
    RPT(i,p) cin >> data[i+1];
    FOR(i,p+1,p+q+1) cin >> gate[i];

    // 輸入連接線 記錄入度
    vector<vi> pre(n+1), nxt(n+1);
    RPT(i,m)
    {
        cin >> a >> b;
        ++indeg[b];
        pre[b].EB(a);
        nxt[a].EB(b);
    }

    // 拓墣排序
    RPT(i,p) topo.EB(i+1);
    while(now < topo.size())
    {
        t = topo[now]; ++now;
        for(int i:nxt[t]) if(--indeg[i] == 0) topo.EB(i);
    }

    // 順著拓墣排序計算每個閘的結果 順便 DP 每個閘的延遲為上兩個閘的延遲最大值 +1
    FOR(i,p,n)
    {
        t = topo[i];
        if(gate[t] == 0)
        {
            data[t] = data[F];
            delay[t] = delay[F];
        }
        if(gate[t] == 1)
        {
            data[t] = data[F] & data[S];
            delay[t] = max(delay[F], delay[S]) + 1;
        }
        if(gate[t] == 2)
        {
            data[t] = data[F] | data[S];
            delay[t] = max(delay[F], delay[S]) + 1;
        }
        if(gate[t] == 3)
        {
            data[t] = data[F] ^ data[S];
            delay[t] = max(delay[F], delay[S]) + 1;
        }
        if(gate[t] == 4)
        {
            data[t] = 1 - data[F];
            delay[t] = delay[F] + 1;
        }
    }
    FOR(i,p+q,n) mx = max(mx, delay[i+1]);
    cout << mx << endl;
    FOR(i,p+q,n) cout << data[i+1] << " \n"[i == n-1];
}