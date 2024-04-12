#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define coutS(x) cout << x << ' ';
#define ll long long
using namespace std;

signed main()
{
    ShiYu
    multiset<int> p;
    ll n;
    while(cin >> n)
    {
        if(n == 0) break;
        if(n > 0) p.insert(n);
        else if(n == -1)
        {
            if(!p.empty())
            {
                auto it = p.begin();
                coutS(*it)
                p.erase(it);
            }
        }
        else if(n == -2)
        {
            if(!p.empty())
            {
                auto it = --p.end();
                coutS(*it)
                p.erase(it);
            }
        }
    }
    return 0;
}