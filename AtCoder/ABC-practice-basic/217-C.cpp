#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int n; cin >> n;
    int p[n],q[n];
    FOR(i,n)
    {
        cin >> p[n];
        q[p[n]-1] = i+1;
    }
    FOR(i,n) cout << q[i] << " ";
}