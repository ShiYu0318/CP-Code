#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main(void)
{
    int N,M,X,Y; cin >> N >> M >> X >> Y;
    bool c = true;
    int ans;
    FOR(i,M)
    {
        if(i * X == N - (M-i) * Y) 
        {
            c = false;
            ans = i;
            break;
        }
    }
    if(!c) cout << ans << ' ' << M-ans << "\n";
    else cout << "-1 -1\n";
}