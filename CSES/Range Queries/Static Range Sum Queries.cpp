#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define int long long

const int MAXN = 2e5+5;
int seg[MAXN << 2],arr[MAXN];

void pull(int x)
{
    seg[x] = seg[2 * x] + seg[2 * x + 1];
}

void build(int x, int l ,int r)
{
    if(l == r) seg[x] = arr[l];
    else
    {
        int mid = (l + r) / 2;
        build(2 * x, l, mid);
        build(2 * x + 1, mid + 1, r);
        pull(x);
    }
}

int query(int x, int l, int r, int ql, int qr)
{
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return seg[x];
    int mid = (l + r) / 2;
    int lq = query(2 * x, l, mid, ql, qr);
    int rq = query(2 * x + 1, mid + 1, r, ql, qr);
    return lq + rq;
}

signed main()
{
    ShiYu
    int n,q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    build(1,1,n);
    for(int i=0;i<4*n;++i) cout << seg[i] << " ";
    int a,b;
    while(q--)
    {
        cin >> a >> b;
        cout << query(1,1,n,a,b) << "\n";
    }
}