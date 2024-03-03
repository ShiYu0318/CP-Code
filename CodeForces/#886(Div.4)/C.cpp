#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0),cin.tie(0);
using namespace std;

signed main()
{
    IO;
    int t; cin >> t;
    while(t--)
    {
        char tb[8][8];
        string ans;
        for(int i=0;i<8;++i)
        {
            for(int j=0;j<8;++j)
            {
                cin >> tb[i][j];
                if(tb[i][j] != '.') ans += tb[i][j];
            }
        }
        cout << ans << "\n";
    }
}