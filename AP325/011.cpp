#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
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

// 例題 P-2-2. 離散化 – sort
// 離散化

signed main()
{
    int n; cin >> n;
    int original[n], result[n]; vi discrete(n);
    RPT(i,n)
    {
        cin >> original[i];
        discrete[i] = original[i];
    }
    sort(all(discrete));
    discrete.resize(unique(all(discrete)) - discrete.begin());
    RPT(i,n)
    {
        result[i] = lower_bound(all(discrete), original[i]) - discrete.begin();
    }
    outputN(result,n);
}