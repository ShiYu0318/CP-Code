#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define endl '\n'
#define RPT(i,n) for(int i=0; i<n; ++i)

string k,s,ans; int l; set<string> st;

void gen(string t)
{
    if(t.size() == l)
    {
        if(!st.count(t))
        {
            ans = t;
            return;
        }
    }
    else
    {
        for(char c:k)
        {
            if(ans.size()) return;
            gen(t + c);
        }
    }
}

signed main()
{
    ShiYu;
    cin >> k >> l >> s;
    RPT(i,s.size()-l+1) st.insert(s.substr(i,l));
    gen(ans); cout << ans << endl;
}