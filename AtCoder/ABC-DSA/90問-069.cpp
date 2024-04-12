#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 快速冪

const int MOD = 1e9+7;


int fpow(int a, int b)
{
    if(b == 1) return a;
    if(b % 2) return fpow(a * a % MOD, b / 2) * a % MOD;
    return fpow(a * a % MOD, b / 2);
}

signed main()
{
    ShiYu
    int n,k; cin >> n >> k;
    int ans;
    if(n == 1) ans =  k % MOD;
    else if(n == 2) ans = k  * (k-1) % MOD;
    else ans = k * (k-1) % MOD * fpow(k-2,n-2) % MOD;
    cout << ans << "\n";
}
