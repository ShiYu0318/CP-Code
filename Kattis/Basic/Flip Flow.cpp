#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define dbg(x) cout << #x << "=" << x << " "

signed main()
{
    ShiYu
    int t,s,n; cin >> t >> s >> n;
    int a,b,now=0;
    bool c = false;
    FOR(i,n)
    {
        cin >> a;
        if(i == 0)
        {
            b = a;
            now = s - now;
            continue;
        }
        else
        {
            if(a - b >= now) now = 0;
            else now -= (a - b);
            now = s - now;
        }
        b = a;
    }
    if(now - (t - b) <= 0) cout << 0 << "\n";
    else cout << now - (t - b) << "\n";
}