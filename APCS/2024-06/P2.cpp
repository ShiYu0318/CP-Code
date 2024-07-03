#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define endl '\n'
#define RPT(i,n) for(int i=0; i<n; ++i)
#define dRPT(a,b) RPT(i,a) RPT(j,b)

signed main()
{
    ShiYu;
    int h,w,n,r,c,t,x,ans[25][25] = {0};
    cin >> h >> w >> n;
    while(n--)
    {
        cin >> r >> c >> t >> x;
        dRPT(h,w) if(abs(i-r) + abs(j-c) <= t) ans[i][j] += x;
    }
    dRPT(h,w) cout << ans[i][j] << " \n"[j == w-1];
}