#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    int ans = 0,q=1,t = 0;
    while(t <= n)
    {
        ans++;
        t += q * q;
        q += 2;
    }
    cout << ans-1 << '\n';
}