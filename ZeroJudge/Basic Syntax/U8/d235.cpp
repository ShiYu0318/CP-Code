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

// 大數字串

signed main()
{
    ShiYu;
    string s; 
    while(cin >> s)
    {
        if(s == "0") break;
        int suma = 0, sumb = 0;
        RPT(i,s.size())
        {
            if(i % 2) suma += s[i] - '0';
            else sumb += s[i] - '0';
        }
        // cout << suma << ' ' << sumb << '\n';
        int d = abs(suma - sumb);
        cout << s << " is " << ((d % 11 == 0 || d == 0) ? "" : "not ") << "a multiple of 11.\n";
    }
}
