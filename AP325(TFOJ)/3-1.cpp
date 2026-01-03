// 20260102
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-3-1. 樹的高度與根 (bottom-up) (APCS201710) (同 P-8-4-1)
// 樹 queue bottom-up

signed main()
{
    int n; cin >> n;
    vi pa(n,0), h(n,0), deg(n);
    queue<int> q;
    FOR(i,1,n+1)
    {
        cin >> deg[i];
        if(deg[i] == 0) q.push(i);  // 葉節點
        RPT(j,deg[i])
        {
            int c; cin >> c;
            pa[c] = i;  // 父節點
        }
    }
    int r, sum = 0;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        sum += h[v];
        int p = pa[v];
        if(p == 0)  // 沒父節點則為根節點
        {
            r = v;
            break;
        }
        h[p] = max(h[p], h[v] + 1); // 更新深度
        if(--deg[p] == 0) q.push(p);    // 父節點拔掉子結點後變葉節點
    }
    cout << r << "\n" << sum << "\n";
}