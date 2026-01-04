// 20260103
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
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 習題 Q-3-5. 帶著板凳排雞排的高人 (APCS201902)
// 延伸版 例題 P-3-4. 最接近的高人 (APCS201902, subtask)
// 單調佇列 二分搜
// 不能以站上板凳後的身高去 pop 單調佇列 因為後面的每個人都是站在板凳上往前看其他人的原身高
// 維護原身高遞減序列 mono 對每個人站上板凳後的身高找往前找第一個更高的人
// 二分搜 在遞減序列中 (從後到前找第一個大於的位置) === (由前到後找第一個小於等於的位置-1)
// lower_bound : >=
// upper_bound : >
// lower_bound + greater : <=
// upper_bound + greater : <
// 因為要二分搜所以身高和位置分開存

const int N = 1e8;

signed main()
{
    ShiYu;
    int n; cin >> n;
    vi h(n), p(n), mono, idx; input(h); input(p);
    mono.EB(N); idx.EB(-1); // 守衛
    int ans = 0;
    RPT(i,n)
    {
        int j = lower_bound(mono.begin(), mono.end(), h[i] + p[i], greater<int>())-1 - mono.begin();
        ans += i - idx[j] - 1; // 因設守衛 idx = 1 所以合併了前面沒人比他高的情況 i - (-1) - 1 = i (0-based)
        while(mono.back() <= h[i])
        {
            mono.pop_back();
            idx.pop_back();
        }
        mono.EB(h[i]);
        idx.EB(i);
    }
    cout << ans << endl;
}