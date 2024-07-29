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
// 22%
signed main()
{
    ShiYu;
    int n; cin >> n;
    vi a(n),b(n),c(n); input(a); input(b); input(c);
    int q; cin >> q;
    while(q--)
    {
        int d,l,r,sum = 0; cin >> d >> l >> r;
        FOR(i,l-1,r)
        {
            int val = a[i];
            if(d >= b[i]) val -= c[i] * (d - b[i] + 1);
            sum += max(0LL,val);
        }
        cout << sum << endl;
    }
}