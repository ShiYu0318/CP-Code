#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std;

signed main()
{
    int r,c; cin >> r >> c;
    char t[r][c];
    vector<string> v;
    FOR(i,0,r) 
    {
        string s;
        FOR(j,0,c)
        {
            cin >> t[i][j];
            char tmp = t[i][j];
            if('a' <= tmp && tmp <= 'z') s += tmp;
            else
            {
                if(s.size() > 1) v.push_back(s);
                s.clear();
            }
        }
        if(s.size() > 1) v.push_back(s);
    }
    FOR(i,0,c)
    {
        string s;
        FOR(j,0,r)
        {
            char tmp = t[j][i];
            if('a' <= tmp && tmp <= 'z') s += tmp;
            else
            {
                if(s.size() > 1) v.push_back(s);
                s.clear();
            }
        }
        if(s.size() > 1) v.push_back(s);
    }
    sort(v.begin(),v.end());
    cout << v[0] << '\n';
}