// 20260105
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

// 習題 Q-3-11. 最長的相異色彩帶
// 簡單版 例題 P-3-9. 最多色彩帶
// 滑動窗口 + bucket 分桶

signed main()
{
    ShiYu;
    int n; cin >> n;
    vi v(n), bk(n,0); input(v);
    int ans = 0;
    for(int l=0, r=0; r<n; ++r)
    {   // 當右界右移後遇到區間重複元素 則持續右移左界直到不重複
        if(++bk[v[r]] == 2)
        {
            while(bk[v[r]] > 1) bk[v[l++]]--;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans << '\n';
}