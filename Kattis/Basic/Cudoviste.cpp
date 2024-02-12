#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
/*
思路：窮舉每個格子 當作 2x2 正方形的左上角 
檢查 2x2 正方形 如果任意一格有壓到建築 這格就不要算
順便紀錄壓到幾台車
四格跑完再存進答案表裡
注意：迴圈要限制邊界範圍 避免讀超過地圖
*/
signed main()
{
    int r,c; cin >> r >> c;
    char m[r][c]; // 創建地圖
    FOR(i,0,r) FOR(j,0,c) cin >> m[i][j]; // 讀入地圖
    // x,y 陣列裡存的分別為周圍四格的相對座標：左上(0,0),左下(1,0),右上(0,1),右下(1,1)
    int x[4] = {0,1,0,1}, y[4] = {0,0,1,1}, ans[5] = {0};
    FOR(i,0,r-1) // r-1 為了不要超出邊界
    {
        FOR(j,0,c-1)
        {
            int tmp = 0; // 紀錄壓到幾台車
            bool cancel = false; // 紀錄有沒有壓到建築物
            FOR(p,0,4) // 用一個迴圈搭配x,y陣列可以檢查周圍四格
            {
                // (i,j)為左上角那格 只要加上x,y陣列中存的相對座標就可以讀到附近的2x2正方形
                char l = m[i+x[p]][j+y[p]];
                if(l == '#') // 四周只要有一格有壓到建築 這格就不要算 直接換下一格
                {
                    cancel = true;
                    break;
                }
                else if(l == 'X') tmp++; // 有壓到車就+1
            }
            if(cancel) continue;
            else ans[tmp]++; // 用 ans 把這格壓到幾台車存下來
        }
        cout << "\n";
    }
    FOR(i,0,5) cout << ans[i] << "\n";
}