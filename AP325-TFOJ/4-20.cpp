// 2026
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

// Greedy 區間覆蓋 雙指針
// 對於滿足在左端於子區間範圍內的條件下更新右端最大值直到不連續或完全涵蓋

int yn(vector<pii> &vp, int n, int x, int y)
{
    int l = x, r = x, cnt = 0;
    for(int i=0; i<n; ++i)
    {
        if(vp[i].F <= l)
        {
            if(vp[i].S > r) r = vp[i].S;
        }
        else
        {
            ++cnt;
            l = r; r = vp[i].S;
            if(l < vp[i].F) return -1;
        }
        if(r >= y) break;
    }
    return (r < y ? -1 : cnt+1);
}

signed main()
{
    ShiYu;
    int n,x,y; cin >> n >> x >> y;
    vector<pii> vp(n);
    for(auto &[i,j] : vp) cin >> i >> j;
    sort(all(vp));
    cout << yn(vp, n, x, y) << "\n";
}