// 20260503
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

// P-4-15. 最靠近的一對 (closest pair) (同 Q-5-5) (@@)
// 排序 + 掃描線（n log n）
// 1. 依 x 排序所有點
// 2. 維護一個以 y 為 key 的 multimap（sweep line 的候選集）
// 3. 對每個新點 (i, j)，只查詢 y ∈ [j-mi, j+mi] 的候選點並更新最小距離
// 4. 候選集內 x 過期（< i-mi）的點順帶刪除
// 證明：候選集內任意兩點距離 ≥ mi 因此 d×2d 矩形內至多 O(1) 8 個候選點 不會退化成 O(n²)
// 每點至多 insert/erase 各一次 時間複雜度 O(n log n)

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<pair<int, int>> vp(n);
    for(auto &[i,j] : vp) cin >> i >> j;
    sort(all(vp));
    multimap<int, int> mp;
    int mi = INT_MAX;
    for(auto [i,j] : vp)
    {
        auto it = mp.lower_bound(j-mi);
        while(it != mp.end() && it->F <= j+mi)
        {
            if(it->S < i-mi) it = mp.erase(it);
            else
            {
                mi = min(mi, abs(i-it->S) + abs(j-it->F));
                ++it;
            }
        }
        mp.emplace(j, i);
    }
    cout << mi << "\n";
}