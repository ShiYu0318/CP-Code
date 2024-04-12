#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        FOR(i,n) cout << 2 * i + 1 << ' ';
        cout << "\n";
    }
}