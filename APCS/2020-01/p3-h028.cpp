// 20260104
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
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-3-6. 砍樹 (APCS202001)
// 單調佇列

const int N = 1e9+5;

signed main()
{
    ShiYu;
    int n, l; cin >> n >> l;
    vi p(n), h(n); input(p); input(h);
    p.push_back(l); h.push_back(N);  // 右邊界給一棵不會倒的樹讓最後一棵樹也能有辦法判斷是否能向右倒
    stack<int> mono;    // 存 idx, h[mono[i]] 是單調遞減
    int cnt = 0, mx = 0;
    RPT(i,n+1)  // n + 1 右邊界樹讓最後一棵樹判斷能否右倒
    {
        // mono 裡的樹向右有空間就倒
        while(!mono.empty() && p[i] - p[mono.top()] >= h[mono.top()])
        {
            mx = max(mx, h[mono.top()]);
            ++cnt; mono.pop();
        }
        // 要進來的樹向左有空間就倒
        int ls = mono.empty() ? p[i] : p[i] - p[mono.top()];
        if((ls >= h[i])) { mx = max(mx, h[i]); ++cnt; }
        else mono.push(i);  // 否則進 mono 等右邊有空間
    }
    cout << cnt << '\n' << mx << '\n';
}