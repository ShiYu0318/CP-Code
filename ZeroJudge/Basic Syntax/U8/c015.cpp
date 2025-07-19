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

// 迴文 do-while

bool isReverse(int n)
{
    string s = to_string(n);
    int sz = s.size();
    RPT(i,sz/2)
    {
        if(s[i] != s[sz-1-i]) return false;
    }
    return true;
}

signed main()
{
    ShiYu;
    int t; cin >> t;
    int n; string s;
    while(t--)
    {
        int ts = 0;
        cin >> n;
        do {
            s = to_string(n);
            reverse(all(s));
            n += stoi(s);
            ++ts;
        } while(!isReverse(n));
        cout << ts << ' ' << n << '\n';
    }
}
