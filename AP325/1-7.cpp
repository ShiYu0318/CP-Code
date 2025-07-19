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

// 例題 P-1-7. 子集合乘積 
// 遞迴

const int P = 1e4+9;
int n, ans, a[26];

void sub(int t, int res)
{
    if(t == n)
    {
        if(res == 1) ++ans;
        return;
    }
    sub(t + 1, res * a[t] % P);
    sub(t + 1, res);
    return;
}

signed main()
{
    ShiYu;
    cin >> n;
    RPT(i,n) cin >> a[i];
    sub(0,1);
    cout << ans - 1; nl;
}