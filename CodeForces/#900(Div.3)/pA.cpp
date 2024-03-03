#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << "\n"

signed main(void)
{
    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;
        int a;
        bool c = false;
        while(n--)
        {
            cin >> a;
            if(a == k && !c)
            {
                c = true;
                cout << "YES\n";
            }
        }
        if(!c) cout << "NO\n";
    }
}