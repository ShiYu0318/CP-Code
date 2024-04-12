#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

signed main()
{
    ShiYu
    int n; cin >> n;
    for(int i=1;i<=n;++i)
    {
        cout << "Case #" << i << ":\n";
        vector<pair<string,int>> v;
        int maxn = INT_MIN,r;
        string s;
        for(int j=0;j<10;++j)
        {
            cin >> s >> r;
            v.emplace_back(s,r);
            maxn = max(maxn,r);
        }
        for(auto &i : v)
        {
            if(i.S == maxn) cout << i.F << '\n';
        }
    }
}