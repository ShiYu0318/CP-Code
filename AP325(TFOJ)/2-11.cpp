#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-2-11. 最接近的區間和 (*)
// 前綴和 動態維護
// 限制版 Kadane’s

signed main()
{
    ShiYu;
    int n,k; cin >> n >> k;
    set<int> st = {0};
    int sum = 0, ans = 0, t;
    while(n--)
    {
        cin >> t; sum += t;
        auto it = st.lower_bound(sum - k);
        if(it != st.end()) ans = max(ans, sum - *it);
        st.insert(sum);
    }
    cout << ans << endl;
}