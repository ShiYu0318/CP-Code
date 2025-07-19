#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)

signed main()
{
    ShiYu;
    int n,c; cin >> n >> c;
    int w[1000];
    FOR(i,0,n) cin >> w[i];
    int maxn = INT_MIN;
    FOR(i,0,n)
    {
        int sum = 0,t=0;
        FOR(j,i,n)
        { 
            if(sum + w[j] <= c)
            {
                t++;
                sum += w[j];
            }
        }
        maxn = max(maxn,t);
    }
    cout << '\n' << maxn << '\n';
    return 0;
}