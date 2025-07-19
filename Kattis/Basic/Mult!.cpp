#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int n; cin >> n;
    int t,f=-1;
    while(n--)
    {
        cin >> t;
        if(f == -1)
        {
            f = t;
            continue;
        }
        
        if(t % f == 0)
        {
            cout << t << '\n';
            f = -1;
        }
    }
}