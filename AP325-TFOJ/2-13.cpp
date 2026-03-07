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
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 習題 Q-2-13. 無理數的快速冪 (108 高中全國賽, simplifed)
// 快速冪 乘法展開

const int p = 1e9+9;

// ( a + b \sqrt{k} ) * ( c + d \sqrt{k}) = ( ac + bdk ) + ( ad + bc ) \sqrt{k}
pii mt(pii a, pii b)
{
    int s = a.F * b.F %p + a.S * b.S %p * 2 %p;
    int t = a.F * b.S %p + a.S * b.F %p;
    return {s %p,t %p};
}

pii fpow(pii z, int n)
{
    if(n == 1) return z;
    pii t = fpow(z, n/2), tt = mt(t,t);
    return (n & 1 ? mt(tt, z) : tt);
}

signed main()
{
    ShiYu;
    int x,y,n; cin >> x >> y >> n;
    pii z = fpow(MP(x,y),n);
    cout << z.F %p << ' ' << z.S %p << '\n';
}