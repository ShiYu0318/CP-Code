#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second

// 習題 Q-1-11. 刪除矩形邊界 — 遞迴 (APCS201910, subtask) 
// 遞迴

int tb[13][13];

// remove frame
int rmf(int ax, int ay, int bx, int by)
{
    if(ax == bx || ay == by) return 0;  // 剩一行或一列
    // 找上下左右的值
    int u = 0, d = 0, l = 0, r = 0; 
    FOR(j,ay,by+1)
    {
        u += tb[ax][j];
        d += tb[bx][j];
    }
    FOR(i,ax,bx+1)
    {
        l += tb[i][ay];
        r += tb[i][by];
    }
    int m = by - ay + 1,
        n = bx - ax + 1;
    u = min(u, m - u);
    d = min(d, m - d);
    l = min(l, n - l);
    r = min(r, n - r);
    // 刪掉邊後遞迴
    int w = u + rmf(ax+1, ay, bx, by),
        x = d + rmf(ax, ay, bx-1, by),
        y = l + rmf(ax, ay+1, bx, by),
        z = r + rmf(ax, ay, bx, by-1);
    return min({w,x,y,z});
}

signed main()
{
    ShiYu;
    int m, n; cin >> m >> n;
    RPT(i,m) RPT(j,n) cin >> tb[i][j];
    cout << rmf(0,0,m-1,n-1) << '\n';
}