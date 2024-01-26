#include<bits/stdc++.h>
using namespace std;

signed main()
{
    string s; cin >> s;
    bool ans = true;
    int sz = s.size();
    for(int i=0;i<sz;++i)
    {
        if(s[i] != s[sz-1-i])
        {
            ans = false;
            break;
        }
    } 
    cout << (ans ? "Yes" : "No") << "\n";
}