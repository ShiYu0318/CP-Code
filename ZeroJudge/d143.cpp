#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(void)
{
    int t; cin >> t;
    int a,b;
    while(t--)
    {
        cin >> a >> b;
        if(a > b) cout << ">\n";
        else if(a == b) cout << "=\n";
        else cout << "<\n";
    }
}