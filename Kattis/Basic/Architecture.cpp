#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)


signed main(void)
{
    ShiYu;
    int r,c; cin >> r >> c;
    int a[1001]={0},t,maxn = INT_MIN;
    FOR(i,r+c)
    {
        cin >> t;
        a[t]++;
        maxn = max(maxn,t);
    }
    cout << (a[maxn] == 1 ? "impossible" : "possible") << "\n";
}