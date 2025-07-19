#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// 習題 Q-2-5. 快速計算費式數列第 n 項
// 矩陣快速冪

const int p = 1e9+7;
vi mt = {1,1,1,0};

vi multi(vi a, vi b)
{
    return {
        (a[0]*b[0] + a[1]*b[2]) % p,
        (a[0]*b[1] + a[1]*b[3]) % p,
        (a[2]*b[0] + a[3]*b[2]) % p,
        (a[2]*b[1] + a[3]*b[3]) % p
    };
}

vi fpow(int n)
{
    if(n == 0 || n == 1) return mt;
    vi t = fpow(n/2), tt = multi(t,t);
    return (n & 1 ? multi(mt, tt) : tt);
}

signed main()
{
    ShiYu;
    int n;
    while(cin >> n && n != -1)
    {
        vi m = fpow(n-1);
        cout << m[0]; nl;
    }
}
