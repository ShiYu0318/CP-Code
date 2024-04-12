#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)
// 25 行要判斷 t 是不是 0 不然除以 0 會 RE
signed main()
{
    ShiYu;
    int k,r; cin >> k >> r;
    vector<int> v;
    int a,q=k;
    while(q--)
    {
        cin >> a;
        v.push_back(a);
    }
    int t,minn,ans = INT_MIN,p;
    while(r--)
    {
        minn = INT_MAX;
        FOR(i,k)
        {
            cin >> t;
            if(t != 0) minn = min(minn, v[i] / t);
        }
        cin >> p;
        ans = max(ans, minn * p);
    }
    cout << ans << '\n';
    return 0;
}