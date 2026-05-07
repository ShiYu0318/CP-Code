// 20260507
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

// Q-4-19. 五嶽盟主的會議場所
// 掃描線 O(n)

signed main()
{
    ShiYu;
    int n,m,s,t; cin >> n;
    vector<pii> vp;
    while(n--)
    {
        cin >> m >> s >> t;
        vp.EB(s,m);
        vp.EB(t+1,-m);
    }
    sort(all(vp));
    int mx = -1, now = 0;
    for(auto [i,j] : vp)
    {
        now += j;
        mx = max(mx, now);
    }
    cout << mx << "\n";
}