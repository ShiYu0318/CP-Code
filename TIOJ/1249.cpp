#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define all(x) x.begin(),x.end()
#define str string
#define ll long long
using namespace std;

signed main()
{
    ShiYu
    
    ll n; 
    while(cin >> n)
    {
        if(n == 0) break;
        str s,c;
        map<str,vector<str>> m;
        while(n--)
        {
            cin >> s;
            c = s;
            sort(all(s));
            m[s].push_back(c);
        }
        bool no_answer = 1;
        for(auto &i : m)
        {
            vector<str> v = i.second;
            if(v.size() == 1) continue;
            no_answer = 0;
            sort(all(v));
            FOR(j,0,v.size())
            {
                cout << v[j];
                if(j != v.size()-1) cout << ",";
            }
            cout << "\n";
        }
        if(no_answer) cout << "No Answer\n";
    }

}