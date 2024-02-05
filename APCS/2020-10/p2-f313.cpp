// 模擬
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define DFOR(a,b) FOR(i,a) FOR(j,b)
#define Dinput(x,a,b) DFOR(a,b) cin >> x[i][j]

signed main(void)
{
    int r,c,k,m; cin >> r >> c >> k >> m;
    int n[r][c],d[r][c],t,p,l; // n 每個城市目前人數, d 每個城市每天的變化人數
    Dinput(n,r,c); // 讀入二維陣列
    FOR(q,m)
    {   // 重複 m 天
        DFOR(r,c)
        {   // 遍歷二維陣列
            if(n[i][j] == -1) d[i][j] = 0;
            else
            {   // 上下左右判斷有 t 個相鄰城市 且這天會有 p 個人搬過來
                t = 0; p = 0;
                if(i != 0 && n[i-1][j] != -1) 
                {
                    t++;
                    p += n[i-1][j] / k;
                }
                if(i != r-1 && n[i+1][j] != -1)
                {
                    t++;
                    p += n[i+1][j] / k;
                }
                if(j != 0 && n[i][j-1] != -1)
                {
                    t++;
                    p += n[i][j-1] / k;
                }
                if(j != c-1 && n[i][j+1] != -1)
                {
                    t++;
                    p += n[i][j+1] / k;
                }
                l = n[i][j] / k * t; // 搬出去的人就是 現在這個城市的人/k 乘 相鄰城市數
                d[i][j] = p - l; // 更新這天這個城市的變化人為 搬進來的 - 搬出去的
            }   
        }
        DFOR(r,c) n[i][j] += d[i][j]; // 更新每個城市的人數
    }
    int maxn = INT_MIN, minn = INT_MAX;
    DFOR(r,c)
    {   // 找答案
        if(n[i][j] == -1) continue;
        else
        {
            maxn = max(maxn,n[i][j]);
            minn = min(minn,n[i][j]);
        }
    }
    cout << "\n" << minn << "\n" << maxn << "\n";
}