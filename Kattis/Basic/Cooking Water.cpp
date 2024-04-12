#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)


signed main()
{
    ShiYu;
    int n; cin >> n;
    int t[1001] = {0},a,b;
    FOR(i,0,n-1)
    {
        cin >> a >> b;
        FOR(j,a,b)
        {
            t[j]++;
            if(t[j] == n)
            {
                cout << "gunilla has a point\n";
                return 0;
            }
        }
    }
    cout << "edward is right\n";
    return 0;
}