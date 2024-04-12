#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define int long long

signed main()
{
    ShiYu;
    int n,p,s; cin >> n >> p >> s;
    int t,a;
    while(s--)
    {
        cin >> t;
        bool c = false;
        while(t--)
        {
            cin >> a;
            if(a == p) c = true;
        }
        if(c) cout << "KEEP\n";
        else cout << "REMOVE\n";
    } 
}