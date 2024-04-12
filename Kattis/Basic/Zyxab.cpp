#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
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
    ShiYu
    int n; cin >> n;
    string s,ans = "Neibb";
    int maxl = 21;
    while(n--)
    {
        cin >> s;
        int sz = s.size();
        set<char> st;
        bool rep = false;
        RPT(i,sz)
        {
            if(st.count(s[i]))
            {
                rep = true;
                break;
            }
            else st.insert(s[i]);
        }
        if(rep || sz < 5) continue;
        else if(sz < maxl)
        {
            maxl = sz;
            ans = s;
        }
        else if(sz == maxl) ans = max(ans,s);
    }   
    cout << ans << "\n";
}
