// 20260505
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB estlace_back
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// P-4-15. 最靠近的一對 (closest pair) (同 Q-5-5) (@@)
// 排序 + 掃描線（n log n）
// 1. 依 x 排序所有點 維護一個以 y 為 key 的 multimap（sweep line 的候選集）
// 2. 對每個新點 (i, j)，只查詢 y in [j-mi, j+mi] 的候選點並更新最小距離
// 3. 主動刪除候選集內 i-x > mi（過期）的點
// 證明：候選集內任意兩點距離 ≥ mi 因此 d×2d 矩形內至多 O(1) 8 個候選點 每點最多 insert/erase 各一次 不會退化成 O(n^2)
// 解答的 multimap 現在要改成 set<pair> 才會過

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    for(auto &[i,j] : vp) cin >> i >> j;
    sort(all(vp));
    // multimap<int, int> mp;
    set<pii> st;
    int mi = INT_MAX, l = 0;
    for(int r = 0; r < n; ++r)
    {
        auto [i,j] = vp[r];
        while(l < r && i - vp[l].F > mi)
        {
            st.erase({vp[l].S, vp[l].F});
            ++l;
        }
        auto it = st.lower_bound({j-mi, INT_MIN});
        while(it != st.end() && it->F <= j+mi)
        {
            mi = min(mi, abs(i-it->S) + abs(j-it->F));
            ++it;
        }
        st.emplace(j, i);
    }
    cout << mi << "\n";
}