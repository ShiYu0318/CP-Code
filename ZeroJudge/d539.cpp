#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs ((x << 1) | 1)

// 線段樹 RMQ(max)

const int MAXN = 5e5+5;
int seg[MAXN << 2], arr[MAXN], n;

void pull(int x)
{
    seg[x] = max(seg[ls],seg[rs]);
}

void build(int x, int l ,int r)
{
    if(l == r) seg[x] = arr[l];
    else
    {
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pull(x);
    }
}

int query(int x, int l, int r, int ql, int qr)
{
    if(qr < l || r < ql) return INT_MIN;
    if(ql <= l && r <= qr) return seg[x];
    int lq = query(ls, l, mid, ql, qr);
    int rq = query(rs, mid + 1, r, ql, qr);
    return max(lq, rq);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    build(1,1,n);
    for(int i=0;i<4*n;++i) cout << seg[i] << ' ';
    int q,a,b; cin >> q;
    while(q--)
    {
        cin >> a >> b;
        if(a > b) swap(a,b);
        cout << query(1,1,n,a,b) << '\n';
    }
}