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
    int n,k; cin >> n >> k;
    vi v(n),sl(n+1),sr(n+1),cl(n+1),cr(n+1);
    input(v); sl[0] = sr[n] = cl[0] = cr[n] = 0;
    RPT(i,n)
    {
        sl[i+1] = sl[i] + v[i];
        cl[i+1] = cl[i] + (v[i] % 2);
    }
    rFOR(i,n)
    {
        sr[i] = sr[i+1] + v[i];
        cr[i] = cr[i+1] + (v[i] % 2);
    }
    output(sl);output(sr);output(cl);output(cr);
    int ans = -1;
    cout << endl;
    RPT(i,n)
    {
        int d = k - sl[i];
        // cout << sl[i] << ' ' << d << '\n';
        auto it = upper_bound(all(sr),d,greater<int>());
        if(sl[i] + *it > k) continue;
        int j = it-sr.begin();
        // cout << *it <<  j << endl;
        // cout << i << ' ' << n-j << ' ' << cl[i] << ' ' <<  cr[j] << endl;
        cout << i << ' ' << n-j << '\n';
        cout << sl[i] << ' ' << *it << ' ' << sl[i] + *it << "\n";
        cout << cl[i] << ' ' << cr[j] << "\n\n";
        if((cl[i] + cr[j]) * 2 == i + (n-j)) ans = max(ans, sl[i] + *it);
    }
    cout << ans << endl;
}