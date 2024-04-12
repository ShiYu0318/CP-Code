#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0;i<n;++i)


signed main()
{
    ShiYu;
    int n,k; cin >> n >> k;
    int i=1,t;
    while(n--)
    {
        cin >> t;
        if(i % k == 0) cout << t << ' ';
        i++;
    }
    cout << "\n";
    
}