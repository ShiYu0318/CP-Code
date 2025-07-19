#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

signed main()
{
    ShiYu;
    int n;cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        int ans = 0;
        stack<char> st;
        RPT(i,s.size())
        {
            if(!st.empty() && s[i] == ')') 
            {
                st.pop();
                ++ans;
            }
            else if(s[i] == '(') st.emplace(s[i]);
            else
            {
                ans = 0;
                break;
            }
        }
        if(!st.empty()) ans = 0;
        cout << ans << '\n';
    }
    
}
