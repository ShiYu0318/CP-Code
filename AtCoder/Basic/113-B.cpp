#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    ShiYu;
    double n,t,a; cin >> n >> t >> a;
    double h,minn = INT_MAX,ans;
    FOR(i,n)
    {
        cin >> h;
        if(abs((t - h * 0.006) - a) < minn)
        {
            minn = abs((t - h * 0.006) - a);
            ans = i+1;
        }
    }
    cout << ans << '\n';
    return 0;
}