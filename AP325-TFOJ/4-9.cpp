// 20260107
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

// P-4-9. 基地台 (APCS201703)
// Greedy + 單調性 + 對答案二分搜（外掛二分搜、Parametric Search）
// 給數線上 N 點與 K 個基地台，最小化直徑 R 覆蓋所有點
// 因答案具有單調性 直徑越長覆蓋的點不會變少
// 所以可以對 R 二分搜 檢查是否能用 K 基地台覆蓋所有點
// 將未被覆蓋點  Greedy 當左端 向右覆蓋 R
// 搜到最長的不足夠長度 + 1 = 最短足夠長度（lower_bound）

int n,k; vi v;

bool enough(int R)
{
    int t=k, now=-1;
    RPT(i,n)
    {
        if(v[i] <= now) continue;
        if(t-- == 0) return false;
        now = v[i] + R;
    }
    return true;
}

signed main()
{
    ShiYu;
    cin >> n >> k;
    v.resize(n); input(v);
    sort(all(v));
    int R = 0, L = v[n-1] - v[0];
    for(int jump = L/2; jump > 0; jump >>= 1)
    {
        while(R + jump < L && !enough(R + jump)) R += jump;
    }
    cout << R+1 << '\n';
}