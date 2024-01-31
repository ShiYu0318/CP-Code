#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second 

signed main()
{
    ShiYu;
    string ss[] = {"", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
    map<char,int> mp;
    FOR(i,1,7) RPT(j,ss[i].size()) mp[ss[i][j]] = i;

    string s;
    while (cin >> s){
        int p = 0;
        RPT(i,s.size())
        {
            if(mp.count(s[i]))
            {
                if (mp[s[i]] != p) 
                {
                    cout << mp[s[i]];
                    p = mp[s[i]];
                }
            } else p = 0;
        }
        cout << "\n";
    }
}