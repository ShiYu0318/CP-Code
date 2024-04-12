#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    vector<string> v(m);
    RPT(i,m)
    {
        if((i+1) % 3 == 0 && (i+1) % 5 == 0) v[i] = "fizzbuzz";
        else if((i+1) % 3 == 0) v[i] = "fizz";
        else if((i+1) % 5 == 0) v[i] = "buzz";
        else v[i] = to_string(i+1);
    }
    string s;
    int ans=-1, maxn = -1,t;
    RPT(i,n)
    {
        t = 0;
        RPT(j,m)
        {
            cin >> s;
            if(v[j] == s) ++t;
        }
        if(t > maxn)
        {
            maxn = t;
            ans = i;
        }
    }
    cout << ans+1 << "\n";  
}
