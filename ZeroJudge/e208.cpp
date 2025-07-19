#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define isupper(x) ('A' >= (x) && (x) <= 'Z')

// 字串 函數使用

signed main()
{
    ShiYu;
    int n; cin >> n;
    RPT(k,n)
    {
        string s,ans; cin >> s;
        RPT(i,s.size())
        {
            if(isupper(s[i]))
            {
                int l = 1;
                while(!isupper(s[i+l])) ++l;
                ans += string(stoi(s.substr(i+1,l)),s[i]);
            }
        }
        cout << "Case " << k+1 << ": " << ans << '\n';
    }
}
