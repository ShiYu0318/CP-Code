#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

signed main()
{
    ShiYu;
    int a,b;
    while(cin >> a >> b && a && b)
    {
        int x = sqrt(a), y = sqrt(b);
        if(x * x != a) ++x;
        cout << y - x + 1 << "\n";
    }
}