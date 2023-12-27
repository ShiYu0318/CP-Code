#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n,p; cin >> n >> p;
    int ans = 0,t;
    while(n--)
    {
        cin >> t;
        if(t < p) ans++;
    }
    cout << ans << "\n";
}