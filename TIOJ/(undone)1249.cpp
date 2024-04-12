#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define all(x) x.begin(),x.end()
#define int long long
using namespace std;

// WA

signed main()
{
    ShiYu;
    int n; 
    while(cin >> n && n)
    {
        string s,c;
        map<string,vector<string>> m;
        while(n--)
        {
            cin >> s;
            c = s;
            sort(all(s));
            m[s].emplace_back(c);
        }
        bool no_answer = 1;
        for(auto &i : m)
        {
            vector<string> v = i.second;
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