#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

// 偏思考 + 優化技巧
// 根號 分塊

signed main()
{
    ShiYu;
    ll t,n; cin >> t;
    while(t--)
    {
        cin >> n;
        ll cnt = 0,i,r=sqrt(n);
        for(i=1; i<=r; ++i) cnt += (n/i - n/(i+1)) * i;
        for(i=1; i<=n/(r+1); ++i) cnt += n/i;
        cout << cnt << '\n';
    }
}