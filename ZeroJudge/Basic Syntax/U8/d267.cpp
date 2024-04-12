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

signed main()
{
    ShiYu;
    int t; cin >> t;
    cin.ignore();
    while(t--)
    {
        int tb[26] = {0};
        string s; getline(cin,s);
        RPT(i,s.size())
        {
            if('a' <= s[i] && s[i] <= 'z') ++tb[s[i] - 'a'];
            if('A' <= s[i] && s[i] <= 'Z') ++tb[s[i] - 'A'];
        }
        int maxn = *max_element(tb, tb+26);
        string ans;
        RPT(i,26)
        {
            if(tb[i] == maxn)
            {
                ans += (char)('a' + i);
            }
        }
        cout << ans << '\n';
    }
}
