// 20260104
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

// 例題 P-3-9. 最多色彩帶
// 滑動窗口 + bucket 分桶

const int N = 2e5+5;
int bk[N];

signed main()
{
    ShiYu;
    int n,l; cin >> n >> l;
    vi v(n); input(v);
    int cnt = 0, mx = 0;
    for(int i=0; i<n; ++i)
    {
        if(bk[v[i]]++ == 0) ++cnt;  // 右端新增元素在此區間剛剛出現
        if(i > l && --bk[v[i-l-1]] == 0) --cnt; // 左端刪除元素在此區間完全消失
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
}