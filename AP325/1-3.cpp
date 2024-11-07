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

// 例題 P-1-3. 棍子中點切割
// 遞迴

const int SIZE = 5e4+5;
int p[SIZE];

int cut(int l, int r)
{
    if(r - l <= 1) return 0;
    int m = l, k = (p[l] + p[r]) / 2;
    // 跳躍二分搜
    for(int jump = (r - l) >> 1; jump > 0; jump >>= 1)
    {
        while(m + jump <= r && p[m + jump] <= k) m += jump;
    }
    if(p[m] - p[l] < p[r] - p[m+1]) ++m;
    return (p[r] - p[l]) + cut(l,m) + cut(m,r);
}

signed main()
{
    ShiYu;
    int n, l; cin >> n >> l;
    p[0] = 0; p[n+1] = l;
    RPT(i,n) cin >> p[i+1];
    cout << cut(0, n+1); nl;
}