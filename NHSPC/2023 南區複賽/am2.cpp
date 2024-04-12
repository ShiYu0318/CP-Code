#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0; i<=n; ++i)

signed main()
{
    ShiYu;
    int t; cin >> t;
    int n;
    while(t--)
    {
        cin >> n;
        int ans = 0;
        FOR(i, n / 50)
        {
            FOR(j, (n - i*50) / 25)
            {
                FOR(k, (n - i*50 - j*25) / 10)
                {
                    ans += (n - i*50 - j*25 - k*10) / 5 + 1;
                }
            }
        }
        cout << ans << '\n';
    }
}