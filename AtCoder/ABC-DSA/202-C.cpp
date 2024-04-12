#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 毒瘤資結

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> a(n); input(a);
    map<int,vector<int>> mv;  // 用 map 存第二列每個元素對應的位置 有可能有多個 用 vector

    int t;
    RPT(i,n)
    {
        cin >> t;
        mv[t].emplace_back(i+1);
    }

    vector<int> b(n+1,0); // b 是存第二列每個數字的位置在第三列有幾個
    RPT(i,n)
    {
        cin >> t;
        ++b[t];
    }

    int ans = 0;
    vector<int> c(n+1,-1); // c 是存第一列有算過的數字的答案 預設 -1 有算過答案了就存起來 下次使用 避免重複計算
    RPT(i,n)
    {
        // 算過了 直接用
        if(c[ a[i] ] != -1)
        {
            ans += c[ a[i] ] + 1;
            continue;
        }
        // 還沒算過 可以遍歷 map 中的 vector 看第一列的這個數字在第二列相同數字的位置 再看這個位置在第三列有幾個
        RPT(j,mv[a[i]].size())
        {
            ans += b[ mv[a[i]][j] ];
            c[ a[i] ] += b[ mv[a[i]][j] ];
        }
    }
    cout << ans << '\n';
}
