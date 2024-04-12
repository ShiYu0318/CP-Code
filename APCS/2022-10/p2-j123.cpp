#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)

// 建表 AC

vector<vector<int>> tb = 
{
    {1,1,1,1},
    {3},
    {2,2},
    {1,3},
    {1,2,2},
};

const int sz[5] = {4,3,4,4,5};
int LL[30] = {0};

signed main()
{
    int R,C,n; cin >> R >> C >> n;
    char t; int y, blank = R * C, del = 0;
    while(n--)
    {
        cin >> t >> y;
        int x = t - 'A', back = 0, l = tb[x].size();
        FOR(i,0,l) back = max(back,LL[y+i]+tb[x][i]);
        if(back > C) ++del;
        else
        {
            FOR(i,y,y+l) LL[i] = back;
            blank -= sz[x];
        }
    }
    cout << blank << ' ' << del << '\n';
}