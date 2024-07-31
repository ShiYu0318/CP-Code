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

// 亂做 22 %

const int MOD = 998244353;

int fpow(int a, int b)
{
    if(a == 0 && b == 0) return 1;
    if(b <= 1) return a;
    int temp = fpow(a, b/2);
    return (b & 1 ? a : 1) * temp * temp;
}

signed main()
{
    ShiYu;
    int n,m,ans = 0; cin >> n >> m;
    if(n == 2) RPT(i,10) RPT(j,10)
        if(fpow(i,j)%10 == m%10 && fpow(j,i)%10 == m%10) ++ans;
    cout << ans % MOD << endl;
}