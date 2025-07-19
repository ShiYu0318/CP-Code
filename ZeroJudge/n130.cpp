#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define RPT(i,n) for(int i=0;i<n;++i)
#define F first
#define S second

// 110 新北市資訊學科能力複賽 p2 AC

const int N = 55;
char tb[N][N];

signed main()
{
    int r,c; cin >> r >> c;
    string s; getline(cin,s); getline(cin,s);
    vector< pii > v;
    RPT(i,r) RPT(j,c)
    {
        cin >> tb[i][j];
        if(tb[i][j] == '.') v.emplace_back(make_pair(i,j));
    }
    // for(auto i:v) cout << i.F << ' ' << i.S << '\n'; 
    for(int i=0,j=(v.size()-s.size())/2;i<s.size();++i,++j)
    {
        pii t = v[j];
        tb[t.first][t.second] = s[i];
    }
    RPT(i,r) 
    {
        RPT(j,c) cout << tb[i][j];
        cout << "\n";
    }
}