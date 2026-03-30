#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define pii pair<int,int>

signed main()
{
    int a,b,n; cin >> a >> b >> n;
    int ans = 0;
    while(n--)
    {
        pii p = {0,0};
        int t;
        while(cin >> t)
        {
            if(!t) break;
            if(t == a) p.first++;
            else if(0 - t == a) p.first--;
            if(t == b) p.second++;
            else if(0 - t == b) p.second--;
        }
        if(p.first && p.second) ans++;
    }
    cout << ans << '\n';
    
}