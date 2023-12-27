#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define int long long

signed main()
{
    ShiYu
    int a,b; cin >> a >> b;
    int t,ans=0;
    FOR(i,a,b)
    {
        t = i;
        vector<int> v;
        while(t != 0)
        {
            v.push_back(t % 10);
            t /= 10;
        }
        bool c = true;
        FOR(i,0,v.size()/2)
        {
            if(v[i] != v[v.size()-i-1])
            {
                c = false;
                break;
            }
        }
        if(c) ans++;
    }
    cout << ans << "\n";
}