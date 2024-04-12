#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 

// 思考規律

signed main()
{
    ShiYu;
    int n,i,j; cin >> n;
    while(n--)
    {
        cin >> i >> j;
        int t = max(i,j), minn = (t-1) * (t-1), maxn = t * t, ans;
        if(t % 2) ans = (i >= j ? minn + j : maxn - i + 1);
        else ans = (i >= j ? maxn - j + 1 : minn + i);
        cout << ans << '\n';
    }    
}