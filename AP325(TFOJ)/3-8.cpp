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
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// 例題 P-3-8. 固定長度區間的最大區段差
// 滑動窗口 維護區間極值單調雙端佇列
// 區間極值有可能會變動 所以要維護其他有可能在之後成為區間極值的位置

signed main()
{
    ShiYu;
    int n,l; cin >> n >> l;
    vi v(n); input(v);
    //        單調遞減 單調遞增
    deque<int> dq_mx{0}, dq_mi{0};
    int ans = -1;
    for(int i=1; i<n; ++i)
    {
        if(dq_mx.front() <= i-l) dq_mx.pop_front();    // 若目前最大值從左端離開區間則更新
        while(!dq_mx.empty() && v[dq_mx.back()] <= v[i]) dq_mx.pop_back();  // 當窗戶的右端推到 i 時,在 i 之前所有 <= v[i] 的元素, 對未來找最大值都是沒有用的, 因為會被 i 取代
        dq_mx.push_back(i);
        
        if(dq_mi.front() <= i-l) dq_mi.pop_front();
        while(!dq_mi.empty() && v[dq_mi.back()] >= v[i]) dq_mi.pop_back();
        dq_mi.push_back(i);

        ans = max(ans, v[dq_mx.front()] - v[dq_mi.front()]);
    }
    cout << ans << '\n';
}