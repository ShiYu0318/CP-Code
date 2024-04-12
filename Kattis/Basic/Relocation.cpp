#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)

int l[100000];

signed main()
{
    ShiYu;
    int n,q; cin >> n >> q;
    FOR(i,n) cin >> l[i];
    int t,a,b,c,x;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> c >> x;
            l[c-1] = x;
        }
        else if(t == 2)
        {
            cin >> a >> b;
            cout << abs(l[a-1] - l[b-1]) << "\n";
        }
    }
}