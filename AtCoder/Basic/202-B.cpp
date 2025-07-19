#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFORn(i,n) for(int i=n-1;i>=0;--i)

signed main()
{
    string s,ans; cin >> s;
    rFORn(i,s.size())
    {
        if(s[i] == '6') ans += '9';
        else if(s[i] == '9') ans += '6';
        else ans += s[i];
    }
    cout << ans << '\n';
}