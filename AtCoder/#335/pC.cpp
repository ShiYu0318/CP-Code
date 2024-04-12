#include <bits/stdc++.h>
using namespace std;
#define RPT(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define dbg(x) cout << #x << "=" << x << ' ';
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define int long long

const int mx[4] = {1,-1,0,0},
          my[4] = {0,0,1,-1};

signed main(void)
{
    vector<pair<int,int>> v;
    int n,q; cin >> n >> q;
    for(int i=n;i>0;--i) v.emplace_back(i,0);
    int t,x,mt,nxy; char d;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> d;
            if(d == 'R') mt = 0;
            else if(d == 'L') mt = 1;
            else if(d == 'U') mt = 2;
            else mt = 3;
            v.emplace_back(v.back().first+mx[mt],v.back().second+my[mt]);
        }
        else
        {
            cin >> x;
            cout << v[(v.size()-x)].first << ' ' << v[(v.size()-x)].second << "\n";
        }

    }
}
