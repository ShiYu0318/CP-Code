#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)


signed main()
{
    int n,b,h,w; cin >> n >> b >> h >> w;
    int minn = INT_MAX,p,a;
    bool c,k=false;
    while(h--)
    {
        cin >> p;
        // cout << p << "\n";
        c = false;
        FOR(i,w)
        {
            cin >> a;
            if(c) continue;
            if(n <= a && n * p <= b)
            {
                minn = min(n * p, minn);
                // cout << minn << "\n";
                c = true;
                k = true;
            }
        }
    }
    if(k) cout << minn << "\n";
    else cout << "stay home\n";

    
}