#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

const int MOD = 1e9+7,MAXN=1e6+5;
int dp[MAXN];

signed main()
{
    ShiYu;
    int n,x; cin >> n >> x;
    vector<int> v(n); input(v);
    dp[0] = 1;
    FOR(i,1,x+1)
    {
        for(auto j:v)
        {
            if(j > i) continue;
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << '\n';
}
