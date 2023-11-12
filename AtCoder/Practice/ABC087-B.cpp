#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<=n;++i)


signed main()
{
    int a,b,c,x; cin >> a >> b >> c >> x;
    int ans=0;
    FOR(i,a)
    {
        FOR(j,b)
        {
            FOR(k,c)
            {
                if(i*500 + j*100 + k*50 == x)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    
}