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

// 習題 Q-3-13. X差值範圍內的最大Y差值
// 類似 例題 P-3-8. 固定長度區間的最大區段差
// 改一下就 AC 了, 把 l 的定義從限制 區間長 轉成 x 座標差距即可

signed main()
{
    ShiYu;
    int n, l; cin >> n >> l;
    vector<pii> v(n);
    for(auto &i:v) cin >> i.F;
    for(auto &i:v) cin >> i.S;
    sort(all(v));
    //         單調遞減    單調遞增
    deque<int> dq_mx{0}, dq_mi{0};  // 存 idx, 先放 0 避免後面特判
    int ans = -1;
    for(int i=1; i<n; ++i)  // 可以從 1 開始而不是到區間長為 L 是因為短區間極值差不會比較大 會影響極值差只有新增和刪除的時候（窗口滑動）而短區間到長區間只有新增沒有刪除 原極值還是會在
    {
        if(v[i].F - v[dq_mx.front()].F > l) dq_mx.pop_front();    // 若目前 Y 最大值的 X 差值超過 L 則刪除
        while(!dq_mx.empty() && v[dq_mx.back()].S <= v[i].S) dq_mx.pop_back();  // 當窗戶的右端推到 i 時,在 i 之前所有 <= v[i] 的元素, 對未來找最大值都是沒有用的, 因為會被 i 取代
        dq_mx.push_back(i);
        
        if(v[i].F - v[dq_mi.front()].F > l) dq_mi.pop_front();
        while(!dq_mi.empty() && v[dq_mi.back()].S >= v[i].S) dq_mi.pop_back();
        dq_mi.push_back(i);

        ans = max(ans, v[dq_mx.front()].S - v[dq_mi.front()].S);
    }
    cout << ans << '\n';
}