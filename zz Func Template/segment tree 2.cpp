#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs ((x << 1) | 1)

const int MAXN = 2e5+5;
int seg[MAXN << 2],arr[MAXN];

void pull(int x)
{
    seg[x] = seg[ls] + seg[rs];
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
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return seg[x];
    int lq = query(ls, l, mid, ql, qr);
    int rq = query(rs, mid + 1, r, ql, qr);
    return lq + rq;
}

signed main()
{
    ShiYu;
    int n,q; cin >> n >> q;
    for(int i = 1;i <= n; ++i) cin >> arr[i];
    build(1,1,n);
    int a,b;
    while(q--)
    {
        cin >> a >> b;
        cout << query(1,1,n,a,b) << '\n';
    }
}