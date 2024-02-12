#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t; cin >> t;
    int a,b,c;
    while(t--)
    {
        cin >> a >> b >> c;
        if(a+b >= 10 || b+c >= 10 || a+c >= 10) cout << "YES\n";
        else cout << "NO\n";
    }
}