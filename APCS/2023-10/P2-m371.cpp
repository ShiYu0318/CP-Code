#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)

signed main()
{
    ShiYu;
    int n,m; cin >> n >> m;
    int t[40][40];
    RPT(i,n) RPT(j,m) cin >> t[i][j];
    int ans = 0;
    bool find = true;
    while(find)
    {
        find = false;
        // 橫
        RPT(i,n)
        {
            RPT(j,m-1)
            {
                if(t[i][j] == -1) continue;
                FOR(k,1,m-j)
                {
                    if(t[i][j+k] == -1) continue;
                    if(t[i][j] == t[i][j+k])
                    {
                        ans += t[i][j];
                        t[i][j] = -1;
                        t[i][j+k] = -1;
                        find  = true;
                    }
                    break;
                }
            }
        }
        // 直
        RPT(i,m)
        {
            RPT(j,n-1)
            {
                if(t[j][i] == -1) continue;
                FOR(k,1,n-j)
                {
                    if(t[j+k][i] == -1) continue;
                    if(t[j][i] == t[j+k][i])
                    {
                        ans += t[j][i];
                        t[j][i] = -1;
                        t[j+k][i] = -1;
                        find  = true;
                    }
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}