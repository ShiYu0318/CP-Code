#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

signed main()
{
    int t; cin >> t;
    int n,k,b;
    while(t--)
    {
        cin >> n;
        int ans=-1;
        for(int i=0;i<n;++i)
        {
            cin >> k;
            if(i == 0 || i == n-1 || ans != -1)
            {
                b = k;
                continue;
            }
            if(k - b != 1) ans = i + 1;
            b = k;
        }
        cout << ans << "\n";
    }
}