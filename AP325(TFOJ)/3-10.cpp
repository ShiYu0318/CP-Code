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

// 例題 P-3-10. 全彩彩帶 (需離散化或字典) (@@) 
// 延伸版 例題 P-3-9. 最多色彩帶
// 滑動窗口 + bucket 分桶 + 離散化 + 二分搜
// 彩帶編號不連續且數字大 用離散化重新編號並用二分搜找對應位置

signed main()
{
    ShiYu;
    int n; cin >> n;
    vi v(n), uni; input(v);
    uni = v; sort(all(uni));
    uni.resize(unique(all(uni)) - uni.begin()); // 離散化
    for(int &i:v) i = upper_bound(all(uni),i) - uni.begin() - 1;    // 重新編號
    vi bk(SZ(uni),0);
    int cnt = 0, ans = n+1;
    for(int l=0, r=0; r<n; ++r)
    {
        if(bk[v[r]]++ == 0) ++cnt;
        while(cnt == SZ(uni))
        {   // 當全滿時更新最小區間長 並持續移動左界直到不合法
            ans = min(ans, r-l+1);
            bk[v[l]] -= 1;
            if(bk[v[l]] == 0) --cnt;
            ++l;
        }
    }
    cout << ans << '\n';
}