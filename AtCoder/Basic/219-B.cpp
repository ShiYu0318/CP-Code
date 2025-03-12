#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    string s[3],t,ans;
    cin >> s[0] >> s[1] >> s[2] >> t;
    FOR(i,t.size())
    {
        ans += s[(int)(t[i] - '1')];
    }
    cout << ans << '\n';
}