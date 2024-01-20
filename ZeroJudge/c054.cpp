// 建表
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)

const string ks = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int find_idx(char c)
{
    FORn(i,ks.size())
    {
        if(c == ks[i]) return i;
    }
    return -1;
}

signed main()
{
    string s;
    while(getline(cin,s))
    {
        string ans;
        FORn(i,s.size())
        {
            if(s[i] == ' ') ans += ' ';
            else ans += ks[find_idx(s[i])-1];
        }
        cout << ans << "\n";
    }
}