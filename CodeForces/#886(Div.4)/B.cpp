#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0);
#define int long long
using namespace std;

signed main()
{
    IO;
    int t; cin >> t;
    while(t--)
    {
        int n,max=0,ans=0;
        cin >> n;
        int r[n],q[n];
        for(int i=0;i<n;++i)
        {
            cin >> r[i] >> q[i];
            if(r[i] <= 10)
            {
                if(q[i] > max)
                {
                    max = q[i];
                    ans = i + 1;
                }
            }
        }
        cout << ans << "\n";
    }
}