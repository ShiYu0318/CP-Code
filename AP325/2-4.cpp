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

// 習題 Q-2-4. 快速冪--200 位整數

int p, t;

int fpow(int x, int y)
{
    if(y == 0) return 1;
    int t = fpow(x, y/2);
    return ((y & 1 ? x : 1) * (t * t % p)) % p;
}

signed main()
{
    ShiYu;
    string s; int x = 0, y; cin >> s >> y >> p;
    rFOR(i,SZ(s))
    {
        x = (x + (s[i]-'0') * fpow(10,t)) % p;
        ++t;
    }
    cout << fpow(x,y); nl;
}
