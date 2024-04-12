#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long

// stringstream

signed main()
{
    ShiYu;
    int t; cin >> t;
    cin.ignore();
    while(t--)
    {
        string s; getline(cin,s);
        stringstream ss(s);
        vector<string> v;
        string ts;
        while(ss >> ts) v.emplace_back(ts);
        // output(v);
        int sz = v.size();
        bool ans = true;
        if(sz < 2 || v[sz-1][1] == v[0][0]) ans = false;
        else
        {
            RPT(i,sz-1)
            {
                if(v[i][1] == v[i+1][0])
                {
                    ans = false;
                    break;
                }
            }
        }
        cout << (ans ? "LOOP" : "NO LOOP") << '\n';
    }
}
