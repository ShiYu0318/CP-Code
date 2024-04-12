#include <bits/stdc++.h>
#define ShiYu; ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
// 這題有嚴格比對 所以最後一個值輸出時不要有空格

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    int t,ans=0;
    vector<int> v;
    FOR(i,n)
    {
        int maxn = INT_MIN;
        FOR(j,m)
        {
            cin >> t;
            maxn = max(maxn,t);
        }
        v.push_back(maxn);
        ans += maxn;
    }
    cout << ans << "\n";
    vector<int> v2;
    FOR(i,v.size())
    {
        if(ans % v[i] == 0)
        {
            v2.push_back(v[i]);
        }
    }
    if(v2.empty()) cout << -1;
    else
    {
        FOR(i,v2.size()-1) cout << v2[i] << ' ';
        cout << v2[v2.size()-1];
    }
    cout << "\n";
    
}