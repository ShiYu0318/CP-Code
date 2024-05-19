#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
    ShiYu;
    int n; cin >> n;
    vi v(n); input(v);
    int ans = 1, t = 0;
    for(int i=1; i<n; ++i)
    {
        if(v[i-1] < v[i])
        {
            if(t == -1)
            {
                ++ans;
                t = 0;
            }
            else if(t == 0) t = 1;
        }
        else if(v[i-1] > v[i])
        {
            if(t == 1)
            {
                ++ans;
                t = 0;
            }
            else if(t == 0) t = -1;
        }
    }
    cout << ans << endl;
}