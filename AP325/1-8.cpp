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

// 習題 Q-1-8. 子集合的和 (APCS201810, subtask) 
// 遞迴

int n, p, ans, a[26];

void sub(int t, int res)
{
    if(t == n)
    {
        if(res <= p) ans = max(ans, res);
        return;
    }
    sub(t + 1, res + a[t]);
    sub(t + 1, res);
    return;
}

signed main()
{
    ShiYu;
    cin >> n >> p;
    RPT(i,n) cin >> a[i];
    sub(0,0);
    cout << ans; nl;
}