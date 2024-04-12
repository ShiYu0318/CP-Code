#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

// 位元枚舉

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(n); input(v);
    int ans = INT_MAX;
    for(int i=0; i < (1 << n); ++i)
    {
        int a = 0, b = 0;
        for(int j=0; j < n; ++j)
        {
            if(i & (1 << j)) a += v[j];
            else b += v[j];
        }
        ans = min(ans,abs(a-b));
    }
    cout << ans << "\n";
}