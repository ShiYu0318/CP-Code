#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    ShiYu
    int n; cin >> n;
    int a[200],ans=0;
    bool c = false;
    FOR(i,n) cin >> a[i];
    while(1)
    {
        FOR(i,n)
        {
            if(a[i] % 2 == 1)
            {
                c = true;
                break;
            }
            else a[i] /= 2;
        }
        if(c) break;
        ans++;
    }
    cout << ans << "\n";
    
    return 0;
}