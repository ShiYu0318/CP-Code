#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 

int const mx[8] = {2,1,-1,-2,-2,-1,-1,-2},
        my[8] = {1,2,2,1,-1,-2,-2,-1};



signed main()
{
    ShiYu
    vector<string> tb(8); input(tb);
    int sz = tb[0].size();
    RPT(i,8)
    {
        vector<string> ttb = tb;
        PRT(j,sz)
        {
            if(tb[i][j] == '*')
            {
                RPT(k,8)
                {
                    tb[i+mx[k],j+my[k]] = '*';
                }
            }
        }
    }
}
