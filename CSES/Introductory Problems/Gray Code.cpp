#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define eb emplace_back
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<string> ans;
    ans.eb("0");
    ans.eb("1");
    for(int i = 2; i < (1 << n); i <<= 1)
    {
        rFOR(j,i) ans.eb(ans[j]);
        RPT(j,i) ans[j] = '0' + ans[j];
        FOR(j,i,i*2) ans[j] = '1' + ans[j];
    }
    for(auto &i : ans) cout << i << "\n";
}