#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t; cin >> t;
    int r,c,test=1;
    while(t--)
    {
    	cout << "Test " << test << "\n"; test++;
        cin >> r >> c;
        char tb[r][c];
        for(int i=0;i<r;++i) for(int j=0;j<c;++j) cin >> tb[i][j];
        for(int i=r-1;i>=0;--i)
        {
            for(int j=c-1;j>=0;--j) cout << tb[i][j];
            cout << "\n";
        }
    }
}