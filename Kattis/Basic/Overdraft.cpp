#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define all(x) x.begin(), x.end()

signed main(void)
{
    int n,t,ans=0,now=0;
    while(cin >> n)
    {
        FOR(i,n)
        {
            cin >> t;
            now += t;
            if(now < 0 && now < ans) ans = now;
        }
        cout << 0 - ans << '\n';
    }
}