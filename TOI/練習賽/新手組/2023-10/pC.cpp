#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main(void)
{
    int l[3]; FOR(i,3) cin >> l[i];
    int s[3]={0},t;
    FOR(i,3)
    {
        FOR(j,l[i])
        {
            cin >> t;
            s[i] += t * 3;
        }
        s[i] += (l[i]-1) * 2;
    }
    int n,mint = INT_MAX;
    FOR(i,3)
    {
        if(s[i] < mint)
        {
            n = i+1;
            mint = s[i];
        }
    }
    cout << n << ' ' << mint << '\n';
}