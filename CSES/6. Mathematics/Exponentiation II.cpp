#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
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

// 費馬小定理 a^{(b^c mod (p-1)} mod p

const int MOD = 1e9+7;

int fpow(int a, int b, int mod)
{
    if(b == 0) return 1;
    if(a == 0) return 0;
    int tmp = fpow(a, b / 2, mod) % mod;
    return (b & 1 ? a : 1) % mod * tmp % mod * tmp % mod;
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    while(n--)
    {
        int a,b,c; cin >> a >> b >> c;
        cout << fpow(a,fpow(b,c,MOD-1),MOD) << endl;
    }
}