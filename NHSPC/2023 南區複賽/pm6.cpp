#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0; i<n; ++i)

signed main()
{
    int a, b; cin >> a >> b;
    int n = a * b, t = n;
    string s = "";
    while(t != 0)
    {
        if(t % 2) s = "1" + s;
        else s = "0" + s;
        t /= 2;
    }
    cout << s << "\n" << n << "\n";
}