#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int s,t; cin >> s >> t;
    int ans=0;
    FOR(i,101)
    {
        FOR(j,101)
        {
            FOR(k,101)
            {
                if(i + j + k <= s && i * k * j <= t)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}