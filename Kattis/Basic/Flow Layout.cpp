#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(i=0;i<n;++i)
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    ShiYu;
    int n;
    while(cin >> n)
    {
        if(n == 0) break;
        int a,b,x=0,y=0,ans1=0,ans2=0;
        bool f = true;
        while(cin >> a >> b)
        {
            if(a == -1 && b == -1)
            {
                cout << ans1 << " x " << ans2 + y << "\n";
                break;
            }
            if(x + a <= n)
            {
                x += a;
                if(b > y) y = b;
            }
            else
            {
                ans2 += y;
                x = a; y = b;
            }
            ans1 = max(ans1,x);
        }
    }
}