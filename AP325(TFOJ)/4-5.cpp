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

// 例題 P-4-5. 嵩山磨劍坊的問題 (加權最小完成時間)
// Greedy 依比值升冪排序

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<pair<double,pii>> v(n); // (t/w,(t,w))
    for(auto &i:v) cin >> i.S.F;
    for(auto &i:v) cin >> i.S.S;
    for(auto &i:v) i.F = (double)i.S.F / i.S.S;
    sort(all(v));
    int ans = 0, t = 0;
    for(auto i:v)
    {
        t += i.S.F;
        ans += t * i.S.S;
    }
    cout << ans << '\n';
}