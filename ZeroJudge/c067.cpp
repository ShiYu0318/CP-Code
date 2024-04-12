#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    ShiYu;
    int n,c=1; 
    while(cin >> n)
    {
        if(!n) break;
        int h[51],sum=0;
        FOR(i,n)
        {
            cin >> h[i];
            sum += h[i];
        }
        int avg = sum / n;
        int ans = 0;
        FOR(i,n)
        {
            if(avg > h[i]) ans += avg - h[i];
        }
        cout << "Set #" << c << "\nThe minimum number of moves is " << ans << ".\n\n";
        c++;
    }
    
}