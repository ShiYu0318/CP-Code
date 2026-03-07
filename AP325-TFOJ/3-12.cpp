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

// 習題 Q-3-12. 完美彩帶 (同 Q-5-8 ，分治版) (APCS201906)
// 例題 P-3-10. 全彩彩帶 (需離散化或字典) (@@)  + 習題 Q-3-11. 最長的相異色彩帶
// 滑動窗口 + bucket 分桶 + unordered_map 離散化

signed main()
{
    ShiYu;
    int m, n; cin >> m >> n;
    vi v(n); input(v);
    unordered_map<int,int> bk;
    int ans = 0, cnt = 0;
    for(int l=0, r=0; r<n; ++r)
    {   
        if(++bk[v[r]] == 1) ++cnt;  // 相異顏色數量
        while(bk[v[r]] > 1)
        {   // 當右界右移後遇到區間重複元素 則持續右移左界直到不重複
            if(--bk[v[l++]] == 0) --cnt;
        }   // 算 長度為 m 且有 m 個相異顏色的彩帶 數量
        if(r-l+1 == m && cnt == m) ++ans;   
    }
    cout << ans << '\n';
}