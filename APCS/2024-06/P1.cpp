#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define F first
#define S second
#define endl '\n'
#define RPT(i,n) for(int i=0; i<n; ++i)
#define input(x) for(auto &i:x) cin >> i

signed main()
{
    ShiYu;
    int n; cin >> n;
    vi v(n); input(v);
    int ans = 0, cnt = 1;
    RPT(i,n-1)
    {
        if(v[i] < v[i+1]) cnt = 1;
        else ++cnt;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}