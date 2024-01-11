#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define input(x) for(auto &i : x) cin >> i; 

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(n); input(v);
    int ans = 0;
    FOR(i,1,n)
    {
        int d = v[i-1] - v[i];
        if(d > 0)
        {
            ans += d;
            v[i] += d;
        }
    }
    cout << ans << "\n";
}