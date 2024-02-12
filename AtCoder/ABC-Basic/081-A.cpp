#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define yn(x) cout << (x ? "Yes" : "No") << "\n"

signed main()
{
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < (int)s.size(); ++i)
    {
        if(s[i] == '1') ans++;
    }
    cout << ans <<"\n";
    
}