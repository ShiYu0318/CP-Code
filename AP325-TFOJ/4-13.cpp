// 20260107
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// P-4-13. 最大連續子陣列 (同 P-5-2)
// Greedy or DP

signed main()
{
    ShiYu;
    int n; cin >> n;
    int sum = 0, mx = 0;
    while(n--)
    {
        int a; cin >> a;
        sum = ((sum + a > 0) ? (sum + a) : 0);
        mx = max(mx, sum);
    }
    cout << mx << '\n';
}