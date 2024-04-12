#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int a,b,c;
    while(cin >> a >> b >> c)
    {
        cout << a << ' ' << b << ' ' << c << (a * c >= b ? ". I will make it!" : ". I will be late!") << "\n";
    }
    return 0;
}