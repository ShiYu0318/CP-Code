#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second 

int tb[50][50];

signed main()
{
    ShiYu;
    bool ans = true;
    int h,w; cin >> h >> w;
    RPT(i,h) RPT(j,w) cin >> tb[i+1][j+1];
    FOR(i,1,h)
    {
        FOR(k,i+1,h+1)
        {
            FOR(j,1,w)
            {
                FOR(l,j+1,w+1)
                {
                    if(tb[i][j] + tb[k][l] > tb[k][j] + tb[i][l])
                    {
                        ans = false;
                        break;
                    }
                }
                if(!ans) break;
            }
            if(!ans) break;
        }
        if(!ans) break;
    }
    Yn(ans);
}
