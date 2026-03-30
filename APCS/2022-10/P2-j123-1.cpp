#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << "=" << x << '\n';
#define F first
#define S second

// 有畫面的模擬 NA75%

const int LW[5][2] = {{4,1},{1,3},{2,2},{2,3},{3,2}};

int tb[30][50] = {0};
int LL[30] = {0};
int r,c,top,topR,stuck_p,sum;
int leave = 0;
vector<vector<pair<int,int>>> v = {
    {{0,0},{1,0},{2,0},{3,0}},
    {{0,0},{0,1},{0,2}},
    {{0,0},{1,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,-1},{1,-2}},
    {{0,0},{1,0},{2,0},{1,-1},{2,-1}}
};

void putinto(int t,int y,int top,int RL)
{
    int sz = v[t].size();
    for(int i=0;i<sz;++i)
    {
        tb[y+v[t][i].F][top+v[t][i].S]++;
    }
    for(int i=y;i<y+LW[t][0];++i)
    {
        LL[i] = RL;
    }
    sum -= sz;

    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j) cout << tb[i][j];
        cout << '\n';
    }
    for(int i=0;i<r;++i) cout << LL[i] << ' ';
    cout << "\n\n";
    cout << sum << ' ' << leave << '\n';
    cout << "\n\n";
}


bool check(int t,int y)
{
    top = 0;topR = y;
    int i,RL;
    if(t < 3)
    {
        for(i=y;i<y+LW[t][0];++i)
        {
            if(LL[i]+LW[t][1] > c) return false;
            if(LL[i] > top)
            {
                top = LL[i];
            }
        }
        RL = top + LW[t][1];
    }
    else if(t == 3)
    {
        if(LL[y] - LL[y+1] >= 2) top = LL[y];
        else if(LL[y] >= LL[y+1]) top = LL[y] + (2 - (LL[y] - LL[y+1]));
        else top = LL[y+1] + 2;
        // dbg(y);dbg(top);
        if(top >= c) return false;
        RL = top+1;
        // cout << top << '\n';
    }
    else
    {
        if(LL[y] > LL[y+1] && LL[y] > LL[y+2]) top = LL[y];
        else if(LL[y+1] >= LL[y] || LL[y+1] >= LL[y]) top = max(LL[y+1],LL[y+2]) + 1;
        // dbg(y);dbg(top);
        if(top >= c) return false;
        RL = top + 1;
    }
    putinto(t,y,top,RL);

    return true;

}

signed main()
{
    // int n; cin >> r >> c >> n;
    cin >> r >> c;

    sum = r * c;
    char t;int y; 
    
    // while(n--)
    while(cin >> t >> y)
    {
        // cin >> t >> y;
        if(!check(t - 'A',y)) leave++;
    }
    cout << sum << ' ' << leave << '\n';
}