#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n) 
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

const int mv[6][2] = {{-1,0},{0,1},{1,1},{1,0},{0,-1},{-1,-1}};

int n,m;

bool in_range(int x, int y)
{
    return (0 <= x && x < m && 0 <= y && y < n);
}

signed main()
{
    ShiYu;
    int k; cin >> m >> n >> k;
    vector<string> tb(m);
    for(auto &i : tb) cin >> i;
    int d,x=m-1,y=0,nx,ny; 
    string ans;
    set<char> st;
    while(k--)
    {
        cin >> d;
        nx = x + mv[d][0];
        ny = y + mv[d][1];
        if(in_range(nx,ny))
        {
            x = nx;
            y = ny;
        }
        char c = tb[x][y];
        ans += c;
        st.insert(c);
    }
    cout << ans << "\n" << st.size() << "\n"; 
}