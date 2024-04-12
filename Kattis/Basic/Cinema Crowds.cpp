#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n,m; cin >> n >> m;
    int t,sum=0,ans=0,k=m;
    while(m--)
    {
        cin >> t;
        if(n - sum >= t)
        {
            ans++;
            sum += t;
        }
    }
    cout << k - ans << '\n';
}