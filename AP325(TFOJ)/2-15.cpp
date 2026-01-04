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
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-2-15. 圓環出口 (APCS202007)
// 前綴和 二分搜 循環

signed main()
{
    ShiYu;
    int n,m,t = 0; cin >> n >> m;
    vi p(n), q(m), ps(n+1); input(p); input(q);
    ps[0] = 0; RPT(i,n) ps[i+1] = ps[i] + p[i]; // 前綴和
    for(int i:q)
    {   // 不需循環則搜點數+目前和 否則搜剩餘點數
        if(ps[n] - ps[t] > i) t = lower_bound(ps.begin()+t, ps.end(), i + ps[t]) - ps.begin();
        else t = lower_bound(ps.begin(), ps.end(), i - (ps[n] - ps[t])) - ps.begin();
    }
    cout << t << endl;
}