#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0)
#define FOR(i,n) for(int i=0; i<n; ++i)
#define vpii vector<pair<int,int> >

signed main(void)
{
    ShiYu;
    int n; cin >> n;
    vpii v;
    int a,b;
    while(n--)
    {
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    int q; cin >> q;
    int t;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            int x, y; cin >> x >> y;
            vpii vt;
            pair<int,int> p;
            FOR(i,v.size())
            {
                if(i + 1 == x)
                {
                    p = v[i];
                    continue;
                }
                else if(i == y)
                {
                    vt.push_back(p);
                }
                vt.push_back(v[i]);
            }
            v = vt;
        }
        else if(t == 2)
        {
            int l, r, x; cin >> l >> r >> x;
            int maxn = -1;
            for(int i=l-1; i<r; ++i)
            {
                int sum = v[i].first * x + v[i].second;
                if(sum > maxn) maxn = sum;
            }
            cout << maxn << "\n";
        }
    }
}