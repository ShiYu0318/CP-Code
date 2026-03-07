#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 Q-2-10. 子集合的和 (折半枚舉)
// 遞迴枚舉子集合 折半枚舉

int p;

void gen(const vi &v, set<int> &st, int t, int res)
{
    if(res > p) return;
    if(t == SZ(v)) { st.insert(res); return; }
    gen(v,st,t+1,res + v[t]); gen(v,st,t+1,res);
}

signed main()
{
    ShiYu;
    int n; cin >> n >> p;
    int la = n/2, lb = n - la;
    vi a(la), b(lb);
    input(a); input(b);

    set<int> sa,sb;
    gen(a,sa,0,0); gen(b,sb,0,0);

    int ans = 0;
    for(auto i:sa)
    {
        auto it = sb.upper_bound(p - i);
        if(it != sb.begin()) ans = max(ans, i + *(--it));
    }
    cout << ans << '\n';
}