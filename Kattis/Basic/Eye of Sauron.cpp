#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

signed main()
{
    ShiYu;
    string s; cin >> s;
    int sz = s.size();
    if(sz % 2) cout << "fix\n";
    else
    {
        bool ans = true;
        RPT(i,sz / 2 - 1)
        {
            if(s[i] != s[sz-1-i] || s[i] != '|' || s[sz-1-i] != '|')
            {
                ans = false;
                break;
            }
        }
        if(ans)
        {
            if(s[sz / 2 - 1] == '|' || s[sz / 2] == '|') ans = false;
        }
        cout << (ans ? "correct" : "fix") << "\n";
    }
}
