#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define all(x) x.begin(), x.end()

signed main()
{
    int n; cin >> n;
    if(n % 4 == 0 || n % 7 == 0) cout << "Yes\n";
    else
    {
        FOR(i,n/4+1)
        {
            FOR(j,n/7+1)
            {
                if(i * 4 + j * 7 == n)
                {
                    cout << "Yes\n";
                    return 0;
                }
                else if(i * 4 + j * 7 > n) break;
            }
        }
        cout << "No\n";
        return 0;
    }
}