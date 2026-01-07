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

// Q-4-10. 恢復能量的白雲熊膽丸
// 類似 P-4-9. 基地台 (APCS201703)
// Greedy + 單調性 + 對答案二分搜

int n,m; vi v;
bool check(int f)
{
    int t = m, ff = f;
    RPT(i,n)
    {
        // cout << v[i] << ' ' << t << ' ' << ff << '\n';
        if(ff < v[i])
        {
            if(!t) return false;
            --t;
            ff = f;
        }
        ff -= v[i];
    }
    return true;
}

signed main()
{
    ShiYu;
    cin >> n >> m;
    v.resize(n);
    int mx = 0, sum = 0;
    for(auto &i:v)
    {
        cin >> i;
        mx = max(mx, i);
        sum += i;
    }
    mx -= 1;    // 當答案是關卡最大值時，要先讓起始值 -1 再加上 jump = 1 才能找到
    for(int jump = sum; jump > 0; jump >>= 1)
    {
        while(mx + jump <= sum && !check(mx + jump)) mx += jump;
    }
    cout << mx+1 << '\n';
}