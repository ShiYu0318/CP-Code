#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second

// 習題 Q-1-11. 刪除矩形邊界 — 遞迴 (APCS201910, subtask) 
// WA 前綴和 太難 Debug

int tb[13][13], ps[14][14], rps[14][14];

// remove frame
int rmf(int ax, int ay, int bx, int by)
{   // (0,0,5,3)
    if(ax == bx || ay == by) return 0;

    int u = ps[ay][bx] - ps[ay][ax],
        d = ps[by-1][bx] - ps[by-1][ax],
        l = rps[by][ax] - rps[ay][ax],
        r = rps[by][bx-1] - rps[ay][bx-1];
    // int u = ps[0][5] - ps[0][0],
    //     d = ps[3-1][5] - ps[3-1][0],
    //     l = rps[3][0] - rps[0][0],
    //     r = rps[3][5-1] - rps[0][5-1];

    // cout << "u: " << u << " d: " << d << " l: " << l << " r: " << r << endl;

    int m = by - ay + 1,
        n = bx - ax + 1;
    u = min(u, m - u);
    d = min(d, m - d);
    l = min(l, n - l);
    r = min(r, n - r);

    int w = u + rmf(ax+1, ay, bx, by),
        x = d + rmf(ax, ay, bx-1, by),
        y = l + rmf(ax, ay+1, bx, by),
        z = r + rmf(ax, ay, bx, by-1);

    // cout << "ax: " << ax << " ay: " << ay << " bx: " << bx << " by: " << by << endl;
    // cout << "w: " << w << " x: " << x << " y: " << y << " z: " << z << endl;


    return min({w,x,y,z});
}


signed main()
{
    ShiYu;
    int m, n; cin >> m >> n;
    // 輸入同時做前綴和預處理
    RPT(i,m)
    {   
        ps[i][0] = 0;
        RPT(j,n)
        {
            cin >> tb[i][j];
            ps[i][j+1] = ps[i][j] + tb[i][j];
        }
    }
    // 直的前綴和
    RPT(j,n)
    {
        rps[0][j] = 0;
        RPT(i,m) rps[i+1][j] = rps[i][j] + tb[i][j];
    }
    RPT(i,m) RPT(j,n+1) cout << ps[i][j] << " \n"[j == n];
    cout << "\n\n";
    RPT(i,m+1) RPT(j,n) cout << rps[i][j] << " \n"[j == n-1];
    cout << "\n\n";
    cout << rmf(0,0,m,n) << "\n";
}
