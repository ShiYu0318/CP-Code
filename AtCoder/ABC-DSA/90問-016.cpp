#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n;i>0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 枚舉

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(3); input(v); sort(all(v));
    int ans = INT_MAX;
    for(int i = n / v[2]; i>=0; --i)
    {
        for(int j = (n - i * v[2]) / v[1]; j>=0; --j)
        {
            int temp = n - i * v[2] - j * v[1];
            if(temp % v[0] == 0)
            {
                ans = min(ans,i + j +temp / v[0]);
            }
        }
    }
    cout << ans << "\n";
}
