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

// AC

struct seg
{
    int l, r, m, v = 0;
    seg *ln = NULL, *rn = NULL;
    seg(int _l, int _r) : l(_l), r(_r)
    {
        m = (l + r) >> 1;
        if(l == r - 1) return;
        ln = new seg(l, m);
        rn = new seg(m, r);
        pull();
    }
    void pull() {v = min(ln->v, rn->v);}
    void upd(int p, int k)
    {
        if(l == p && r - 1 == p) { v = k; return; }
        if(p < m) ln->upd(p, k);
        else rn->upd(p, k);
        pull();
    }
    int query(int ll, int rr)
    {
        if (l == ll && r == rr) return v;
        if (rr <= m) return ln->query(ll, rr);
        if (ll >= m) return rn->query(ll, rr);
        return min(ln->query(ll, m), rn->query(m, rr));
    }
};

signed main()
{
    ShiYu;
    int n, q; cin >> n >> q;
    vi v(n); seg l(0, n), r(0, n);
    RPT(i,n)
    {
        cin >> v[i];
        l.upd(i, v[i] + i);
        r.upd(i, v[i] + n - i - 1);
    }
    while(q--)
    {
        int m; cin >> m;
        if(m == 1)
        {
            int k, x; cin >> k >> x; k--;
            l.upd(k, x + k);
            r.upd(k, x + n - k - 1);
        }
        else
        {
            int k; cin >> k; k--;
            int ans = min(l.query(k, n) - k, r.query(0, k + 1) - (n - k - 1));
            cout << ans << endl;
        }
    }
}