// 建表
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)

string tb[55],ans[50];
const int mx[] = {0,1,1,1,0,-1,-1,-1},
          my[] = {1,1,0,-1,-1,-1,0,1};

signed main()
{
    int h,w; cin >> h >> w;

    // 包邊界 防止讀取出去
    string as,ts,ms;
    FORn(i,w+2) as += ".";
    tb[0] = as;
    FOR(i,1,h+1) 
    {
        cin >> ts;
        ms = "." + ts + ".";
        tb[i] = ms;
    }
    tb[h+1] = as;
    // FORn(i,h+2) cout << tb[i] << "\n";

    // 跑八方檢查
    FOR(i,1,h+1)
    {
        string cs;
        FOR(j,1,w+1)
        {
            if(tb[i][j] == '#') cs += '#';
            else
            {
                int tn = 0;
                FORn(k,8)
                {
                    if(tb[i+mx[k]][j+my[k]] == '#') tn++;
                }
                cs += to_string(tn);
            }
        }
        ans[i-1] = cs;
    }
    cout << "\n\n\n";
    FORn(i,h) cout << ans[i] << "\n";
}
