#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0)
#define FOR(i,n) for(int i=0; i<n; ++i)

signed main(void)
{
    ShiYu
    int n; cin >> n;
    vector<pair<pair<int,int>,bool> > v;
    int a,b;
    while(n--)
    {
        cin >> a >> b;
        v.push_back(make_pair(make_pair(a,b),true));
    }
    int q; cin >> q;
    int t;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            int x, y; cin >> x >> y;
            vector<pair<pair<int,int>,bool> > vt;
            pair<pair<int,int>,bool> p;
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
            int maxn = -1,now=-1,sum = 0;
            while(x--)
            {
                for(int i=l-1; i<r; ++i)
                {
                    if(v[i].second == true)
                    {
                        if(v[i].first.first + v[i].first.second > maxn)
                        {
                            maxn = v[i].first.first + v[i].first.second;
                            now = i;
                        }
                    }
                    else if(v[i].second == false)
                    {
                        if(v[i].first.first > maxn)
                        {
                            maxn = v[i].first.first;
                            now = i;
                        }
                    }
                }
                sum += maxn;
                v[now].second = false;
            }
            cout << sum << "\n";
        }
    }
}