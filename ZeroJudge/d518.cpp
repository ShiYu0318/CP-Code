#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

signed main()
{
    ShiYu;
    int n;
    while(cin >> n)
    {
        map<string,int> mp;
        int now = 1;
        string s;
        for(int i=1;i<=n;++i)
        {
            cin >> s;
            if(mp.count(s)) cout << "Old! " << mp[s] << '\n';
            else
            {
                cout << "New! " << now << '\n';
                mp[s] = now;
                now++;
            }
        }
    }
}