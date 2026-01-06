// 20260106
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
#define nl cout << '\n';
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// 例題 Q-3-14. 線性函數 (@@) (同 P-5-6，分治版)
// 凸包 Convex Hull Trick (CHT) 單調佇列

const int INF = 1e16;
vector<pii> fs;
vi mono; // 存線在 fs 中的 idx , 兩相鄰線交點 x 呈單調遞增

double get_p(int a, int b) { return double(fs[b].S - fs[a].S) / (fs[a].F - fs[b].F); }  // 兩線求交點

bool better(int c)
{
    int b = mono[SZ(mono)-1];   // 前條線
    if(fs[c].F == fs[b].F) return true;   // 斜率相同為平行無交點 因 pair 排序先 F 後 S 所以後面的線會比前面高 可直接丟掉前面
    if(SZ(mono) < 2) return false;
    int a = mono[SZ(mono)-2];   // 前前條線
    // 前兩條線的交點比後兩條線交點大 則 b 被 c 覆蓋掉了
    return (get_p(a, b) >= get_p(b, c));
}

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    fs.resize(n);
    for(auto &i:fs) cin >> i.F >> i.S;
    vi c(m); input(c);
    sort(all(fs)); sort(all(c));    // 對線按斜率從小到大排序，對同斜率線從小到大排序截距
    
    // 建凸包
    for(int i=0; i<n; ++i)
    {
        while(!mono.empty() && better(i)) mono.pop_back();  // 過濾被覆蓋掉沒用的線
        mono.EB(i);
    }

    // 算交點
    vector<double> ps;  // 存凸包上相鄰線的交點 x 座標
    RPT(i,SZ(mono)-1) ps.EB(get_p(mono[i], mono[i+1]));
    ps.EB(INF); // 最右側交點設為 INF

    // 查詢
    int sum = 0;
    for(int i=0, j=0; i<m; ++i)
    {
        while(c[i] > ps[j]) ++j;
        sum += fs[mono[j]].F * c[i] + fs[mono[j]].S;
    }
    cout << sum << '\n';
}