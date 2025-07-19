#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define F first
#define S second
#define Bbicorz ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(NULL)

const int INF = 1e18 + 1;

struct Segment_tree{

    vector<int> seg;
    vector<int> arr;

    Segment_tree(int n){
        arr.resize(n + 1);
        seg.resize(4 * n + 5);
    }

    inline void build(int l, int r, int idx){
        if(l == r) return seg[idx] = arr[l], void();
        int mid = (l + r) >> 1;
        build(l, mid, idx << 1);
        build(mid + 1, r, idx << 1 | 1);
        seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
    }

    inline int query(int l, int r, int idx, int val) {
        if(l == r) return l;
        int mid = l + r >> 1;
        if(seg[idx << 1] == val) return query(l, mid, idx << 1, val);
        return query(mid + 1, r, idx << 1 | 1, val);
    }

    inline void modify(int l, int r, int idx, int node, int k){
        if(l == r) return seg[idx] = k, arr[l] = k, void();
        int mid = (l + r) >> 1;
        if(mid >= node) modify(l, mid, idx << 1, node, k);
        else modify(mid + 1, r, idx << 1 | 1, node, k);
        seg[idx] = min(seg[idx << 1], seg[idx << 1 | 1]);
    }

};


inline void solve(){
    int n, k;
    cin >> n >> k;
    Segment_tree f(n);
    vector<pii> link(n + 5); // F is left node, S is right node
    for(int i = 1; i <= n; ++i) cin >> f.arr[i];
    for(int i = 1; i <= n; ++i) link[i].F = i - 1, link[i].S = i + 1;
    f.build(1, n, 1);
    auto ers = [&](int idx){
        int fr = link[idx].F;
        int ba = link[idx].S;
        link[fr].S = ba;
        link[ba].F = fr;
        link[idx] = {n + 2, n + 2};
        return ba;
    };
    int ans = 0;
    int cnt = 0;
    while(cnt < n) {
        int mi = f.seg[1];
        if(mi > k) break;
        int idx = f.query(1, n, 1, mi);
        int ba = ers(idx);
        f.modify(1, n, 1, idx, INF);
        if(ba <= n) f.modify(1, n, 1, ba, f.arr[ba] + mi);
        ans += mi;
    }
    cout << ans << '\n';
}

signed main() {
    Bbicorz;
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
