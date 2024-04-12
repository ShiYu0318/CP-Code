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
#define F first
#define S second

// 貪心

signed main()
{
    ShiYu
    int n,t,x; cin >> n >> t;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(t--)
    {
        cin >> x;
        pq.emplace(x);
    }
    int ans = 0,a,b,c;
    while(pq.size() > 1)
    {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        c = a + b;
        ans += c;
        pq.emplace(c);
    }
    cout << ans << "\n";
}
