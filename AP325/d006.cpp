#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

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
    ShiYu
    cin >> n;
    RPT(i,n) cin >> a[i];
    sub(0,1);
    cout << ans - 1 << "\n"; 
}