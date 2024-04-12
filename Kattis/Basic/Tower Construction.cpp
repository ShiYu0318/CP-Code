#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
    int t; cin >> t;
    int h,b=0,ans=0;
    while(t--)
    {
        cin >> h;   
        if(h > b) ans++;
        b = h;
    }
    cout << ans << '\n';
}