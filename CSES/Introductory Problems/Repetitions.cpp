#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)

// 最長連續字串

signed main()
{
    ShiYu;
    string s; cin >> s;
    char c = s[0];
    int temp=1,maxn=1;
    FOR(i,1,s.size())
    {
        if(s[i] == c) 
        {
            temp++;
            maxn = max(maxn,temp);
        }
        else
        {
            c = s[i];
            maxn = max(maxn,temp);
            temp = 1;
        }
    }
    cout << maxn << '\n';
}