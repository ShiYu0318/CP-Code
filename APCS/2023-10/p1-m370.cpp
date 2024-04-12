#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define MMn maxn=INT_MIN, minn=INT_MAX

signed main()
{
    int x,n; cin >> x >> n;
    int MMn,t,l=0,r=0;
    FOR(i,n)
    {
        cin >> t;
        if(t > x)
        {
            maxn = max(maxn,t);
            r++;
        }
        else
        {
            minn = min(minn,t);
            l++;
        }
    }
    if(r > l) cout << r << ' ' << maxn << "\n";
    else cout << l << ' ' << minn << "\n";
}