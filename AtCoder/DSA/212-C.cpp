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

// 雙指針

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    vi a(n),b(m); input(a); input(b);
    sort(all(a)); sort(all(b));
    int ans = INT_MAX, i = 0, j = 0;
    while(i < n && j < m)
    {
        ans = min(ans, abs(a[i] - b[j]));
        ++(a[i] < b[j] ? i : j);
    }
    cout << ans << endl;
}

// 排序 搜尋

// signed main()
// {
//     ShiYu;
//     int n,m; cin >> n >> m;
//     vi a(n),b(m); input(a); input(b);
//     sort(all(b));
//     int ans = INT_MAX;
//     for(auto i : a)
//     {
//         if(b[0] > i) ans = min(ans, abs(b[0] - i));
//         else if(b[m-1] < i) ans = min(ans, abs(b[m-1] - i));
//         else
//         {   // 跳躍二分搜
//             int now=0;
//             for(int jump = m/2; jump > 0; jump /= 2)
//             {
//                 while(now + jump < m && b[now+jump] < i) now += jump;
//             }
//             ans = min(ans, abs(b[now] - i));
//             ans = min(ans, abs(b[now+1] - i));
//         }
//     }
//     cout << ans << endl;
// }