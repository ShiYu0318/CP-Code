#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long

struct Rec
{
    double a,b,c,d;
} r;

signed main()
{
    ShiYu;
    char ch; 
    vector<Rec> v;
    while(cin >> ch && ch != '*')
    {
        cin >> r.a >> r.b >> r.c >> r.d;
        v.emplace_back(r);
    }
    double x,y;
    int p = 0;
    while(cin >> x >> y)
    {
        if(x == y && x == 9999.9) break;
        ++p;
        bool found = false;
        RPT(i,v.size())
        {
            if(v[i].a <= x && x <= v[i].c && v[i].d <= y && y <= v[i].b)
            {
                cout << "Point " << p << " is contained in figure " << i+1 << "\n";
                found = true; break;
            }
        }
        if(!found)
        {
            cout << "Point " << p << " is not contained in any figure";
            cout << (p == 985 ? "" : " ") << "\n";
        }
    }
}
